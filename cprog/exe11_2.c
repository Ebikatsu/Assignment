#include<stdio.h>
#include<stdlib.h>

struct student
{
  char *name;
  int math;
  int english;
  float average;
};

int main(void)
{
  int i;
  struct student s[3];

  s[0].name    = "鈴木";
  s[0].math    = 85;
  s[0].english = 50;

  s[1].name    = "佐藤";
  s[1].math    = 75;
  s[1].english = 70;

  s[2].name    = "高橋";
  s[2].math    = 90;
  s[2].english = 65;

  for(i = 0; i < sizeof(s)/sizeof(s[0]); i++)s[i].average = (float)(s[i].math+s[i].english)/2;
  for(i = 0; i < sizeof(s)/sizeof(s[0]); i++)printf("名前 %s\n数学 %d\n英語 %d\n平均 %f\n\n", s[i].name, s[i].math, s[i].english, s[i].average);
  return EXIT_SUCCESS;
}
