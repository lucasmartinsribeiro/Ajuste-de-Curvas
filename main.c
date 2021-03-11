#include <stdio.h>
#include "ajustes_curvas.h"

#define NUM 8
void todos_ajustes();

void teste (double a,int teste)
{
    printf("%lf\n",a);
    int aux = teste;
    printf("%d\n",aux);
}
void ajustes()
{
    //int const NUM = 8;
    //double numeros[NUM][COLUNA]={-2,-30.5,-1.5,-20.2,0,-3.3,1,8.9,2.2,16.8,3.1,21.4};
    double numeros[NUM][COLUNA]={0,0.32,  1,0.12,  2,0.21,  3,0.47,  4,0.52,  5,0.76,  6,0.87,  7,0.96};
    //double numeros[NUM][COLUNA] = {1, 0.52500, 1.2, 0.84478  ,1.4 , 1.28068 , 1.6,1.86340 ,1.8,2.63260 ,2 , 3.63856,2.2,4.94400,2.4 ,6.62580,2.6,8.77679 ,2.8 ,11.50759 ,3, 14.94844};
    equacao_curva(NUM,numeros);
    double qualidade = equacao_linear(NUM,numeros);
    printf("Qualidade do ajuste linear: %lf\n",qualidade);
    
    qualidade = equacao_expo(NUM,numeros);
    printf("Qualidade do ajuste expo: %lf\n",qualidade);

    qualidade = equacao_log(NUM,numeros);
    printf("Qualidade do ajuste logarítimico: %lf\n",qualidade);

    qualidade = equacao_pote(NUM,numeros);
    printf("Qualidade do ajuste potencial: %lf\n",qualidade);

    qualidade = equacao_hiper(NUM,numeros);
    printf("Qualidade do ajuste hiperbólico: %lf\n",qualidade);
}
int main()
{    
    //double numeros[NUM][COLUNA] = {1, 0.52500, 1.2, 0.84478  ,1.4 , 1.28068 , 1.6,1.86340 ,1.8,2.63260 ,2 , 3.63856,2.2,4.94400,2.4 ,6.62580,2.6,8.77679 ,2.8 ,11.50759 ,3, 14.94844};
    //double numeros[NUM][COLUNA] = {10,2,15,7,20,16,25,26,30,37,40,57,50,73,60,84,70,92,80,99,90,104,100,108};
    ajustes();
    
}

