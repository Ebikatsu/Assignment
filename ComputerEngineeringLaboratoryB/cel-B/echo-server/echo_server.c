#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define NO_FLAGS_SET 0
#define BUFFER_LEN 256

int closeSocket(int);

int main(int argc, char *argv[])
{
    struct sockaddr_in serverAddress;
    struct sockaddr_in clientAddress;
 /*
netinet/in.h

struct in_addr {
	u_int32_t s_addr;		//IPアドレス
};

struct sockaddr_in {
	u_char sin_len;
	u_char sin_family;
	u_short sin_port;		//ポート番号
	struct in_addr sin_addr;	//IPアドレス
	char sin_zero[8];
};
*/
    int serverPort;
    int clientPort;
    int serverSocket;
    int clientSocket;
    char recvStr[BUFFER_LEN];
    char sendStr[BUFFER_LEN];
    int numrcv;
    int numsnt;
    unsigned int clientSize;
    int status;
    int flag;

    /*** struct sockaddr_in型のclientAddressのバイト数をunsigned int clientSizeに代入する ***/
    clientSize = sizeof(clientAddress);

    /*** コマンドライン引数の個数をチェックする ***/
    if (argc != 2) {
      printf("usage: %s <port>\n", argv[0]);
      exit(EXIT_FAILURE);
    }

    /*** 1番目のコマンドライン引数をint型に変換してseverPortに代入する ***/
    serverPort = atoi(argv[1]);

    /*** struct sockaddr_in serverAddressの全てのメンバを0で初期化する ***/
    memset(&serverAddress, 0, sizeof(serverAddress));

    //unsigned short htons(unsigned short a);ホスト・バイト・オーダーからネットワーク・バイト・オーダーに変換する
    //ホスト・バイト・オーダーはリトルエンディアン
    //ネットワーク・バイト・オーダーはビッグエンディアン
    /*** int serverPortをビッグエンディアンに変換してserverAddress.sin_portに代入する ***/
    serverAddress.sin_port = htons(serverPort);

    /*** アドレスファミリの設定 ***/
    serverAddress.sin_family = AF_INET;

    //INADDR_ANYは0で、任意のホストを意味するipアドレス
    //u_long htonl(u_long);ホスト・バイト・オーダーからネットワーク・バイト・オーダーに変換する
    /*** serverAddress.sin_addr.s_addrに任意のホストを意味するアドレスを代入する。 ***/
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);

    //int socket(int domain, int type, int protocol);
    //domain プロトコルファミリ
    //type 通信の種類。SOCK_STREAMは順次双方向バイトストリーム。コネクション型の信頼性が高い通信。
    //protocol エンドツーエンドプロトコルを指定する。0は自走設定
    /*** ソケットを作成し、ソケット記述子をdestSocketに代入する ***/
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    /*** ソケットの作成に失敗した時の処理 ***/
    if (serverSocket == -1) {
      fprintf(stderr, "Error: socket creation is unsuccessful.\n");
      exit(EXIT_FAILURE);
    }

    //int bind(int socket, const struck sockaddr *address, size_t address_len);
    //socket ソケット記述子
    //address プロトコル対応のアドレス構造体へのポインタ
    //address_len アドレス構造のサイズ
    /*** serverSocketにIPアドレスとポート番号をつける ***/
    bind(serverSocket, (struct sockaddr *)&serverAddress, 
        sizeof(serverAddress));

    /*** flagが1である限りループ ***/
    do {
      //int listen(int socket, int queue_limit);
      //socket ソケット記述子
      //queue_limit キューの長さ（接続要求の上限値）
      /*** コネクションの確立時にクライアントからの接続要求を格納するキューをサーバ側で作る ***/
      listen(serverSocket, 1);

      /*** 接続待ち状態であることを表示 ***/
      printf("Waiting for connection ...\n");

      //int accept(int socket, struct sockaddr *address, size_t *address_len);
      //socket ソケット記述子
      //address 呼び出し側のクライアントのアドレスポインタ
      //address_len アドレス構造体の長さ
      //成功時新しいソケットファイルディスクリプタを返す。失敗時-1を返す。
      /*** コネクションの確立時に、該当するソケットへの接続を待つ動作を用意する。クライアントからの接続要求に合わせて、listen()でキューイングしたソケットを取り出します。 ***/
      clientSocket = 
        accept(serverSocket, (struct sockaddr *)&clientAddress, &clientSize);

      /*** accept関数が失敗した時の処理 ***/
      if (clientSocket == -1) {
        fprintf(stderr, "Cannot accept a connection.\n");
      }

      //char *inet_ntoa(struct in_addr in);
      //in ホストのIPアドレス
      //IPアドレスを文字列に変換する
      /*** 接続してきたクライアントの情報を表示 ***/
      printf("Connected from %s.\n", inet_ntoa(clientAddress.sin_addr));

      /*** 無限ループ ***/
      while (1) {

	//int recv(int socket, void *msg, unsigned int msgLength, int flag);
	//socket ソケットディスクリプタ
	//msg 受信するメッセージが格納されているアドレス
	//msgLength メッセージのバイト数
	//flag ソケットが呼び出された際の動作を指定する。0はデフォルトの動作
	//戻り値 受信したバイト数。失敗したら-1
        /*** メッセージを受信する ***/
        numrcv = recv(clientSocket, recvStr, BUFFER_LEN, 0);

        /*** 正常に受信できなかった時の処理 ***/
        if (numrcv == -1 || numrcv == 0) {
          printf("Connection terminated.\n");
          status = close(clientSocket);
          flag = 1;
          break;
        }

        /*** 受信した文字列と文字数を表示 ***/
        printf("RECEIVE(%u)>>%s", (unsigned)strlen(recvStr), recvStr);

        //int send(int socket, const void *msg, unsigned int msgLength, int flag);
	//socket ソケットディスクリプタ
	//msg 送信するメッセージが格納されているアドレス
	//msgLength メッセージのバイト数
	//flag ソケットが呼び出された際の動作を指定する。0はデフォルトの動作
	//戻り値 送信したバイト数。失敗したら-1
        /*** メッセージを送信する ***/
        numsnt = send(clientSocket, recvStr, strlen(recvStr) + 1, 0);

        /*** 正常に送信できなかった時の処理 ***/
        if (numsnt != strlen(recvStr) + 1) {
          if (numsnt != (int)strlen(sendStr) + 1) {
            fprintf(stderr, "Error: Connection terminated.\n");
            flag = 0;
            break;
          }
        }
      }
    } while (flag);

    /*** ソケットを切断する ***/
    closeSocket(serverSocket);

    /*** 正常終了 ***/
    return(EXIT_SUCCESS);
}

/*
 * closeSocket関数の内容はecho_clientと同じのため、コメントの追記は不要
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
