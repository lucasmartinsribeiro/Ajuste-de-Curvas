#include<stdio.h>
#include<stdlib.h>
#include <math.h>


#define COLUNA 2
#define TAM_VET_COEF 4

// MATRIZ DOS COEFICIENTES
#define N 3
#define L_MAT_COEF 3
#define C_MAT_COEF 4

// sinalizador das colunas
#define X 0
#define Y 1

// VETOR DAS RAÍZES DO SISTEMA LINEAR (PARABÓLICO)
#define TAM_VET_RAIZES 3
// ---------------------------------------------------------------------------------------------

//                                  FUNÇÕES QUE FAZEM A ROTINA
// LINEARAZIÇÃO
void criar_vetCoef(int escX, int escY, int tam,double *vetCoef,double matNum[][COLUNA]);
double log_natural(double valor, int esc);
double coef_linear_A0(int tam, double *vetCoef);
double coef_angular_A1(int tam, double *vetCoef);
// PARABÓLICO
void create_matCoef(int tam, double matCoef[L_MAT_COEF][C_MAT_COEF], double matNum[][COLUNA]);
void print_matriz_num(int tam,double matCoef[][COLUNA]);
void print_matriz(double matCoef[L_MAT_COEF][C_MAT_COEF]);
// SISTEMA LINEAR
void gauss(double matCoef[L_MAT_COEF][C_MAT_COEF],double vetor_A[TAM_VET_RAIZES]);


//                                  FUNÇÕES QUE INTERAGEM COM USUARIO

double equacao_linear(int tam, double matNum[][COLUNA]);
double equacao_expo(int tam, double matNum[][COLUNA]);
double equacao_log(int tam, double matNum[][COLUNA]);
double equacao_pote(int tam, double matNum[][COLUNA]);
double equacao_hiper(int tam, double matNum[][COLUNA]);
double equacao_curva(int tam, double matNum[][COLUNA]);



//                                 FUNÇÃO PARA CALCULAR O COEFICIENTE D PEARSON
double quali(int esc,int tam, double *vetCoef, double matNum[][COLUNA], double A0, double A1);



