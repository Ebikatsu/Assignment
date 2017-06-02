#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <pthread.h>

#define NO_FLAGS_SET 0
#define BUFFER_LEN 256

void reply(void *);
int closeSocket(int);
int clients = 0;
pthread_mutex_t mutex;

/*
 * プログラムの開始点
 */
int main(int argc, char *argv[])
{
  struct sockaddr_in serverAddress;
  struct sockaddr_in clientAddress;
  int serverPort;
  int clientPort;
  int serverSocket;
  int clientSocket;
  unsigned int clientSize;
  int status;

  pthread_t worker;

  /**
   * 空コメントのない箇所はECHOサーバと同じ処理であるため、コメントの追記は不要
   */
  clientSize = sizeof(clientAddress);

  if (argc != 2) {
    printf("usage: %s <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  serverPort = atoi(argv[1]);

  memset(&serverAddress, 0, sizeof(serverAddress));

  serverAddress.sin_port = htons(serverPort);
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
  serverSocket = socket(AF_INET, SOCK_STREAM, 0);

  if (serverSocket == -1) {
    fprintf(stderr, "Error: socket creation is unsuccessful.\n");
    exit(EXIT_FAILURE);
  }

  bind(serverSocket, (struct sockaddr *)&serverAddress, 
      sizeof(serverAddress));

  /*** コネクションの確立時にクライアントからの接続要求を格納するキューをサーバ側で作る ***/
  listen(serverSocket, SOMAXCONN);

  /*** 接続待ち状態であることを表示 ***/
  printf("Waiting for connection ...\n");

  /*** 無限ループ ***/
  while (1) {

    clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, 
          &clientSize);

    if (clientSocket == -1) {
      fprintf(stderr, "Error: cannot accept a connection.\n");
    }

    if(pthread_mutex_lock(&mutex) != 0) {
        fprintf(stderr, "Error: cannot lock a mutex.\n");
        exit(EXIT_FAILURE);
    }
    clients++;
    printf("%d clients.\n", clients);
    if(pthread_mutex_unlock(&mutex) != 0) {
        fprintf(stderr, "Error: cannot unlock a mutex.\n");
        exit(EXIT_FAILURE);
    }

    /*** 接続してきたクライアントの情報を表示 ***/
    printf("Connected from %s.\n", inet_ntoa(clientAddress.sin_addr)); 

    /*** スレッドを作成する。 ***/
    status = pthread_create((pthread_t *)&worker, (pthread_attr_t *)NULL, 
        (void *)reply, (void *)&clientSocket);

    /*** スレッドの作成に失敗した時の処理 ***/
    if (status != 0) {
      fprintf(stderr, "Error: cannot create a thread.\n");
      closeSocket(serverSocket);
      exit(EXIT_FAILURE);
    }

    //#include<pthread.h> int pthread_detach(pthread_t thread);
    //対象のスレッドが終了した時にそのスレッドのリソースが開放されることを保証する。
    //thread 切り離すスレッド
    //返り値:成功の時0、失敗の時0でないエラーコード
    /*** スレッドを切り離す。pthread_joinとは違い生成元のスレッドは対象のスレッドの終了を待たない。対象のスレッドが終了するとそのリソースは自動的に開放される。 ***/
    pthread_detach(worker);
  }

  closeSocket(serverSocket);

  /*** 正常終了 ***/
  return(EXIT_SUCCESS);
}

/*
 * reply関数
 */
void reply(void *socket) {
  int clientSocket;
  int numrcv;
  int numsnt;
  char recvStr[BUFFER_LEN];
  char sendStr[BUFFER_LEN];

  /*** クライアントソケット ***/
  clientSocket = *((int *)socket);

  /*** 無限ループ ***/
  while (1) {

    numrcv = recv(clientSocket, recvStr, BUFFER_LEN, 0);

    /*** クライアントからのメッセージを正常に受け取れなかった時の処理 ***/
    if (numrcv == -1 || numrcv == 0) {
      closeSocket(clientSocket);

      if(pthread_mutex_lock(&mutex) != 0) {
          fprintf(stderr, "Error: cannot lock a mutex.\n");
          exit(EXIT_FAILURE);
      }
      clients--;
      printf("%d clients.\n", clients);
      if(pthread_mutex_unlock(&mutex) != 0) {
          fprintf(stderr, "Error: cannot unlock a mutex.\n");
          exit(EXIT_FAILURE);
      }

      printf("Connection terminated.\n");
      break;
    }

    printf("RECEIVE(%u)>>%s", (unsigned)strlen(recvStr), recvStr);
    numsnt = send(clientSocket, recvStr, strlen(recvStr) + 1, 0);

    /*** クライアントにメッセージを正常に送れなかった時の処理 ***/
    if (numsnt != strlen(recvStr) + 1) {
      if (numsnt != (int)strlen(sendStr) + 1) {
        fprintf(stderr, "Error: connection terminated.\n");
        closeSocket(clientSocket);
        if(pthread_mutex_lock(&mutex) != 0) {
            fprintf(stderr, "Error: cannot lock a mutex.\n");
            exit(EXIT_FAILURE);
        }
        clients--;
        printf("%d clients.\n", clients);
        if(pthread_mutex_unlock(&mutex) != 0) {
            fprintf(stderr, "Error: cannot unlock a mutex.\n");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_FAILURE);
      }
    }
  }
}

/*
 * closeSocket関数
 *  →  echo_client/echo_serverと同じのため、コメントの追記は不要
 */
int closeSocket(int socket)
{
  int status;

  status = close(socket);

  if (status == -1) {
    fprintf(stderr, "Error: cannot close a socket.\n");
    exit(EXIT_FAILURE);
  }

  return(EXIT_SUCCESS);
}
