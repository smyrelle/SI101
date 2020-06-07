#include <stdio.h>
#include <math.h>

int dias (int a);   //Prot�tipo da fun��o
int N(int a);       //Prot�tipo da fun��o

int main ()
{
    char *meses[]=
{
    "Janeiro","Fevereiro","Marco",
    "Abril","Maio","Junho",
    "Julho","Agosto","Setembro",
    "Outubro","Novembro","Dezembro"
};

    int Y, sum, dia_sem, dia=0, mesDia=0;
    int b=0, i, j=0, linhas;
    int mes[12] ={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    scanf ("%d", &Y);   //Y - Ano
    printf ("\n%d", dias(Y));
    printf ("\n%d", N(Y));

    if ((dias(Y)) == 365){
        if (N(Y)==31)
         sum = 58+(N(Y));

        else
         sum = 89+(N(Y));
    }

    else{
        mes[1] = 29;
        if (N(Y)==31)
            sum = 59+(N(Y));

        else
            sum = 90+(N(Y));
    }

    switch (sum%7)
    {
     case 0: dia_sem=0; break; //domingo
     case 6: dia_sem=1; break; //segunda
     case 5: dia_sem=2; break; //terca
     case 4: dia_sem=3; break; //quarta
     case 3: dia_sem=4; break; //quinta
     case 2: dia_sem=5; break; //sexta
     case 1: dia_sem=6; break; //sabado
    }

    printf("\nCalendario do ano %d", Y);
    printf("\n|-----------------------------|\n");
    for (i = 0; i < 12; i++) { // Contagem mes
        printf("|%-29s|\n", meses[i]);
        printf("|-----------------------------|\n");
        printf("| dom seg ter qua qui sex sab |\n");
        printf("|");

        linhas = 0;

        
        for (j=0 ; j < dia_sem; j++) {
            printf("  --");
            dia++;
        }

        for (mesDia=1; mesDia <= mes[b]; mesDia++){   
            printf("  %02d", mesDia);
            if (dia >= 6){
                printf(" |\n|");
                linhas ++;
                dia = 0;                
            }else dia ++;
        }

        dia_sem = dia;
        while(linhas < 6){
            linhas ++; 
            while (dia <= 6){
                printf("  --");
                dia ++;
            }  
            printf(" |\n|");
            dia = 0;
        }
        printf("-----------------------------|\n");
        dia = 0; 
        b ++;
    }

    return 0;
}
  

int dias(int a){

   int ANO = a, rest, dias;
    rest = ANO%100;

   if (rest==0)
    ANO /= 100;

    rest = ANO%4;

   if (rest == 0)
    return dias = 366;

   else
    return dias = 365;

}

int N(int a)
{

   int G = (a%19)+1;                 //G - N�mero �ureo
   int C = (a/100)+1;                //C - S�culo
   int X = ((3*C)/4)-12;             //X - Fator de corre��o 1
   int Z = (((8*C) + 5)/25)-5;       //Z - Fator de corre��o 2
   int E = ((11*G) + 20 + Z - X)%30; //E - Epacta

   if (((E == 25) && (G>11)) || (E == 24))
        E += 1;

   int N = 44 - E;  //N - Lua cheia

   if (N < 21)
        N += 30;

   int D = ((5*a)/4) - (X+10);  //D - Domingo de P�scoa
   N = (N + 7) - ((D+N) % 7);

   if (N> 31)
    {
    return N -= 31;
    }

   else
    return N;
}
