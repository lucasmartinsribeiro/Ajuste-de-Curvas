//#include"ajustes_curvas.h"

double equacao_curva(int tam, double matNum[][COLUNA]);
void create_matCoef(int tam, double matCoef[L_MAT_COEF][C_MAT_COEF], double matNum[][COLUNA]);
void print_matriz(int tam, double matCoef[L_MAT_COEF][C_MAT_COEF]);


double equacao_curva(int tam, double matNum[][COLUNA])
{
    double matrix_coef[C_MAT_COEF][L_MAT_COEF];
    create_matCoef(tam,matrix_coef,matNum);
    print_matriz(tam,matrix_coef);
}

void create_matCoef(int tam, double matCoef[L_MAT_COEF][C_MAT_COEF], double matNum[][COLUNA])
{
    int contI=0,contAux=0,vetAux[VET_AUX];
    matCoef[contI][contI]=tam;
    while(contI<VET_AUX)
    {
        vetAux[contI]=0;
        matCoef[contI][X]=0;
        matCoef[contI][Y]=0;
    }
    contI=0;
    vetAux[contI]=tam;
    while(contI<tam)
    {
        //soma de x
        vetAux[SOMA_X1]+=matNum[contI][X];
        // soma de x^2
        vetAux[SOMA_X2]+=pow(matNum[contI][X],2);
        // soma de x^3
        vetAux[SOMA_X3]+=pow(matNum[contI][X],3);
        // soma de x^4
        vetAux[SOMA_X4]+=pow(matNum[contI][X],4);
        // soma de y
        vetAux[SOMA_Y]+=matNum[contI][Y];
        // soma de x*y
        vetAux[SOMA_X_Y]+=(matNum[contI][X]*matNum[contI][Y]);
        // soma de (x^2)*y
        vetAux[SOMA_X2_Y]+=(pow(matNum[contI][X],2)*matNum[contI][Y]);
        contI++;
    }
    for(int i=0;i<C_MAT_COEF-1;i++)
    {
        contAux=0;
        for(int j=0;j<(L_MAT_COEF);j++)
        {
            if(i==(C_MAT_COEF-1))
            {
                contAux++;
            }
            if(j==i && j<1)
                matCoef[j][i]=vetAux[TAM];
            if(i>0 || j>0)
            {
                matCoef[j][i]=vetAux[contAux+1];
                contAux++;
            }
        }
    }
}

void print_matriz(int tam, double matCoef[L_MAT_COEF][C_MAT_COEF])
{
    for(int i=0;i<L_MAT_COEF;i++)
    {
        for(int j=0;j<C_MAT_COEF;j++)
        {
            printf("mat[%d][%d] = %lf\n",i,j,matCoef[i][j]);
        }
        printf("\n");
    }
}