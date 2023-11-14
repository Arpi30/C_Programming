#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GRN "\x1B[32m"
#define RED "\x1B[31m"
#define WHT "\x1B[37m"
#define MAG "\x1B[35m"
#define RESET "\x1B[0m"

void gotoxy(int x, int y)
{
  printf("%c[%d;%df", 0x1B, y, x); //x és y koordinálása ASCII kóddal
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
  int pulse = 0;
  char keypress;
  clrscreen();
  negyzet(0, 50, 5, 50);

  while (1)
  {
    if(pulse % 2 == 0){
      alakzat(8, 10, 001, GRN, RESET);
      alakzat(3, 10, 002, RED, RESET);
    }else{
      alakzat(8, 10, 001, WHT, RESET);
      alakzat(3, 10, 002, MAG, RESET);
    }
    pulse++;
    usleep(500000);

    if (kbhit()){
      keypress = getch();
      if ((int)keypress == 27)
      {
        break;
      }
    }
  }
  



  return 0;
}