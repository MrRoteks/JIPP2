#ifndef PROJEKT1_MATRIXLIB_H
#define PROJEKT1_MATRIXLIB_H

#include <iostream>

using namespace std;

void help();
void checkInput();

void printMatrix(double **wynik, int W, int K);
void printMatrix(int **wynik, int W, int K);

int addMatrix(int **a, int **b, int W, int K);
double addMatrix(double **a, double **b, int W, int K);

int subtractMatrix(int **a, int **b, int W, int K);
double subtractMatrix(double **a, double **b, int W, int K);

int multiplyMatrix(int **a, int **b, int Wa, int Ka, int Kb);
double multiplyMatrix(double **a, double **b, int Wa, int Ka, int Kb);

int multiplyByScalar(int **a, int Wa, int Ka, double s);
double multiplyByScalar(double **a, int Wa, int Ka, double s);

int transpozeMatrix(int **a, int Wa, int Ka);
double transpozeMatrix(double **a, int Wa, int Ka);

int powerMatrix(int **a, int Wa, int Ka, unsigned st);
double powerMatrix(double **a, int Wa, int Ka, unsigned st);

bool LUdecomposition(int n, double **a);
double determinantMatrix(double **a, int Wa, int Ka);
//tylko double ze wzgledu na dekompozycje lu gdzie jest dzielenie

bool matrixIsDiagonal(int **a, int Wa, int Ka);
bool matrixIsDiagonal(double **a, int Wa, int Ka);

void swap(double *a, double *b);

void swap(int *a, int *b);

int sortRow(int **a, int Ka);
double sortRow(double **a, int Ka);

int sortRowsInMatrix(int **a, int Wa, int Ka);
double sortRowsInMatrix(double **a, int Wa, int Ka);


#endif //PROJEKT1_MATRIXLIB_H
