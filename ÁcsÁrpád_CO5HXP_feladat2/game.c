#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<conio.h>

#define GRN "\x1B[32m"
#define RED "\x1B[31m"
#define WHT "\x1B[37m"
#define MAG "\x1B[35m"
#define RESET "\x1B[0m"

void gotoxy(int x, int y)
{
  printf("%c[%d;%df", 0x1B, x, y); //x és y koordinálása ASCII kóddal
}

void clrscreen(void){
  system("cls");  // terminál törlése minden futásnál
}

void negyzet(int x1, int x2, int y1, int y2){
  int x, y;

  for (x = x1; x < x2; x++){
    gotoxy(x, y1);  // felső sor
    printf("%c", 219);
    gotoxy(x, y2);  //alsó sor
    printf("%c", 219);
  }
  
  for (y = y1; y < y2; y++){
    gotoxy(x1, y);  //bal oldal
    printf("%c", 219);
    gotoxy(x2, y);  //jobb oldal
    printf("%c", 219);
  }
}

void alakzat(int x, int y, int *ascii, char *color, char *res){
  gotoxy(x, y);
  printf("%s%c%s", color, ascii, res);
}


int main(){
  /*---------------------------ALAKZAT VALTOZOK-----------------------*/
  int x_alakzat_1 = 8;
  int x_alakzat_2 = 3;
  int y_alakzat_1 = 10;
  int y_alakzat_2 = 10;
  int i;
  /*------------------------------------------------------------------*/

  while (1)
  {
    clrscreen();
    negyzet(0, 30, 5, 50);
    alakzat(x_alakzat_1, y_alakzat_1, 001, GRN, RESET);
    alakzat(x_alakzat_2, y_alakzat_2, 002, RED, RESET);

    switch (getch())
    {
    case 'd':
      y_alakzat_1++;
      break;
    case 'a':
      y_alakzat_1--;
      break;
    case 's':
      x_alakzat_1++;
      break;
    case 'w':
      x_alakzat_1--;
      break;
    case 'x':
      exit(1);
    }

    if (y_alakzat_1 == 50 || y_alakzat_1 == 5 || x_alakzat_1 == 1 || x_alakzat_1 == 30)
    {
      exit(1);
    }
    x_alakzat_2++;
  }
  return 0;
}