// Felhasznált tartalom:
// fgets()  https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm
// strcmp() https://www.programiz.com/c-programming/library-function/string.h/strcmp
// kereses tömbben  https://codeforwin.org/c-programming/c-program-to-search-element-in-array
// teglalap menuhöz https://codeforwin.org/c-programming/square-star-pattern-in-c
// W3SCHOOLS, STACKOWERFLOW, C-s fórumok


#include<stdio.h>
#include<string.h>

#define N 5

/*----------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------ÚJSOR KARAKTER TÖRLÉSE------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------------------------------*/
void removeNewLine(char *str)             // az újsor karakter megváltoztatása
{
  int len = strlen(str);  // a string hossza elmentése egy változóba
  if (len > 0 && str[len - 1] == '\n')    // ha a hossz 0-nál nagyobb és a string utolsó értéke egy újsor karakter akkor helyettesíti egy null értékkel
  {
    str[len - 1] = '\0';
  }
}
/*----------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------MENŰ------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------------------------------*/
int menu(){
  // menu változók
  int val;                // ebbe fogom elmenteni a menu sorszámát
  int felso_sor = 2;      //a menu felső része, sor
  int also_sor = 3;     // a menu also része, sor
  int felso_oszlop = 50;  //a menu felső része, oszlop
  int also_oszlop = 50; // a menu also része, oszlop

  int i, j, k, l;         // a ciklusok változói a menu kirajzolásához

  for (i = 0; i < felso_sor; i++)                     // a menu felső része
  {
    for (j = 0; j < felso_oszlop; j++)
    {
      if (i == 0 || j == 0 || j == felso_oszlop - 1)  // A menu keretjének a megrajzolása
      {
        printf("*");
      }
      else
      {
        printf(" ");      // A téglalap belső része tiszta
      }
    }
    printf("\n");
  }
  printf("*         \33[4m\033[0;31mUDVOZOLJUK\033[0m \033[0;37mA\033[0m \033[0;32mTELEFONKONYVBEN\033[0m\33[0m           *\n"); //A menu címe színezése
  printf("*             \33[4m\033[0;31mKESZITETTE:\033[0m \033[0;32mACS ARPAD\033[0m\33[0m              *\n");

  for (k = 0; k < also_sor; k++)                      // A menu alsó része
  {
    for (l = 0; l < also_oszlop; l++)
    {
      if (k == also_sor - 1 || l == 0 || l == also_oszlop - 1)
      {
        printf("*");
      }
      else
      {
        printf(" ");
      }
    }
    printf("\n");
  }
  printf("*           VALASSZON A LEHETOSEGEK KOZUL        *\n");                                               //A menu elemeinek aláhúzása és színezése
  printf("*     \33[4m1.Hozzaadas\33[0m    \33[4m2.kereses\33[0m    \33[4m3.Listazas\33[0m     *\n");
  printf("*        \33[4m\033[0;31m \33[4m4.TORLES\33[0m\033[0m          \33[4m\033[0;31m \33[4m0.KILEPES\33[0m\033[0m           *\n");
  printf("**************************************************\n");
  printf("* \033[0;32mPARANCS:\033[0m\33[0m ");
  scanf("%d", &val);        // a választási lehetőség elmentése a val változóba
  getchar();

  return val;
}
/*----------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------HOZZÁADÁS--------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------------------------------*/
void hozzaad(char telszamP[N][20], char nevP[N][20]) // függvény paraméterként átadom a 2 tömböt amibe elmentem a felhasználó információkat
{
  for (int i = 0; i < N; i++)
  { // Egy loopal feltöltöm a tömböket a bekért adatokkal
    printf("Adj meg egy telefonszamot. A kilepeshez irja be hogy 'exit': \n");
    fgets(telszamP[i], sizeof(telszamP[i]), stdin);
    fflush(stdin);                                                    // bemeneti puffer megtisztítása
    removeNewLine(telszamP[i]);                                       // saját függvény az újsor karakterre

    if (strcmp(telszamP[i], "") == 1 || telszamP[i][0] == '\0')     // ha a bemenet üres vagy \0 akkor kilép
    {
      printf("\33[4m\033[0;31m \33[4mErvenytelen bevitel, kilepes...\33[0m\033[0m \n");
      break;
    }
    else if (strcmp(telszamP[i], "exit") == 0)                      // Ha a bemenet exit akkor kilep a futasbol
    {
      printf("\33[4m\033[0;31m \33[4mKILEPES\33[0m\033[0m\n");
      break;
    }
    fflush(stdin); // Az első bekérés után megtisztítom a puffert hogy az új sor karakter miatt ne hívja meg azonnal a második bekérést.
    printf("Adja meg a hozza tartozo nevet. A kilepeshez irja be hogy 'exit': \n");
    fgets(nevP[i], sizeof(nevP[i]), stdin);
    removeNewLine(nevP[i]);
    if (strcmp(nevP[i], "") == 1 || nevP[i][0] == '\0')            // ha a bemenet üres vagy \0 akkor kilép
    {
      printf("\33[4m\033[0;31m \33[4m0.Ervenytelen bevitel, kilepes...\33[0m\033[0m \n");
      break;
    }
    else if (strcmp(nevP[i], "exit") == 0){                       // Ha a bemenet exit akkor kilep a futasbol
      printf("\33[4m\033[0;31m \33[4mKILEPES\33[0m\033[0m\n");
      break;
    }
      printf("-----------------------------------\n");
  }
}
/*----------------------------------------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------KERESÉS-----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------------------------------*/
void kereses(char nev[N][20], char telszam[N][20]) // függvény paraméterként átadom a 2 tömböt amibe elmentem a felhasználó információkat
{
  char kereses[20];   // A keresés elmentése egy karakter tömbbe
  char valasztas;     // Ebbe a változóba mentjük el 'n' vagy 'y' karaktert ha megkérdezi a program
  int talalat = 0;    // Ez egy kapcsoló változó, ha 0 akkor nincs találat ha 1 akkor van

  while (1)           // végtelen ciklus a kereséshez
  {
    printf("**********************KERESES*********************\n");
    printf("Adja meg a keresett \033[4mnevet\033[0m vagy \033[4mtelefonszamot\033[0m: ");
    fgets(kereses, 20, stdin);                          // fgets-el mentem el a kereset felhasználó infórmációt a kereses karakter tömbbe
    kereses[strcspn(kereses, "\n")] = '\0';             // A kereses tömb validálása

    for (int i = 0; i < N; i++)
    {
      if (strcmp(nev[i], kereses) == 0 || strcmp(telszam[i], kereses) == 0)     //strcmp-vel validálom a kereses értékét
      {
        printf("A keresett \033[4mszemely\033[0m es \033[4mtelefonszam\033[0m: %s ---- %s\n", nev[i], telszam[i]); // Ha van találat akkor kiíratás
        talalat = 1;
      }
    }

    if (!talalat)
    {
      printf("Ezen a neven vagy telefonszamon \33[4m\033[0;31m \33[4mNEM\33[0m\033[0m talalhato felhasznalo.\n"); // Ha nincs talált akkor ez az üzenet jelenjen meg
    }

    do      //Elől tesztelős ciklussal veszem ki az újsor karaktert
    {
      printf("Uj kereses vagy befejezes? i/n\n");
      valasztas = getchar();     
    } while (getchar() != '\n'); 

    if (valasztas == 'i')   //Ha a választás i akkor folytatódhat a keresés ha n akkor kilép a futásból
    {
      continue;
    }
    else if (valasztas == 'n')
    {
      printf("Viszlat!\n");
      break;
    }
    else
    {
      do{
        printf("A megadott valasztas helytelen, kerem probalja ujra! y/n\n");   // helytelen karakter esetén újból megkérdezi hogy akarja e folytatni a felhjasználó a keresést
        valasztas = getchar();
      } while (getchar() != '\n');
      if(valasztas == 'i'){
        continue;
      }else if(valasztas == 'n'){
        break;
      }
    }
  }
}

void listazas(char nev[N][20], char telszam[N][20]) // függvény paraméterként átadom a 2 tömböt amibe elmentem a felhasználó információkat
{ // Egyszerű for ciklus a kiíratáshoz
  for (int i = 0; i < N; i++)
  {
    printf("Az elmentett felhasznalo neve: \033[0;32m%s\033[0m\33[0m es telefonszama: \033[0;32m%s\033[0m\33[0m\n", nev[i], telszam[i]);
    printf("\n");
  }

}
void torles(char nev[N][20], char telszam[N][20]) // függvény paraméterként átadom a 2 tömböt amibe elmentem a felhasználó információkat
{
  int torolt_felh = 0;

  printf("Kerem valassza ki a torolni kivant felhasznalo sorszamat!\n");

  for (int i = 0; i < N; i++)
  {
    printf("%d. nev: \033[0;32m%s\033[0m\33[0m telefonszam: \033[0;32m%s\033[0m\33[0m\n", i + 1, nev[i], telszam[i]);
    printf("\n");
  }
  printf("Melyik felhasznalot szeretne torolni? \n");
  scanf("%d", &torolt_felh);

  if (torolt_felh >= 1 && torolt_felh <= 5)
  {                // Ellenőrizzük, hogy a felhasználó által megadott szám érvényes index-e
    torolt_felh--; // Átállítjuk a 0-tól kezdődő indexre

    for (int j = torolt_felh; j < N - 1; j++) 
    {
      strcpy(nev[j], nev[j + 1]);         // Itt az aktualis elemre ramasoljuk a kovetkezo elemet
      strcpy(telszam[j], telszam[j + 1]);
    }

    // A legutolsó elemeket üres karakterláncokkal töltjük fel
    nev[4][0] = '\0';
    telszam[4][0] = '\0';

    printf("\033[0;32mFELHASZNALO TOROLVE!\033[0m\33[0m\n");
  }
  else
  {
    printf("Ervenytelen index, a felhasznalot nem tudom torolni!.\n");
  }
}

/*----------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------MAIN FÜGGVÉNY---------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------------------------------*/
int main(){
  char telszam[N][20]; // 2 dimenziós tömbe mentem el a telefonszámokat
  char nev[N][20];     // 2 dimenziós tömbe mentem el a neveket
                   // A kereses eltarolasa
  char ujra;          // újrakezdés
  int switch_value = 0; // ebbe a változóba fogom elmenteni a menu lehetőségeket
  int nincs_adat = 1;

  for (int i = 0; i < 5; i++)   // A memóriaszemét eltávolítása miatt üres karakterláncot tárolok el
  {
    nev[i][0] = '\0';
    telszam[i][0] = '\0';
  }

  for (int i = 0; i < 5; i++)   // Itt validálom a tömb elemeit hogy van e tartalma vagy sem, ha van adat akkor a nincs_adat változó tartalma 0/False lesz.
  {
    if (strcmp(nev[i], "") != 0 || strcmp(telszam[i], "") != 0)
    {
      nincs_adat = 0; 
      break;
    }
  }

  do
  {                        // Elől tesztelős ciklussal oldottam meg, Jelenítse meg a menűt amíg 0-át nem add meg a felhasználó
    switch_value = menu(); // a menu erteke egy integer lesz, ha 0-nal nagyobb akkor True

    switch (switch_value)
    {
    case 1:
      hozzaad(telszam, nev);
      nincs_adat = 0;   //Ha lefutott a hozzaad függvény akkor a nincs_talat változó értéke 0 lesz és így már a litázás során ki fogja iratni az elmentett adatokat
      break;
    case 2:
      kereses(nev, telszam);
      break;
    case 3:
      nincs_adat ? printf("\33[4m\033[0;31mNincs elmentett Adat! Kerem adjon hozza felhasznalokat!\033[0m\n") : listazas(nev, telszam); // Ha nincs_adat változó értéke 1 akkor a következő üzenet jelenik meg, Ellenkező esetben meghívja a listazas függvényt
      break;
    case 4:
      nincs_adat ? printf("\33[4m\033[0;31mNincs elmentett Adat! Kerem adjon hozza felhasznalokat!\033[0m\n") : torles(nev, telszam); // Ha nincs_adat változó értéke 1 akkor a következő üzenet jelenik meg, Ellenkező esetben meghívja a torles függvényt
      break;
    case 0: // 0-val való kilépés a programból
      break;
    default:
      puts("\33[4m\033[0;31mNincs ilyen sorszamu lehetoseg, kerem probalja ujra!!\033[0m\n");
      break;
    }
    }
    while (switch_value != 0);
  }
