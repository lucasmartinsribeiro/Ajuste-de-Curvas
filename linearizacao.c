#include "ajustes_curvas.h"

// sinalizador da posição do vetor dos coeficientes

#define SOMA_X 0
#define SOMA_X2 1
#define SOMA_Y 2
#define SOMA_XY 3
//                                FUNÇÕES QUE INTERAGEM COM USUARIO


double equacao_linear(int tam, double matNum[][COLUNA])
{
    double vetNum[TAM_VET_COEF],A0=0,A1=0;
    int escX=0,escY=0;
    for(int i=0;i<TAM_VET_COEF;i++)
    {
        vetNum[i]=0;
    }
    criar_vetCoef(escX,escY,tam,vetNum,matNum);
    A0=coef_linear_A0(tam,vetNum);
    A1=coef_angular_A1(tam,vetNum);
    
    printf("\n");
    printf("EQUACAO LINEAR DA RETA  y= %lf + %lf*x\n",A0,A1);
    return quali(1,tam, matNum, A0, A1,0);
}

double equacao_expo(int tam, double matNum[][COLUNA])
{
    double vetNum[TAM_VET_COEF],A0=0,A1=0;
    int escX=0,escY=1;
    for(int i=0;i<TAM_VET_COEF;i++)
    {
        vetNum[i]=0;
    }
    criar_vetCoef(escX,escY,tam,vetNum,matNum);
    A0=(pow(2.71828,coef_linear_A0(tam,vetNum)));
    A1=coef_angular_A1(tam,vetNum);
    
    printf("\n");
    printf("EQUACAO EXPONENCIAL y= %lf * e^%lf*x\n",A0,A1);
    return quali(2,tam,matNum, A0, A1,0);
}

double equacao_log(int tam, double matNum[][COLUNA])
{
    double vetNum[TAM_VET_COEF],A0=0,A1=0;
    int escX=1,escY=0;
    for(int i=0;i<TAM_VET_COEF;i++)
    {
        vetNum[i]=0;
    }
    criar_vetCoef(escX,escY,tam,vetNum,matNum);
    A0=coef_linear_A0(tam,vetNum);
    A1=coef_angular_A1(tam,vetNum);
    
    printf("\n");
    printf("EQUACAO LOGARITIMICA y= %lf + %lf*ln(x)\n",A0,A1);
    return quali(3,tam, matNum, A0, A1,0);
}

double equacao_pote(int tam, double matNum[][COLUNA])
{
    double vetNum[TAM_VET_COEF],A0=0,A1=0;
    int escX=1,escY=1;
    for(int i=0;i<TAM_VET_COEF;i++)
    {
        vetNum[i]=0;
    }
    criar_vetCoef(escX,escY,tam,vetNum,matNum);
    A0=(pow(2.71828,coef_linear_A0(tam,vetNum)));
    A1=coef_angular_A1(tam,vetNum);
    
    printf("\n");
    printf("EQUACAO POTENCIAL y= %lf*x^%lf\n",A0,A1);
    return quali(4,tam, matNum, A0, A1,0);
}

double equacao_hiper(int tam, double matNum[][COLUNA])
{
    double vetNum[TAM_VET_COEF],A0=0,A1=0;
    int escX=2,escY=0;
    for(int i=0;i<TAM_VET_COEF;i++)
    {
        vetNum[i]=0;
    }
    criar_vetCoef(escX,escY,tam,vetNum,matNum);
    A0=coef_linear_A0(tam,vetNum);
    A1=coef_angular_A1(tam,vetNum);
    
    printf("\n");
    printf("EQUACAO HIPERBOLICO  y= %lf + %lf/x\n",A0,A1);
    return quali(5,tam, matNum, A0, A1,0);
}

//                                FUNÇÕES DE LINEARIZAÇÃO
double log_natural(double valor, int esc)
{
    if(esc==0)
    {
        return valor;
    } else
        if(esc==2)
        {
            return 1/valor;
        } else {
            return log(valor);
        }
}

void criar_vetCoef(int escX, int escY,int tam,double *vetCoef,double matNum[][COLUNA])
{
    for(int i=0;i<tam;i++)
    {
        vetCoef[SOMA_X] += log_natural(matNum[i][X], escX);
        vetCoef[SOMA_X2] += pow(log_natural(matNum[i][X],escX),2);
       
        vetCoef[SOMA_Y] += log_natural(matNum[i][Y],escY);
        vetCoef[SOMA_XY] += log_natural(matNum[i][X],escX)*(log_natural(matNum[i][Y],escY));

    }
}

double coef_linear_A0(int tam, double *vetCoef)
{
    double numerador=0,denominador=0;
    numerador=((vetCoef[SOMA_X2]*vetCoef[SOMA_Y]) - (vetCoef[SOMA_X]*vetCoef[SOMA_XY]));
    denominador=((tam*vetCoef[SOMA_X2]) - (pow(vetCoef[SOMA_X],2)));
    return numerador/denominador;
}

double coef_angular_A1(int tam, double *vetCoef)
{
    double numerador=0,denominador=0;
    numerador=((tam*vetCoef[SOMA_XY]) - (vetCoef[SOMA_X]*vetCoef[SOMA_Y]));
    denominador = ((tam*vetCoef[SOMA_X2]) - (pow(vetCoef[SOMA_X],2)));
    return numerador/denominador;
}

// 1 - linear, 2- expo, 3 - log, 4 - pote, 5 - hiper e 6 - Parabólico
double quali(int esc,int tam,double matNum[][COLUNA], double A0, double A1, double A2)
{
    double Yaj=0,vetYaj[3]={0,0,0},numerador=0,denominador=0;
    int soma_Yaj=0,soma_Yaj_Y=1,soma_Y2=2;
    for(int i=0; i<tam;i++)
    {
       // 1 - linear
        if(esc==1)
        {
            Yaj=A0+A1*(matNum[i][X]);
            // y = a +bx
            vetYaj[soma_Yaj] += Yaj;
            vetYaj[soma_Yaj_Y]+=pow(matNum[i][Y]-Yaj,2);
            vetYaj[soma_Y2]+=pow(matNum[i][Y],2);
        }
       // 2- expo
        if(esc==2)
        {
            Yaj=log(A0*pow(2.71828,(A1*(matNum[i][X]))));
            vetYaj[soma_Yaj] += Yaj;
            vetYaj[soma_Yaj_Y]+=(pow((log(matNum[i][Y])-Yaj),2));
            //printf("Yaj= %lf    matnum[%d][%d]=%lf      sub=%lf\n",Yaj,i,Y,matNum[i][Y],vetYaj[soma_Yaj_Y]);
            vetYaj[soma_Y2]+=pow(log(matNum[i][Y]),2);
        }
        //3 - log
        if(esc==3)
        {
            Yaj=A0+A1*log(matNum[i][X]);
            vetYaj[soma_Yaj] += Yaj;
            vetYaj[soma_Yaj_Y]+=pow((matNum[i][Y]-Yaj),2);
           // printf("Yaj= %lf    matnum[%d][%d]=%lf      sub=%lf\n",Yaj,i,Y,matNum[i][Y],vetYaj[soma_Yaj_Y]);
            vetYaj[soma_Y2]+=pow(matNum[i][Y],2);
        }
        //4 - pote
        if(esc==4)
        {
            Yaj=A0*(pow(matNum[i][X],A1));
            vetYaj[soma_Yaj] += log(Yaj);
            vetYaj[soma_Yaj_Y]+=pow((log(matNum[i][Y])-log(Yaj)),2);
            //printf("Yaj= %lf    matnum[%d][%d]=%lf      sub=%lf\nlog(%lf)-%lf=%lf\n\n",Yaj,i,Y,matNum[i][Y],vetYaj[soma_Yaj_Y],log(matNum[i][Y]),vetYaj[soma_Yaj],(pow((log(matNum[i][Y])-Yaj),2)));
            vetYaj[soma_Y2]+=pow(log(matNum[i][Y]),2);
        }
        //5 - hiper
        if(esc==5)
        {
            Yaj=A0+A1/(matNum[i][X]);
            vetYaj[soma_Yaj] += Yaj;
            vetYaj[soma_Yaj_Y]+=pow((matNum[i][Y]-Yaj),2);
            vetYaj[soma_Y2]+=pow(matNum[i][Y],2);
        }
        if(esc==6)
        {
            Yaj=A0+(A1*(matNum[i][X]))+(A2*pow((matNum[i][X]),2));
            // y = a +bx
            vetYaj[soma_Yaj] += Yaj;
            vetYaj[soma_Yaj_Y]+=pow(matNum[i][Y]-Yaj,2);
            vetYaj[soma_Y2]+=pow(matNum[i][Y],2);
        }
    }
    numerador=(tam*vetYaj[soma_Yaj_Y]);
    denominador=((tam*vetYaj[soma_Y2]-pow(vetYaj[soma_Yaj],2)));
    return 1-(numerador/denominador);
}