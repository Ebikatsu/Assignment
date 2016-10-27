#include<stdio.h>
#include<stdlib.h>

struct time
{
  int hour;
  int minute;
};

int main(void)
{
  int i;
  struct time tokyo[3] = {{23,40},{23,10},{3,15}};
  struct time india[3];
  struct time difference = {5,30};
  for(i = 0; i < sizeof(india)/sizeof(india[0]); i++)
    {
      india[i].minute = tokyo[i].minute-difference.minute;
      india[i].hour   = tokyo[i].hour+india[i].minute/60-(india[i].minute>=0?0:1)-difference.hour;
      india[i].minute = india[i].minute+60*(india[i].minute/60+(india[i].minute>=0?0:1));
    }
  for(i = 0; i < sizeof(india)/sizeof(india[0]); i++)
    {
      if     (0<=india[i].hour&&india[i].hour<24)printf("東京が%d時%d分の時、インドは%d時%d分です。\n",        tokyo[i].hour, tokyo[i].minute,                     india[i].hour,       india[i].minute);
      else if(india[i].hour<0)                   printf("東京が%d時%d分の時、インドは%d日前の%d時%d分です。\n",tokyo[i].hour, tokyo[i].minute, india[i].hour/24+1, india[i].hour%24+24, india[i].minute);
      else if(24<=india[i].hour)                 printf("東京が%d時%d分の時、インドは%d日後の%d時%d分です。\n",tokyo[i].hour, tokyo[i].minute, india[i].hour/24,   india[i].hour%24,    india[i].minute);
    }
  return EXIT_SUCCESS;
}
