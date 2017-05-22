#include<stdio.h>

typedef enum status{
	AEVENBEVEN,AEVENBODD,AODDBEVEN,AODDBODD,ERROR
} STATE; //STATE型の宣言

//get関数のプロトタイプ宣言
int get(void);

int main(void)
{
	char c;
	STATE s;
	s = AEVENBEVEN;//初期状態

	while((c = get()) != EOF){
		switch(s){
		case AEVENBEVEN:
			switch(c){
			case 'a':
				s = AODDBEVEN;
				break;
			case 'b':
				s = AEVENBODD;
				break;
			default:
				s = ERROR;
			}
			break;
		case AEVENBODD:
			switch(c){
			case 'a':
				s = AODDBODD;
				break;
			case 'b':
				s = AEVENBEVEN;
				break;
			default:
				s = ERROR;
			}
			break;
		case AODDBEVEN:
			switch(c){
			case 'a':
				s = AEVENBEVEN;
				break;
			case 'b':
				s = AODDBODD;
				break;
			default:
				s = ERROR;
			}
			break;
		case AODDBODD:
			switch(c){
			case 'a':
				s = AEVENBODD;
				break;
			case 'b':
				s = AODDBEVEN;
				break;
			default:
				s = ERROR;
			}
			break;
		case ERROR:
			break;
		}
	}
	if(s == AEVENBEVEN){//終了状態
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

