#include"ajustes_curvas.h"

// TAMANHO DO VETOR AUXILIAR
#define VET_AUX 11

// POSIÇÕES DO VETOR AUXILIAR
#define TAM 0
#define SOMA_X1 1
#define SOMA_X2 2
#define SOMA_X3 3
#define SOMA_X4 4

#define SOMA_Y1 5
#define SOMA_X_Y 6
#define SOMA_X2_Y 7

// ORGANIZAÇÃO DO VETOR DE RAÍZES
#define A0 0
#define A1 1
#define A2 2

//                            FUNÇÃO QUE INTERAGEM COM A FUNÇÃO main    
double equacao_curva(int tam, double matNum[][COLUNA]){
    double matrix_coef[L_MAT_COEF][C_MAT_COEF],vetorA[TAM_VET_RAIZES];
    //  printf("Chegamos aki pelo menos\n\n");
    create_matCoef(tam,matrix_coef,matNum);
    //print_matriz_num(tam,matNum);
    //printf("\n\n");
    //printf("passamos da função\n\n");
    //print_matriz(matrix_coef);
    //printf("\n\n");
    //double numeros[3][4] =  {2,1,1,8,1,1,4,15,3,2,9};
    //double numeros[3][4]={1,1,1,12,2,-1,2,12,1,-1,-3,-16};
    gauss(matrix_coef,vetorA);
    printf("Equacao da curva -> y = %lf +(%lf*x)+(%lf*(x^2))\n",vetorA[A0],vetorA[A1],vetorA[A2]);
    //gauss(numeros,vetorA);
}

//                            FUNÇÕES QUE CRIAM A MATRIZ DOS COEFICIENTES    
void create_matCoef(int tam, double matCoef[L_MAT_COEF][C_MAT_COEF], double matNum[][COLUNA]){
    int contJ=0,aux=0,contI=0,contAux=0;
    double vetAux[VET_AUX];
    matCoef[contI][contI]=tam;
    int contador=0,contador2=0;

    while(contador<VET_AUX){
        vetAux[contador]=0;
        contador++;
    }
    contador=0;
    while(contador<L_MAT_COEF){
        while(contador2<C_MAT_COEF)
        {    
            matCoef[contador][contador2]=0;
            contador2++;
        }
        contador++;
    }
    
    vetAux[contI]=tam;
    while(contI<tam){
        //soma de x
        vetAux[SOMA_X1]+=matNum[contI][X];
        // soma de x^2
        vetAux[SOMA_X2]+=pow(matNum[contI][X],2);
        // soma de x^3
        vetAux[SOMA_X3]+=pow(matNum[contI][X],3);
        // soma de x^4
        vetAux[SOMA_X4]+=pow(matNum[contI][X],4);
        // soma de y
        vetAux[SOMA_Y1]+=matNum[contI][Y];
        // soma de x*y
        vetAux[SOMA_X_Y]+=(matNum[contI][X]*matNum[contI][Y]);
        // soma de (x^2)*y
        vetAux[SOMA_X2_Y]+=(pow(matNum[contI][X],2)*matNum[contI][Y]);
        contI++;
    }
    printf("\n");
    //  printf("antes do segundo for\n\n");
    for(int i=0; i<L_MAT_COEF; i++){
        for(int j = 0 ; j < C_MAT_COEF ; j++){
            if(j==i && j<1){
                matCoef[i][j]=vetAux[TAM];
            }
            // printf("vetAux[TAM]=%d\n\n",vetAux[TAM]);
            if(i+j==1)
                matCoef[i][j]=vetAux[SOMA_X1];
            if(i+j==2)
                matCoef[i][j]=vetAux[SOMA_X2];
            if(i+j==3 && j<3)
                matCoef[i][j]=vetAux[SOMA_X3];
            if(i+j==4 && j<3)
                matCoef[i][j]=vetAux[SOMA_X4];
            if(i+j==3 && j==3)
                matCoef[i][j]=vetAux[SOMA_Y1];
            if(i+j==4 && j==3)
                matCoef[i][j]=vetAux[SOMA_X_Y];
            if(i+j==5 && j==3)
                matCoef[i][j]=vetAux[SOMA_X2_Y];
            //printf("Mat[%d][%d]=%lf\n\n",i,j,matCoef[i][j]);
        }
    }
}

//                       FUNÇÃO QUE RESOLVE O SISTEMA LINEAR POR ESCALONAMENTO
void gauss(double matCoef[L_MAT_COEF][C_MAT_COEF],double vetor_A[TAM_VET_COEF]){
    double multi=0,soma=0;
    // ESCALONAMENTO
    for(int j=0;j<TAM_VET_RAIZES-1;j++){
        for(int i=0;i<TAM_VET_RAIZES;i++){
            if(i>j){
                multi=-1*(matCoef[i][j]/matCoef[j][j]);
                for(int z=0;z<TAM_VET_COEF;z++){
                    matCoef[i][z]=(multi*matCoef[j][z])+matCoef[i][z];
                }
            }
            // v[1][]= (multi*mat[0][3])
        }
    }
    print_matriz(matCoef);
    vetor_A[TAM_VET_RAIZES-1]=(matCoef[TAM_VET_RAIZES-1][TAM_VET_RAIZES])/(matCoef[TAM_VET_RAIZES-1][TAM_VET_RAIZES-1]);
    printf("\nV[%d]->%lf\n",A2,vetor_A[A2]);
    for(int i=TAM_VET_RAIZES-2;i>=0;i--){
        soma=0;
        for(int j=i+1;j<=TAM_VET_RAIZES;j++){
            soma+=matCoef[i][j]*vetor_A[j];
        }
        vetor_A[i]=((matCoef[i][C_MAT_COEF-1])-soma)/matCoef[i][i];
    }
    printf("Raízes:  A0= %lf\n        A1=%lf\n        A2=%lf\n",vetor_A[A0],vetor_A[A1],vetor_A[A2]);
}

//                                          IMPRIMIR AS MATRIZES
void print_matriz(double matCoef[L_MAT_COEF][C_MAT_COEF]){
    for(int i=0;i<L_MAT_COEF;i++){
        for(int j=0;j<C_MAT_COEF;j++){
           printf("[%.2lf] ",matCoef[i][j]);
        }
        printf("\n");
    }
}
void print_matriz_num(int tam,double matCoef[][COLUNA]){
    for(int i=0;i<tam;i++){
        for(int j=0;j<COLUNA;j++){
           printf("[%.2lf] ",matCoef[i][j]);
        }
        printf("\n");
    }
}

/*
    for(int i=0;i<L_MAT_COEF;i++){
        contAux=0;
        for(int j=0;j<(C_MAT_COEF);j++){
            if(i+j==3)
                contAux++;
            if(j==i && j<1)
                matCoef[i][j]=vetAux[TAM];
            if(i>0 || j>0)
                matCoef[i][j]=vetAux[contAux+1]; printf("[%d][%d]\n",i,j);
            if(i==3){
                contAux=4;
                matCoef[i][j]=vetAux[contAux+1];
            }
        }
        aux++;
    }
*/