#include<stdio.h>
#include<stdlib.h>

int main(void){
  int val1 = 5;
  int val2 = 11;
  int *p_val;

  //ブロック1
  p_val = &val1;

  printf("&val1 =%p\n", &val1);
  printf("val1  =%d\n", val1);
  printf("&p_val=%p\n", &p_val);
  printf("p_val =%p\n", p_val);
  printf("*p_val=%d\n", *p_val);
  printf("__________\n");

  //ブロック2
  *p_val = 100;

  printf("&val1 =%p\n", &val1);
  printf("val1  =%d\n", val1);
  printf("&p_val=%p\n", &p_val);
  printf("p_val =%p\n", p_val);
  printf("*p_val=%d\n", *p_val);
  printf("__________\n");

  //ブロック3
  p_val = &val2;

  printf("&val2 =%p\n", &val2);
  printf("val2  =%d\n", val2);
  printf("&p_val=%p\n", &p_val);
  printf("p_val =%p\n", p_val);
  printf("*p_val=%d\n", *p_val);
  printf("__________\n");

  //ブロック4
  *p_val += 10;

  printf("&val2 =%p\n", &val2);
  printf("val2  =%d\n", val2);
  printf("&p_val=%p\n", &p_val);
  printf("p_val =%p\n", p_val);
  printf("*p_val=%d\n", *p_val);
  printf("__________\n");
  return EXIT_SUCCESS;
}
