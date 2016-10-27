#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NAME_LENGTH 11

char playerName[NAME_LENGTH];
char enemyName[NAME_LENGTH];

int playerHP;
int enemyHP;

/*playerNameとenemyNameを入力させ、playerHPとenemyHPに300を代入し、0を返す。*/
int initialize();
/*プレイヤーと敵のHPを表示する。*/
void displayHP();
/*playerに次の動作を決定させる。攻撃する場合は1を、気をためる場合は2を、降参する場合は3を返す。*/
int player();
/*引数が1の場合はenemy(rand()%30)を実行し、その旨を表示する、
  引数が2の場合はenemy(0)を実行し、playerが気をためていることを表示する。
  引数が3の場合はplayerHPを0とする。*/
void calculate(int action);
/*敵の動作*/
void enemy(int damage);
/*勝敗を判断し、結果を表示する。*/
int judge();

int main(void)
{
  int termination=1;
  int action;

  termination=initialize();

  while(!termination)//terminationが0になるまで繰り返す。
  {
    displayHP();
    action=player();
    calculate(action);
    termination=judge();
  }

  return EXIT_SUCCESS;
}

int initialize()
{
  srand(time(NULL));
  printf("プレイヤーの名前を入力して下さい。\n");
  scanf("%s",playerName);
  printf("敵の名前を入力してください。\n");
  scanf("%s",enemyName);

  playerHP=300;
  enemyHP=300;

  return 0;
}

int player()
{
  int action;

  printf("\nどうする?");
  printf("1 - 攻撃する、2 - 気をためる、3 - 降参する 4 - 入れ替わる\n");
  scanf("%d",&action);

  return action;
}

void calculate(int action)
{
  static int count=0;

  switch(action)
  {
  case 1://攻撃する場合
    printf("%sの攻撃!\n",playerName);
    int damage=(rand()%30)*(count+1);
    enemy(damage);
    count=0;
    break;
  case 2://気をためる場合
    printf("%sは気をためている。\n",playerName);
    enemy(0);
    count++;
    break;
  case 3://降参する場合
    playerHP=0;
    count=0;
    break;
  case 4://入れ替わる場合
    {
      printf("入れ替わった。\n");
      char Name[NAME_LENGTH];
      int i,HP;
      for(i=0;i<NAME_LENGTH;i++)Name[i]=playerName[i];
      for(i=0;i<NAME_LENGTH;i++)playerName[i]=enemyName[i];
      for(i=0;i<NAME_LENGTH;i++)enemyName[i]=Name[i];
      HP=playerHP;
      playerHP=enemyHP;
      enemyHP=HP;
      count=0;
      break;
    } 
  }
}

void enemy(int damage)
{
  int actionPattern[2][5]={{0,0,0,0,1},{0,1,1,2,2}},row=(enemyHP>=playerHP)?0:1,column=rand()%5,action=actionPattern[row][column];
  switch(action)
  {
  case 0:
    printf("%sは%dのダメージを受けた。\n",enemyName,damage);
    enemyHP-=damage;
    if(enemyHP>0)
    {
      printf("%sの攻撃!\n",enemyName);
      damage=rand()%30;
      printf("%sは%dのダメージを受けた。\n",playerName,damage);
      playerHP-=damage;
    }
    break;
  case 1:
    enemyHP-=damage/2;
    printf("%sは身を守っている。\n%sは%dのダメージを受けた。\n",enemyName,enemyName,damage/2);
    break;
  case 2:
    playerHP-=damage;
    printf("%sは入れ替わりの術を使った!\n%sと%sは入れ替わった!\n%sは自分の繰り出した攻撃により%dのダメージを受けた。\n",enemyName,playerName,enemyName,playerName,damage);
    break;
  default:
    printf("入力エラー: %d\n",action);
  }
}

int judge()
{
  if(playerHP<=0)//プレイヤーのHPが0以下の場合プレイヤーが負けたことになる。
  {
    printf("\n%sは%sに負けた。\n",playerName,enemyName);
    return 1;
  }
  else if(enemyHP<=0)//敵のHPが0以下の場合敵が負けたことになる。
  {
    printf("\n%sは%sを倒した。\n",playerName,enemyName);
    return 1;
  }
  else//プレイヤーも敵もHPが残っている場合ゲームを続行する。
  {
    return 0;
  }
}

void displayHP()
{
  printf("%sのHPは%dです。\n",playerName,playerHP);
  printf("%sのHPは%dです。\n",enemyName,enemyHP);
}
