     1	#include <stdio.h>
     2	#include <stdlib.h>
     3	#include <time.h>
     4	#define NAME_LENGTH 11
       
     5	char playerName[NAME_LENGTH];
     6	char enemyName[NAME_LENGTH];
       
     7	int playerHP;
     8	int enemyHP;
       
     9	/*playerNameとenemyNameを入力させ、playerHPとenemyHPに300を代入し、0を返す。*/
    10	int initialize();
    11	/*プレイヤーと敵のHPを表示する。*/
    12	void displayHP();
    13	/*playerに次の動作を決定させる。攻撃する場合は1を、気をためる場合は2を、降参する場合は3を返す。*/
    14	int player();
    15	/*引数が1の場合はenemy(rand()%30)を実行し、その旨を表示する、
    16	  引数が2の場合はenemy(0)を実行し、playerが気をためていることを表示する。
    17	  引数が3の場合はplayerHPを0とする。*/
    18	void calculate(int action);
    19	/*敵の動作*/
    20	void enemy(int damage);
    21	/*勝敗を判断し、結果を表示する。*/
    22	int judge();
       
    23	int main(void)
    24	{
    25	  int termination=1;
    26	  int action;
       
    27	  termination=initialize();
       
    28	  while(!termination)//terminationが0になるまで繰り返す。
    29	  {
    30	    displayHP();
    31	    action=player();
    32	    calculate(action);
    33	    termination=judge();
    34	  }
       
    35	  return EXIT_SUCCESS;
    36	}
       
    37	int initialize()
    38	{
    39	  srand(time(NULL));
    40	  printf("プレイヤーの名前を入力して下さい。\n");
    41	  scanf("%s",playerName);
    42	  printf("敵の名前を入力してください。\n");
    43	  scanf("%s",enemyName);
       
    44	  playerHP=300;
    45	  enemyHP=300;
       
    46	  return 0;
    47	}
       
    48	int player()
    49	{
    50	  int action;
       
    51	  printf("\nどうする?");
    52	  printf("1 - 攻撃する、2 - 気をためる、3 - 降参する 4 - 入れ替わる\n");
    53	  scanf("%d",&action);
       
    54	  return action;
    55	}
       
    56	void calculate(int action)
    57	{
    58	  static int count=0;
       
    59	  switch(action)
    60	  {
    61	  case 1://攻撃する場合
    62	    printf("%sの攻撃!\n",playerName);
    63	    int damage=(rand()%30)*(count+1);
    64	    enemy(damage);
    65	    count=0;
    66	    break;
    67	  case 2://気をためる場合
    68	    printf("%sは気をためている。\n",playerName);
    69	    enemy(0);
    70	    count++;
    71	    break;
    72	  case 3://降参する場合
    73	    playerHP=0;
    74	    count=0;
    75	    break;
    76	  case 4://入れ替わる場合
    77	    {
    78	      printf("入れ替わった。\n");
    79	      char Name[NAME_LENGTH];
    80	      int i,HP;
    81	      for(i=0;i<NAME_LENGTH;i++)Name[i]=playerName[i];
    82	      for(i=0;i<NAME_LENGTH;i++)playerName[i]=enemyName[i];
    83	      for(i=0;i<NAME_LENGTH;i++)enemyName[i]=Name[i];
    84	      HP=playerHP;
    85	      playerHP=enemyHP;
    86	      enemyHP=HP;
    87	      count=0;
    88	      break;
    89	    } 
    90	  }
    91	}
       
    92	void enemy(int damage)
    93	{
    94	  int actionPattern[2][5]={{0,0,0,0,1},{0,1,1,2,2}},row=(enemyHP>=playerHP)?0:1,column=rand()%5,action=actionPattern[row][column];
    95	  switch(action)
    96	  {
    97	  case 0:
    98	    printf("%sは%dのダメージを受けた。\n",enemyName,damage);
    99	    enemyHP-=damage;
   100	    if(enemyHP>0)
   101	    {
   102	      printf("%sの攻撃!\n",enemyName);
   103	      damage=rand()%30;
   104	      printf("%sは%dのダメージを受けた。\n",playerName,damage);
   105	      playerHP-=damage;
   106	    }
   107	    break;
   108	  case 1:
   109	    enemyHP-=damage/2;
   110	    printf("%sは身を守っている。\n%sは%dのダメージを受けた。\n",enemyName,enemyName,damage/2);
   111	    break;
   112	  case 2:
   113	    playerHP-=damage;
   114	    printf("%sは入れ替わりの術を使った!\n%sと%sは入れ替わった!\n%sは自分の繰り出した攻撃により%dのダメージを受けた。\n",enemyName,playerName,enemyName,playerName,damage);
   115	    break;
   116	  default:
   117	    printf("入力エラー: %d\n",action);
   118	  }
   119	}
       
   120	int judge()
   121	{
   122	  if(playerHP<=0)//プレイヤーのHPが0以下の場合プレイヤーが負けたことになる。
   123	  {
   124	    printf("\n%sは%sに負けた。\n",playerName,enemyName);
   125	    return 1;
   126	  }
   127	  else if(enemyHP<=0)//敵のHPが0以下の場合敵が負けたことになる。
   128	  {
   129	    printf("\n%sは%sを倒した。\n",playerName,enemyName);
   130	    return 1;
   131	  }
   132	  else//プレイヤーも敵もHPが残っている場合ゲームを続行する。
   133	  {
   134	    return 0;
   135	  }
   136	}
       
   137	void displayHP()
   138	{
   139	  printf("%sのHPは%dです。\n",playerName,playerHP);
   140	  printf("%sのHPは%dです。\n",enemyName,enemyHP);
   141	}
