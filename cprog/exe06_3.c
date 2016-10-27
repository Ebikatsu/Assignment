#include<stdio.h>
#include<stdlib.h>

float average(int *p,int n);

int main(void)
{
  int p1[]={52,38,79,89,57,71,90},
    p2[]={67,89,55,45,91},
      p3[]={89,34,67,65,67,55};

      printf("%f\n%f\n%f\n",average(p1,7),average(p2,5),average(p3,6));
      return EXIT_SUCCESS;
}

float average(int *p,int n)
{
  int i;
  float sum=0;
  for(i=0;i<n;i++)sum+=(float)(*(p++));
  return sum/(float)n;
}
