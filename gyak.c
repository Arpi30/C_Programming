#include<stdio.h>
#include<stdbool.h>
#include<math.h>

/*---------------------------------------------------------------------------------------------*/
/*---------------------------------------PRIM SZAMOK-------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/

/* bool prime(int szam){
  int i = 2;
  while( i <= sqrt(szam) && szam % i != 0){
    i++;
  }
  return i > sqrt(szam) ? true : false;
}

int main()
{
  int x;
  printf("Adj meg egy szamot!\n");
  scanf("%d", &x);
  if(prime(x)){
    printf("A %d prim szam", x);
  }else{
    printf("A %d nem prim szam", x);
  }
  prime(x);
  return 0;
} */
/*---------------------------------------------------------------------------------------------*/
/*-----------------------------------DECIMALIS-BINARIS-----------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
int main()
{
  int decimal_num, binary_num = 0, i = 1, remainder;
  printf("Enter a decimal number: ");
  scanf("%d", &decimal_num);
  while (decimal_num != 0)
  {
    remainder = decimal_num % 2;
    decimal_num = decimal_num / 2;
    binary_num = binary_num + remainder * i;
    i *= 10;
  }
  printf("Binary number: %d\n", binary_num);
  return 0;

  return 0;
}