#include <stdio.h>
#include "ajustes_curvas.h"

#define NUM 11



void converMatrix(double matNum[NUM][COLUNA]);


void ajustes()
{
    double numeros[NUM][COLUNA];
    converMatrix(numeros);
    
    double qualidade = equacao_linear(NUM,numeros);
    printf("Qualidade do ajuste linear: %lf\n",qualidade);
    
    printf("\n\n");

    qualidade = equacao_curva(NUM,numeros);
    printf("Qualidade do ajuste parabolico: %lf\n",qualidade);

    printf("\n\n");

    qualidade = equacao_expo(NUM,numeros);
    printf("Qualidade do ajuste exponencial: %lf\n",qualidade);
    
    printf("\n\n");

    qualidade = equacao_log(NUM,numeros);
    printf("Qualidade do ajuste logaritimico: %lf\n",qualidade);
    
    printf("\n\n");

    qualidade = equacao_pote(NUM,numeros);
    printf("Qualidade do ajuste potencial: %lf\n",qualidade);
    printf("\n\n");
    
    qualidade = equacao_hiper(NUM,numeros);
    printf("Qualidade do ajuste hiperbolico: %lf\n",qualidade);
}

int main()
{    
    ajustes();
}

void converMatrix(double matNum[NUM][COLUNA])
{
    //0,0.32,1,0.12,2,0.21,3,0.47,4,0.52,5,0.76,6,0.87,7,0.96
    double vetX[NUM]={1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 2.6, 2.8, 3};
    double vetY[NUM]={0.52500, 0.84478, 1.28068, 1.86340, 2.63260, 3.63856, 4.94400, 6.62580, 8.77679, 11.50759, 14.94844};


    for(int i=0;i<NUM;i++)
    {
        matNum[i][X]=vetX[i];
        matNum[i][Y]=vetY[i];
    }
}


