#include<stdio.h>
#include<stdlib.h>

double power(double dx, int no);

int main(void)
{
  double dx;
  int no;
  scanf("%lf",&dx);
  scanf("%d",&no);
  printf("%lf\n",power(dx,no));
  return EXIT_SUCCESS;
}

double power(double dx, int no)
{
  int i;
  double tmp = 1;

  for(i = 0; i<no; i++)
    tmp *= dx;
  return (tmp); 
}
