#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct mystruct
{
  char name[128];
  int age;
  char gakubu;
  char number[7];
};

void printstruct(struct mystruct x);

int main(void)
{
  struct mystruct a = {"伊藤太清", 19, 's', "153012"}, b = {"長迫強士", 30, 's', "153072"};
  printstruct(a);
  printstruct(b);
  strcpy(b.name, a.name);
  b.age = a.age;
  b.gakubu = a.gakubu;
  strcpy(b.number, a.number);
  printstruct(a);
  printstruct(b);
  return EXIT_SUCCESS;
}

void printstruct(struct mystruct x)
{
  printf("%s\n%d\n%c%s\n", x.name, x.age, x.gakubu, x.number);
}
