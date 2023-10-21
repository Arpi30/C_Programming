#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool prime(int szam){
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
}
