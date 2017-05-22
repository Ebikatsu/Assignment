#include<stdio.h>

typedef enum status{
	STATE1,STATE2,STATE3,ERROR
} STATE; //STATE型の宣言

//get関数のプロトタイプ宣言
int get(void);

int main(void)
{
	char c;
	STATE s;
	s = STATE1;//初期状態は状態1

	while((c = get()) != EOF){
		switch(s){
		case STATE1:
			if(c == 'a'){s = STATE2;}
			else if(c == 'c'){s = STATE3;}
			else {s = ERROR;}
			break;
		case STATE2:
			if(c == 'b'){s = STATE2;}
			else if(c == 'c'){s = STATE3;}
			else {s = ERROR ;}
			break;
		case STATE3:
			if(c == 'a'){s = STATE2;}
			else if(c == 'b'){s = ERROR;}
			else if(c == 'c'){s = ERROR ;}
			else {s = ERROR;}
			break;
		case ERROR:
			break;
		}
	}
	if(s == STATE3){//終了状態は状態3
		printf("accept\n");
	} else {
		printf("reject\n");
	}

	return 0;
}

int get(void){
	int c;
	while((c = getchar()) == '\n');
	return c;
}

