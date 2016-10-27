#include<stdio.h>
#include<stdlib.h>

void swap(double *x, double *y);

int main(void)
{
  double ary[]={1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
  double *p;
  for(p=ary;p<=&ary[5];p+=2)swap(p,p+1);
  for(p=ary;p<=&ary[5];p++)printf("%lf\n",*p);
  return EXIT_SUCCESS;
}

void swap(double *x, double *y){
  double tmp;

  printf("func : x=%lf, y=%lf\n", *x, *y);
  tmp = *x;
  *x = *y;
  *y = tmp;
  printf("func : x=%lf, y=%lf\n", *x, *y);
}
