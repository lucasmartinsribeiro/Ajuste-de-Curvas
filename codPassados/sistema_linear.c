//#include"ajustes_curvas.h"


#define A0 0
#define A1 1
#define A2 2

void gauss(double matCoef[L_MAT_COEF][C_MAT_COEF],double vetor_A[TAM_VET_COEF])
{
    double multi=0,soma=0;
   // print_matriz(L_MAT_COEF,matCoef);
    for(int j=0;j<TAM_VET_RAIZES-1;j++)
    {
        for(int i=0;i<TAM_VET_RAIZES;i++)
        {
            if(i>j)
            {
                multi=-(matCoef[i][j]/matCoef[j][j]);
                for(int z=0;z<TAM_VET_COEF+1;z++)
                {
                    matCoef[i][z]=(multi*matCoef[j][z])+matCoef[i][z];
                }
            }
        }
    }
    print_matriz(matCoef);
    vetor_A[TAM_VET_RAIZES-1]=(matCoef[TAM_VET_RAIZES-1][TAM_VET_RAIZES])/(matCoef[TAM_VET_RAIZES-1][TAM_VET_RAIZES-1]);
    printf("\nV[%d]->%lf\n",A2,vetor_A[A2]);
    for(int i=TAM_VET_RAIZES-2;i>=0;i--)
    {
        soma=0;
        for(int j=i+1;j<=TAM_VET_RAIZES;j++)
        {
            soma+=matCoef[i][j]*vetor_A[j];
        }
        vetor_A[i]=((matCoef[i][C_MAT_COEF-1])-soma)/matCoef[i][i];
    }
    printf("teste:  A0= %lf\n        A1=%lf\n        A2=%lf\n",vetor_A[A0],vetor_A[A1],vetor_A[A2]);
}