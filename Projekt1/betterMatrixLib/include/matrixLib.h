#ifndef PROJEKT1_MATRIXLIB_H
#define PROJEKT1_MATRIXLIB_H

#include <iostream>

using namespace std;

/**
 * help - wyswietla pomocnicze informacje dotyczace programu
 */
void help();

/**
 * checkInput - sprawdza czy urzytkownik nie podal zlych danych (np. litery zamiast liczby)
 */
void checkInput();

/**
 * printMatrix - wyświtela wskazaną macierz
 * @param wynik -tablica, w ktorej zawarta jest macierz
 * @param W - ilosc wierszy macierzy
 * @param K - ilosc kolumn w macierzy
 */
void printMatrix(double **wynik, int W, int K);
/**
 * printMatrix - wyświtela wskazaną macierz
 * @param wynik -tablica, w ktorej zawarta jest macierz
 * @param W - ilosc wierszy macierzy
 * @param K - ilosc kolumn w macierzy
 */
void printMatrix(int **wynik, int W, int K);

/**
 * matrixAdd - dodaje 2 macierze
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param b - tablica, w ktorej zawarta jest macierz b
 * @param W - ilosc wierszy macierzy
 * @param K - ilosc kolumn w macierzy
 * @return - zwraca wskaźnik do pierwszej liczby w macierzy wynikowej
 */
int **matrixAdd(int **a, int **b, int W, int K);
/**
 * matrixAdd - dodaje 2 macierze
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param b - tablica, w ktorej zawarta jest macierz b
 * @param W - ilosc wierszy macierzy
 * @param K - ilosc kolumn w macierzy
 * @return - zwraca wskaźnik do pierwszej liczby w macierzy wynikowej
 */
double **matrixAdd(double **a, double **b, int W, int K);

/**
 * matrixSubtract - odejmuje macierze
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param b - tablica, w ktorej zawarta jest macierz b
 * @param W - ilosc wierszy macierzy
 * @param K - ilosc kolumn w macierzy
 * @return - zwraca wskaźnik do pierwszej liczby w macierzy wyniowej
 */
int **matrixSubtract(int **a, int **b, int W, int K);
/**
 * matrixSubtract - odejmuje macierze
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param b - tablica, w ktorej zawarta jest macierz b
 * @param W - ilosc wierszy macierzy
 * @param K - ilosc kolumn w macierzy
 * @return - zwraca wskaźnik do pierwszej liczby w macierzy wyniowej
 */
double **matrixSubtract(double **a, double **b, int W, int K);

/**
 * matrixMultiply - mnozy macierze
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param b - tablica, w ktorej zawarta jest macierz b
 * @param Wa - ilosc wierszy macierzy a
 * @param Ka - ilosc kolumn macierzy a
 * @param Kb - ilosc kolumn macierzy b
 * @return - zwraca wskaźnik do pierwszej liczby w macierzy wyniowej
 */
int **matrixMultiply (int **a, int **b, int Wa, int Ka, int Kb);
/**
 * matrixMultiply - mnozy macierze
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param b - tablica, w ktorej zawarta jest macierz b
 * @param Wa - ilosc wierszy macierzy a
 * @param Ka - ilosc kolumn macierzy a
 * @param Kb - ilosc kolumn macierzy b
 * @return - zwraca wskaźnik do pierwszej liczby w macierzy wyniowej
 */
double **matrixMultiply (double **a, double **b, int Wa, int Ka, int Kb);

/**
 * matrixMultiplyByScalar -mnorzy macierz przez skalar
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Wa -ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @param s - skalar
 * @return - zwraca wskaźnik do pierwszej liczby w macierzy wyniowej
 */
int **matrixMultiplyByScalar (int **a, int Wa, int Ka, double s);
/**
 * matrixMultiplyByScalar -mnorzy macierz przez skalar
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Wa -ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @param s - skalar
 * @return - zwraca wskaźnik do pierwszej liczby w macierzy wyniowej
 */
double **matrixMultiplyByScalar (double **a, int Wa, int Ka, double s);

/**
 * matrixTranspoze - transponuje macierz
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Wa - ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @return - zwraca wskaźnik do pierwszej liczby w macierzy wyniowej
 */
int **matrixTranspoze (int **a, int Wa, int Ka);
/**
 * matrixTranspoze - transponuje macierz
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Wa - ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @return - zwraca wskaźnik do pierwszej liczby w macierzy wyniowej
 */
double **matrixTranspoze  (double **a, int Wa, int Ka);

/**
 * matrixPower - podnosi macierz do wskazanej potegi
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Wa - ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @param st - stopien potegi
 * @return - zwraca wskaźnik do pierwszej liczby w macierzy wyniowej
 */
int **matrixPower (int **a, int Wa, int Ka, unsigned st);
/**
 * matrixPower - podnosi macierz do wskazanej potegi
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Wa - ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @param st - stopien potegi
 * @return - zwraca wskaźnik do pierwszej liczby w macierzy wyniowej
 */
double **matrixPower (double **a, int Wa, int Ka, unsigned st);

/**
 * LUdecomposition -rozklad LU macierzy (do wyznacznika)
 * @param a -macierz do rozkladu
 * @param n -rozmiar macierzy (ilosc wierszy/kolumn - macierz musi byc kwadratowa)
 */
bool LUdecomposition(int n, double **a);
/**
 * matrixDeterminant - liczy wyznacznik macierzy
 * @param a - tablica, w ktorej zawarta jest macierz a (jest to tablica typu double ze wzgledu na dzielenie w rozkladzie LU)
 * @param Wa - ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @return - zwraca wyznacznik macierzy
 */
double matrixDeterminant (double **a, int Wa, int Ka);
//tylko double ze wzgledu na dekompozycje lu gdzie jest dzielenie

/**
 * matrixIsDiagonal - sprawdza czy macierz jest diagonalna
 * @param a -sprawdzana macierz
 * @param Wa -ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @return -zwraca watrosc "true" jesli macierz jest diagonalna lub wartosc "false" gdy nie jest diagonalna
 */
bool matrixIsDiagonal(int **a, int Wa, int Ka);
/**
 * matrixIsDiagonal - sprawdza czy macierz jest diagonalna
 * @param a -sprawdzana macierz
 * @param Wa -ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @return -zwraca watrosc "true" jesli macierz jest diagonalna lub wartosc "false" gdy nie jest diagonalna
 */
bool matrixIsDiagonal(double **a, int Wa, int Ka);


/**
 * swap - zamienia dwie wartosci zmiennych miejscami
 * @param a
 * @param b
 */
void swap(int *a, int *b);
/**
 * swap - zamienia dwie wartosci zmiennych miejscami
 * @param a
 * @param b
 */
void swap(double *a, double *b);

/**
 * sortRow - sortuje pierwszy rzad w macierzy (rosnaco)
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Ka -ilosc kolumn w macierzy
 * @return - zwraca wskaznik do podanej marcierzy z posortowanym pierwszym rzedem macierzy
 */
int **sortRow(int **a, int Ka);
/**
 * sortRow - sortuje pierwszy rzad w macierzy (rosnaco)
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Ka -ilosc kolumn w macierzy
 * @return - zwraca wskaznik do podanej marcierzy z posortowanym pierwszym rzedem macierzy
 */
double **sortRow(double **a, int Ka);

/**
 * matrixSortRows -sortuje wszystkie rzedy macierzy (rosnaco)
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Wa -ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @return - zwraca wskaznik do marcierzy z posortowanymi rzedami
 */
int **matrixSortRows (int **a, int Wa, int Ka);
/**
 * matrixSortRows -sortuje wszystkie rzedy macierzy (rosnaco)
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Wa -ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @return - zwraca wskaznik do marcierzy z posortowanymi rzedami
 */
double **matrixSortRows (double **a, int Wa, int Ka);

//do zrobienia
/**
 * matrixGenerate - generuje losowa macierz
 * @param Wa - ilosc wierszy w macierzy
 * @param Ka - ilosc kolumn w macierzy
 * @param min - minimalna wartosc od ktorej losowane beda liczby
 * @param max - maksymalna wartosc do ktorej losowane beda liczby
 * @return - zwraca wskaznik do losowo wygenerowanej macierzy
 */
int **matrixGenerate(int W, int K,int min,int max);
/**
 * matrixGenerate - generuje losowa macierz
 * @param Wa - ilosc wierszy w macierzy
 * @param Ka - ilosc kolumn w macierzy
 * @param min - minimalna wartosc od ktorej losowane beda liczby
 * @param max - maksymalna wartosc do ktorej losowane beda liczby
 * @return - zwraca wskaznik do losowo wygenerowanej macierzy
 */
double **matrixGenerate (int W, int K, double min, double max);
#endif //PROJEKT1_MATRIXLIB_H
