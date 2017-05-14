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
    struct sockaddr_in destSockAddr1;
    struct sockaddr_in destSockAddr2;
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
    int destPort;			//送信先のポート番号
    int destSocket1;
    int destSocket2;
    char destAddress[256];		//送信先のIPアドレス
    int status;
    char sendStr1[BUFFER_LEN];
    char sendStr2[BUFFER_LEN];
    char recvStr1[BUFFER_LEN];
    char recvStr2[BUFFER_LEN];
    int numsnt;
    int numrcv1;
    int numrcv2;
    char *enable = "";
    
    /*** 引数の数を確認する ***/
    if (argc != 3) {
        printf("usage: %s <adress> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    /*** char型の配列destAddressの全ての要素にnull文字を代入する ***/
    memset(&destAddress, 0, sizeof(destAddress));

    /*** destAddressにひとつめの引数（サーバのIPアドレスを文字列として入れる ***/
    strcpy(destAddress, argv[1]);

    /*** ふたつめの引数（送信先のポート番号）をint型に変換してdestPortに代入する ***/
    destPort = atoi(argv[2]);

    //unsigned long inet_addr(char *cp);文字列で表されたIPアドレスを数値に変換する。
    /*** char型で送信先のIPアドレスが書き込まれたdestAddressをunsigned long型に変換してdestSockAddr.sin_addr.s_addrに代入する ***/
    destSockAddr1.sin_addr.s_addr = inet_addr(destAddress);
    destSockAddr2.sin_addr.s_addr = inet_addr(destAddress);

    //unsigned short htons(unsigned short a);ホスト・バイト・オーダーからネットワーク・バイト・オーダーに変換する
    //ホスト・バイト・オーダーはリトルエンディアン
    //ネットワーク・バイト・オーダーはビッグエンディアン
    /*** int型の送信先ポート番号destPortをビッグエンディアンに変換してdestSockAddr.sin_portに代入する ***/
    destSockAddr1.sin_port = htons(destPort);
    destSockAddr2.sin_port = htons(destPort);

    /*** アドレスファミリの指定 ***/
    destSockAddr1.sin_family = AF_INET;
    destSockAddr2.sin_family = AF_INET;

    //int socket(int domain, int type, int protocol);
    //domain プロトコルファミリ
    //type 通信の種類。SOCK_STREAMは順次双方向バイトストリーム。コネクション型の信頼性が高い通信。
    //protocol エンドツーエンドプロトコルの指定。0は自動設定
    /*** ソケットを作成し、ソケット記述子をdestSocketに代入する ***/
    destSocket1= socket(AF_INET, SOCK_STREAM, 0);

    printf("DEBUG\n");
    printf("destSocket1=%d\n",destSocket1);
    printf("DEBUG\n");

    /*** ソケットの作成に失敗した時の処理 ***/
    if (destSocket1 == -1) {
        fprintf(stderr, "Error: socket creation is unsuccessful.\n");
        exit(EXIT_FAILURE);
    }

    destSocket2= socket(AF_INET, SOCK_STREAM, 0);

    printf("DEBUG\n");
    printf("destSocket2=%d\n",destSocket2);
    printf("DEBUG\n");

    if (destSocket2 == -1) {
        fprintf(stderr, "Error: socket creation is unsuccessful.\n");
        exit(EXIT_FAILURE);
    }

    /*** 接続先のIPアドレス、ポート番号を表示 ***/
    printf("Connect to %s:%d ...\n", destAddress, destPort);

    //int connect(int socket, const struct sockaddr *address, size_t address_len);
    //socket ソケットディスクリプタ
    //address sockaddr構造体のへのポインタ
    //address_len アドレス構造体のサイズ
    //戻り値 0:成功 -1:失敗
    /*** 作成したソケットで接続を確立する ***/
    status = connect(destSocket1, (struct sockaddr *)&destSockAddr1, (socklen_t)sizeof(destSockAddr1));
    /*** 接続の確率に失敗した時の処理 ***/
    if (status == -1) {
        fprintf(stderr, "Error: cannot connect to server.\n");
        closeSocket(destSocket1);
        exit(EXIT_FAILURE);
    }

    /*** 接続に成功したことを表示 ***/
    printf("Socket1 is connected...\n");

    status = connect(destSocket2, (struct sockaddr *)&destSockAddr2, (socklen_t)sizeof(destSockAddr2));
    if (status == -1) {
        fprintf(stderr, "Error: cannot connect to server.\n");
        closeSocket(destSocket2);
        exit(EXIT_FAILURE);
    }

    printf("Socket2 is connected...\n");

    //クライアント側もサーバ側もソケットが２つつながったように表示される。

    /*** 無限ループ ***/
    while (enable != NULL) {

	printf("DEBUG\n");
	printf("enter while\n");
	printf("DEBUG\n");

        /*** 標準入力から文字列を受け取りchar *sendStrに書き込む ***/
        printf("SEND1>> ");
        enable = fgets(sendStr1, BUFFER_LEN, stdin);
        printf("SEND2>> ");
        enable = fgets(sendStr2, BUFFER_LEN, stdin);

	printf("DEBUG\n");
	printf("%s\n",sendStr1);
	printf("DEBUG\n");

	printf("DEBUG\n");
	printf("%s\n",sendStr2);
	printf("DEBUG\n");

	//int send(int socket, const void *msg, unsigned int msgLength, int flag);
	//socket ソケットディスクリプタ
	//msg 送信するメッセージが格納されているアドレス
	//msgLength メッセージのバイト数
	//flag ソケットが呼び出された際の動作を指定する。0はデフォルトの動作
	//戻り値 送信したバイト数。失敗したら-1
        /*** メッセージを送信する ***/
        numsnt = send(destSocket1, sendStr1, strlen(sendStr1) + 1,
                      NO_FLAGS_SET);


        /*** 送信するデータを完全に送信できなかった時の処理 ***/
        if (numsnt != (int)strlen(sendStr1) + 1) {
          fprintf(stderr, "Error: Connection terminated.\n");
          closeSocket(destSocket1);
          exit(EXIT_FAILURE);
        }

	printf("send1\n");

        numsnt = send(destSocket2, sendStr2, strlen(sendStr2) + 1, NO_FLAGS_SET);


        if (numsnt != (int)strlen(sendStr2) + 1) {
          fprintf(stderr, "Error: Connection terminated.\n");
          closeSocket(destSocket2);
          exit(EXIT_FAILURE);
        }

	printf("send2\n");

	//クライアント側では２つとも正常にsendされたことになっているが、サーバ側ではあとに接続されたソケットからしか受け取っていない。

	//int recv(int socket, void *msg, unsigned int msgLength, int flag);
	//socket ソケットディスクリプタ
	//msg 受信するメッセージが格納されているアドレス
	//msgLength メッセージのバイト数
	//flag ソケットが呼び出された際の動作を指定する。0はデフォルトの動作
	//戻り値 受信したバイト数。失敗したら-1
        /*** メッセージを受信する ***/
        //numrcv1 = recv(destSocket1, recvStr1, BUFFER_LEN, NO_FLAGS_SET);

        /*** 正常に受信できなかった時の処理 ***/
	/*
        if (numrcv1 == 0 || numrcv1 == -1) {
          fprintf(stderr, "Error: Connection terminated.\n");
          closeSocket(destSocket1);
          closeSocket(destSocket2);
          exit(EXIT_FAILURE);
        }
	*/

        numrcv2 = recv(destSocket2, recvStr2, BUFFER_LEN, NO_FLAGS_SET);

        if (numrcv2 == 0 || numrcv2 == -1) {
          fprintf(stderr, "Error: Connection terminated.\n");
          closeSocket(destSocket1);
          closeSocket(destSocket2);
          exit(EXIT_FAILURE);
        }

        printf("RECEIVE1>> %s", recvStr1);
        printf("RECEIVE2>> %s", recvStr2);

    }

    /*** ソケットを切断する ***/
    closeSocket(destSocket1);
    closeSocket(destSocket2);
    //サーバ側ではひとつのソケットは正常に破棄されるが、もうひとつのソケットは正常に破棄されず、サーバダウンを起こす。


    /*** 正常終了 ***/
    return(EXIT_SUCCESS);
}


int closeSocket(int socket)
{
    int status;

    /*** ソケットを切断する ***/
    status = close(socket);

    /*** ソケットを正常に切断できなかった時の処理 ***/
    if (status == -1) {
        fprintf(stderr, "Error: cannot close a socket.\n");
        exit(EXIT_FAILURE);
    }

    /*** 正常終了 ***/
    return(EXIT_SUCCESS);
}
