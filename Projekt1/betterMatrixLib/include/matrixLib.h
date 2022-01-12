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
void printMatrix(float **wynik, int W, int K);

/**
 * printMatrix - wyświtela wskazaną macierz
 * @param wynik -tablica, w ktorej zawarta jest macierz
 * @param W - ilosc wierszy macierzy
 * @param K - ilosc kolumn w macierzy
 */
void printMatrix(long int **wynik, int W, int K);

/**
 * matrixAdd - dodaje 2 macierze
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param b - tablica, w ktorej zawarta jest macierz b
 * @param W - ilosc wierszy macierzy
 * @param K - ilosc kolumn w macierzy
 * @return - zwraca wskaźnik do pierwszej liczby w macierzy wynikowej
 */
long int **matrixAdd(long int **a, long int **b, int W, int K);

/**
 * matrixAdd - dodaje 2 macierze
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param b - tablica, w ktorej zawarta jest macierz b
 * @param W - ilosc wierszy macierzy
 * @param K - ilosc kolumn w macierzy
 * @return - zwraca wskaźnik do pierwszej liczby w macierzy wynikowej
 */
float **matrixAdd(float **a, float **b, int W, int K);

/**
 * matrixSubtract - odejmuje macierze
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param b - tablica, w ktorej zawarta jest macierz b
 * @param W - ilosc wierszy macierzy
 * @param K - ilosc kolumn w macierzy
 * @return - zwraca wskaźnik do pierwszej liczby w macierzy wyniowej
 */
long int **matrixSubtract(long int **a, long int **b, int W, int K);

/**
 * matrixSubtract - odejmuje macierze
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param b - tablica, w ktorej zawarta jest macierz b
 * @param W - ilosc wierszy macierzy
 * @param K - ilosc kolumn w macierzy
 * @return - zwraca wskaźnik do pierwszej liczby w macierzy wyniowej
 */
float **matrixSubtract(float **a, float **b, int W, int K);

/**
 * matrixMultiply - mnozy macierze
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param b - tablica, w ktorej zawarta jest macierz b
 * @param Wa - ilosc wierszy macierzy a
 * @param Ka - ilosc kolumn macierzy a
 * @param Kb - ilosc kolumn macierzy b
 * @return - zwraca wskaźnik do pierwszej liczby w macierzy wyniowej
 */
long int **matrixMultiply(long int **a, long int **b, int Wa, int Ka, int Kb);

/**
 * matrixMultiply - mnozy macierze
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param b - tablica, w ktorej zawarta jest macierz b
 * @param Wa - ilosc wierszy macierzy a
 * @param Ka - ilosc kolumn macierzy a
 * @param Kb - ilosc kolumn macierzy b
 * @return - zwraca wskaźnik do pierwszej liczby w macierzy wyniowej
 */
float **matrixMultiply(float **a, float **b, int Wa, int Ka, int Kb);

/**
 * matrixMultiplyByScalar -mnorzy macierz przez skalar
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Wa -ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @param s - skalar
 * @return - zwraca wskaźnik do pierwszej liczby w macierzy wyniowej
 */
long int **matrixMultiplyByScalar(long int **a, int Wa, int Ka, long int s);

/**
 * matrixMultiplyByScalar -mnorzy macierz przez skalar
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Wa -ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @param s - skalar
 * @return - zwraca wskaźnik do pierwszej liczby w macierzy wyniowej
 */
float **matrixMultiplyByScalar(float **a, int Wa, int Ka, float s);

/**
 * matrixTranspoze - transponuje macierz
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Wa - ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @return - zwraca wskaźnik do pierwszej liczby w macierzy wyniowej
 */
long int **matrixTranspoze(long int **a, int Wa, int Ka);

/**
 * matrixTranspoze - transponuje macierz
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Wa - ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @return - zwraca wskaźnik do pierwszej liczby w macierzy wyniowej
 */
float **matrixTranspoze(float **a, int Wa, int Ka);

/**
 * matrixPower - podnosi macierz do wskazanej potegi
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Wa - ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @param st - stopien potegi
 * @return - zwraca wskaźnik do pierwszej liczby w macierzy wyniowej
 */
long int **matrixPower(long int **a, int Wa, int Ka, unsigned short st);

/**
 * matrixPower - podnosi macierz do wskazanej potegi
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Wa - ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @param st - stopien potegi
 * @return - zwraca wskaźnik do pierwszej liczby w macierzy wyniowej
 */
float **matrixPower(float **a, int Wa, int Ka, unsigned short st);

/**
 * LUdecomposition -rozklad LU macierzy (do wyznacznika)
 * @param a -macierz do rozkladu
 * @param n -rozmiar macierzy (ilosc wierszy/kolumn - macierz musi byc kwadratowa)
 */
bool LUdecomposition(int n, float **a);

/**
 * matrixDeterminant - liczy wyznacznik macierzy
 * @param a - tablica, w ktorej zawarta jest macierz a (jest to tablica typu double ze wzgledu na dzielenie w rozkladzie LU)
 * @param Wa - ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @return - zwraca wyznacznik macierzy
 */
float matrixDeterminant(float **a, int Wa, int Ka);
//tylko double ze wzgledu na dekompozycje lu gdzie jest dzielenie

/**
 * matrixIsDiagonal - sprawdza czy macierz jest diagonalna
 * @param a -sprawdzana macierz
 * @param Wa -ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @return -zwraca watrosc "true" jesli macierz jest diagonalna lub wartosc "false" gdy nie jest diagonalna
 */
bool matrixIsDiagonal(long int **a, int Wa, int Ka);

/**
 * matrixIsDiagonal - sprawdza czy macierz jest diagonalna
 * @param a -sprawdzana macierz
 * @param Wa -ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @return -zwraca watrosc "true" jesli macierz jest diagonalna lub wartosc "false" gdy nie jest diagonalna
 */
bool matrixIsDiagonal(float **a, int Wa, int Ka);


/**
 * swap - zamienia dwie wartosci zmiennych miejscami
 * @param a
 * @param b
 */
void swap(long int *a, long int *b);

/**
 * swap - zamienia dwie wartosci zmiennych miejscami
 * @param a
 * @param b
 */
void swap(float *a, float *b);

/**
 * sortRow - sortuje pierwszy rzad w macierzy (rosnaco)
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Ka -ilosc kolumn w macierzy
 * @return - zwraca wskaznik do podanej marcierzy z posortowanym pierwszym rzedem macierzy
 */
long int **sortRow(long int **a, int Ka);

/**
 * sortRow - sortuje pierwszy rzad w macierzy (rosnaco)
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Ka -ilosc kolumn w macierzy
 * @return - zwraca wskaznik do podanej marcierzy z posortowanym pierwszym rzedem macierzy
 */
float **sortRow(float **a, int Ka);

/**
 * matrixSortRows -sortuje wszystkie rzedy macierzy (rosnaco)
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Wa -ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @return - zwraca wskaznik do marcierzy z posortowanymi rzedami
 */
long int **matrixSortRows(long int **a, int Wa, int Ka);

/**
 * matrixSortRows -sortuje wszystkie rzedy macierzy (rosnaco)
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Wa -ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @return - zwraca wskaznik do marcierzy z posortowanymi rzedami
 */
float **matrixSortRows(float **a, int Wa, int Ka);

//do zrobienia
/**
 * matrixGenerate - generuje losowa macierz
 * @param Wa - ilosc wierszy w macierzy
 * @param Ka - ilosc kolumn w macierzy
 * @param min - minimalna wartosc od ktorej losowane beda liczby
 * @param max - maksymalna wartosc do ktorej losowane beda liczby
 * @return - zwraca wskaznik do losowo wygenerowanej macierzy
 */
long int **matrixGenerate(int W, int K, long int min, long int max);

/**
 * matrixGenerate - generuje losowa macierz
 * @param Wa - ilosc wierszy w macierzy
 * @param Ka - ilosc kolumn w macierzy
 * @param min - minimalna wartosc od ktorej losowane beda liczby
 * @param max - maksymalna wartosc do ktorej losowane beda liczby
 * @return - zwraca wskaznik do losowo wygenerowanej macierzy
 */
float **matrixGenerate(int W, int K, float min, float max);

#endif //PROJEKT1_MATRIXLIB_H
