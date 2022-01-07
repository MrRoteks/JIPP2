#include <iostream>
#include "../include/matrixLib.h"
#include <iomanip>
#include<random>
#include <utility>
using namespace std;


void help()
{
    const char *pomoc ="                        MatrixCalculator - HELP:\n"
                       "           (Projekt1/cmake-build-debug/)/.betterMatrixApp [dzialanie] [dzialanie2]\n"
                       "    ----------------------------------------------------------------\n"
                       "                            Dzialania:                             \n"
                       "    matrixAdd - dodawanie dwoch macierzy\n"
                       "    matrixSubtract - odejmowanie dwoch macierzy \n"
                       "    matrixMultiply - mnozenie dwoch macierzy \n"
                       "    matrixMultiplyByScalar - mnozenie przez skalar \n"
                       "    matrixTranspoze - transponowanie macierzy \n"
                       "    matrixPower - potegowanie macierzy \n"
                       "    matrixDeterminant - wyznacznik macierzy \n"
                       "    matrixIsDiagonal - sprawdzanie, czy macierz jest diagonalna\n"
                       "    swap - zamienia liczby miejscami"
                       "    sortRow - sortowanie tablicy za pomoca sortowania bombelkowego \n"
                       "    matrixSortRows - sortowanie wszystkich wierszy w macierzy\n"
                       "    matrixGenerate - generuje losowa macierz"
                       "    generate - generuje losowa macierz do dzialania (musi zostac podany jako [dzialanie2])    "
                       "    help - wyswietla pomoc"
                       "    ----------------------------------------------------------------\n"
                       "                        Wczytywanie macierzy: \n"
                       "    Po podaniu odpowiedniego dzialania program poprosi o podanie typu macierzy, na ktorych chcemy wykonac dzialanie.\n"
                       "    Wpisujemy 1 dla macierzy typu \"int\" lub 2 dla macierzy typu \"double\" (bledny typ zatrzyma program)\n"
                       "    Nastepnie podajemy wiersze i kolumny macierzy pierwszej (a/A) oraz identycznie dla macierzy drugiej (b/B)\n"
                       "    Na koniec uzupelniamy macierze odpowiednimi wartosciami. \n"
                       "    Mozemy dodatkowo otrzymac zapytanie o dodatkowa wartosc np.skalar,potega\n"
                       "    (Wiersze, kolumny, wartosci w macierzy i inne sa wczytywane przez polecenie \"cin\",\n"
                       "    \t wiec mozemy wpisac wszystkie wartosci na raz - oddzielajac kazda wartosc spacja i zatwierdzic enterem)\n"
                       "    ----------------------------------------------------------------\n"
                       "                            Wynik dzialania: \n"
                       "    Program wyswietli nam wynik w postaci macierzy (lub liczby np. wyznacznik) \n"
                       "    oraz linijke nizej wyswietli wskaznik do wynik[0][0] \n"
                       "    (zwracana wartosc z funkcji, ze wzgledu na wybrane dzialanie mozemy jej nie otrzymac)\n"
                       "--------------------------KONIEC--------------------------------------\n";

    cout<<pomoc;
    exit(2);
}



void checkInput()
{
    if(cin.fail()==1)
    {
        cout<<"Bledna wartosc/typ danych.";
        exit(6);
    }
}



void printMatrix(double **wynik, int W, int K) {
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++) {
            cout << wynik[i][j] << "\t";
        }
        cout << endl;
    }
}

void printMatrix(int **wynik, int W, int K) {
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++) {
            cout << wynik[i][j] << "\t";
        }
        cout << endl;
    }
}



int **matrixAdd(int **a, int **b, int W, int K) {
    int **wynik = new int *[W];
    for (int i = 0; i < W; ++i)
        wynik[i] = new int[K];
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++) {
            wynik[i][j] = a[i][j] + b[i][j];
        }
    }
    printMatrix(wynik, W, K);

    return wynik;
}

double **matrixAdd(double **a, double **b, int W, int K) {
    double **wynik = new double *[W];
    for (int i = 0; i < W; ++i)
        wynik[i] = new double[K];
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++) {
            wynik[i][j] = a[i][j] + b[i][j];
        }
    }
    printMatrix(wynik, W, K);

    return wynik;
}



int **matrixSubtract(int **a, int **b, int W, int K) {
    int **wynik = new int *[W];
    for (int i = 0; i < W; ++i)
        wynik[i] = new int[K];
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++) {
            wynik[i][j] = a[i][j] - b[i][j];
        }
    }
    printMatrix(wynik, W, K);

    return wynik;
}

double **matrixSubtract(double **a, double **b, int W, int K) {
    double **wynik = new double *[W];
    for (int i = 0; i < W; ++i)
        wynik[i] = new double[K];
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++) {
            wynik[i][j] = a[i][j] - b[i][j];
        }
    }
    printMatrix(wynik, W, K);

    return wynik;
}



int **matrixMultiply(int **a, int **b, int Wa, int Ka, int Kb) {
    int j = 0, i = 0, n = 0;
    int **wynik = new int *[Wa];
    for (i = 0; i < Wa; ++i)
        wynik[i] = new int[Kb];

    for (i = 0; i < Wa; ++i)
        for (j = 0; j < Kb; ++j) {
            wynik[i][j] = 0;
        }

    for (i = 0; i < Wa; ++i)
        for (j = 0; j < Kb; ++j)
            for (n = 0; n < Ka; ++n) {
                wynik[i][j] += a[i][n] * b[n][j];
            }
    printMatrix(wynik, Wa, Kb);

    return wynik;

}

double **matrixMultiply(double **a, double **b, int Wa, int Ka, int Kb) {
    int j = 0, i = 0, n = 0;
    double **wynik = new double *[Wa];
    for (i = 0; i < Wa; ++i)
        wynik[i] = new double[Kb];

    for (i = 0; i < Wa; ++i)
        for (j = 0; j < Kb; ++j) {
            wynik[i][j] = 0;
        }

    for (i = 0; i < Wa; ++i)
        for (j = 0; j < Kb; ++j)
            for (n = 0; n < Ka; ++n) {
                wynik[i][j] += a[i][n] * b[n][j];
            }
    printMatrix(wynik, Wa, Kb);

    return wynik;

}



int **matrixMultiplyByScalar(int **a, int Wa, int Ka, double s) {
    int j = 0, i = 0, n = 0;
    int **wynik = new int *[Wa];
    for (i = 0; i < Wa; ++i)
        wynik[i] = new int[Ka];

    for (i = 0; i < Wa; ++i)
        for (j = 0; j < Ka; ++j) {
            wynik[i][j] = a[i][j] * s;
        }

    printMatrix(wynik, Wa, Ka);

    return wynik;
}

double **matrixMultiplyByScalar(double **a, int Wa, int Ka, double s) {
    int j = 0, i = 0, n = 0;
    double **wynik = new double *[Wa];
    for (i = 0; i < Wa; ++i)
        wynik[i] = new double[Ka];

    for (i = 0; i < Wa; ++i)
        for (j = 0; j < Ka; ++j) {
            wynik[i][j] = a[i][j] * s;
        }

    printMatrix(wynik, Wa, Ka);

    return wynik;
}



int **matrixTranspoze(int **a, int Wa, int Ka) {
    int j = 0, i = 0, n = 0;
    int **wynik = new int *[Ka];
    for (i = 0; i < Ka; ++i)
        wynik[i] = new int[Wa];

    for (i = 0; i < Wa; ++i)
        for (j = 0; j < Ka; ++j) {
             wynik[j][i] = a[i][j];
        }
    printMatrix(wynik, Ka, Wa);

    return wynik;
}

double **matrixTranspoze(double **a, int Wa, int Ka) {
    int j = 0, i = 0, n = 0;
    double **wynik = new double *[Ka];
    for (i = 0; i < Ka; ++i)
        wynik[i] = new double[Wa];

    for (i = 0; i < Wa; ++i)
        for (j = 0; j < Ka; ++j) {
            wynik[j][i] = a[i][j];
        }
    printMatrix(wynik, Ka, Wa);

    return wynik;
}



int **matrixPower(int **a, int Wa, int Ka, unsigned st) {
    int j = 0, i = 0, n = 0, d = 0, b = 0, k = 0, sum;
    int **wynik = new int *[Wa];
    for (i = 0; i < Wa; ++i)
        wynik[i] = new int[Ka];
    int **temp = new int *[Wa];
    for (i = 0; i < Wa; ++i)
        temp[i] = new int[Ka];

    if (st == 0) {
        for (i = 0; i < Wa; ++i)
            for (j = 0; j < Ka; ++j) {
                wynik[i][j] = 1;
            }
    } else {
        for (i = 0; i < Wa; ++i)
            for (j = 0; j < Ka; ++j) {
                wynik[i][j] = a[i][j];
                temp[i][j] = 0;
            }
        while (st > 1) {
            for (i = 0; i < Wa; ++i)
                for (j = 0; j < Ka; ++j)
                    for (n = 0; n < Ka; ++n) {                  // dlaczego? bo a^n = a^n-1*a
                        temp[i][j] += wynik[i][n] *
                                      a[n][j]; // dzialanie: "wynik" = a^m, temp =a^m*a -- powtorz st -1 razy, gdzie st-- i zapisz temp do wynikiu po pelnej iteracji
                    }                                           //za karzda iteracja zmienna wynik jest tym a^n-1  i dlatego nie mozemy odrazu zapisywac go jako wynik tylko poslugujemy sie temp
            for (i = 0; i < Wa; ++i)
                for (j = 0; j < Ka; ++j) {
                    wynik[i][j] = temp[i][j];
                    temp[i][j] = 0; // czyscimy temp zeby w nast iteracji nie zostały dodatkowe wartosci z poprzedniej (przy mnorzeniu macierzy dodajemy wartosci do komorek)
                }
            st--;
        }

    }
    printMatrix(wynik, Wa, Ka);

    return wynik;
}

double **matrixPower(double **a, int Wa, int Ka, unsigned st) {
    int j = 0, i = 0, n = 0, d = 0, b = 0, k = 0, sum;
    double **wynik = new double *[Wa];
    for (i = 0; i < Wa; ++i)
        wynik[i] = new double[Ka];
    double **temp = new double *[Wa];
    for (i = 0; i < Wa; ++i)
        temp[i] = new double[Ka];

    if (st == 0) {
        for (i = 0; i < Wa; ++i)
            for (j = 0; j < Ka; ++j) {
                wynik[i][j] = 1;
            }
    } else {
        for (i = 0; i < Wa; ++i)
            for (j = 0; j < Ka; ++j) {
                wynik[i][j] = a[i][j];
                temp[i][j] = 0;
            }
        while (st > 1) {
            for (i = 0; i < Wa; ++i)
                for (j = 0; j < Ka; ++j)
                    for (n = 0; n < Ka; ++n) {                  // dlaczego? bo a^n = a^n-1*a
                        temp[i][j] += wynik[i][n] *
                                      a[n][j]; // dzialanie: "wynik" = a^m, temp =a^m*a -- powtorz st -1 razy, gdzie st-- i zapisz temp do wynikiu po pelnej iteracji
                    }                                           //za karzda iteracja zmienna wynik jest tym a^n-1  i dlatego nie mozemy odrazu zapisywac go jako wynik tylko poslugujemy sie temp
            for (i = 0; i < Wa; ++i)
                for (j = 0; j < Ka; ++j) {
                    wynik[i][j] = temp[i][j];
                    temp[i][j] = 0; // czyscimy temp zeby w nast iteracji nie zostały dodatkowe wartosci z poprzedniej (przy mnorzeniu macierzy dodajemy wartosci do komorek)
                }
            st--;
        }

    }
    printMatrix(wynik, Wa, Ka);

    return wynik;
}



bool LUdecomposition(int n, double **a)
{
    int i, j, k;
    const double eps = 1e-12;
    for( k = 0; k < n - 1; k++ )
    {
        if( abs ( a[ k ][ k ] ) < eps )
            return false;

        for( i = k + 1; i < n; i++ ) {
            a[i][k] /= a[k][k];
        }
            for( i = k + 1; i < n; i++ )
            for( j = k + 1; j < n; j++ )
                a [ i ][ j ] -= a [ i ][ k ] * a [ k ][ j ];
    }
    return true;
}



double matrixDeterminant(double **a, int Wa, int Ka) {
    double det = 0;
    int n=Wa,i, j;
    cout << setprecision ( 4 ) << fixed;
    if( LUdecomposition( n, a ) )
    {
        det = a [ 0 ][ 0 ];
        for( i = 1; i < n; i++ )
            det *= a [ i ][ i ];
    }
    else
        cout << "DZIELNIK ZERO\n";

    return det;
}



bool matrixIsDiagonal(int **a, int Wa, int Ka)
{
    for(int i=0;i<Wa;i++)
        for(int j=0;j<Ka;j++)
        {
            if(a[i][j]!=0&&i!=j)
                return false;
        }
    return true;
}

bool matrixIsDiagonal(double **a, int Wa, int Ka)
{
    for(int i=0;i<Wa;i++)
        for(int j=0;j<Ka;j++)
        {
            if(a[i][j]!=0&&i!=j)
                return false;
        }
    return true;
}


void swap(double *a, double *b)
{
    double temp=*a;
    *a=*b;
    *b=temp;

}
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}



int **sortRow(int **a, int Ka)
{
    int temp=0;
    for (int i = 0; i < Ka-1; i++)

        // Last i elements are already in place
        for (int j = 0; j < Ka-i-1; j++)
            if (a[0][j] > a[0][j+1])
            {
                temp= a[0][j];
                a[0][j] = a[0][j+1];
                a[0][j+1] = temp;

            }
    for(int i=0;i<Ka;i++)
        cout<<a[0][i];
    cout<<endl;
    return a;
}

double **sortRow(double **a, int Ka)
{
    double temp=0;
    for (int i = 0; i < Ka-1; i++)

        // Last i elements are already in place
        for (int j = 0; j < Ka-i-1; j++)
            if (a[0][j] > a[0][j+1])
            {
                temp= a[0][j];
                a[0][j] = a[0][j+1];
                a[0][j+1] = temp;

            }
    for(int i=0;i<Ka;i++)
        cout<<a[0][i]<<" ";
    cout<<endl;
    return a;
}



int **matrixSortRows(int **a, int Wa, int Ka) {
    int temp = 0;
    for (int n = 0; n < Wa; n++)
        for (int i = 0; i < Ka - 1; i++)
            for (int j = 0; j < Ka - i - 1; j++)
                if (a[n][j] > a[n][j + 1]) {
                    temp = a[n][j];
                    a[n][j] = a[n][j + 1];
                    a[n][j + 1] = temp;
                }
    printMatrix(a, Wa, Ka);
    return a;
}

double **matrixSortRows(double **a, int Wa, int Ka) {
    double temp = 0;
    for (int n = 0; n < Wa; n++)
        for (int i = 0; i < Ka - 1; i++)
            for (int j = 0; j < Ka - i - 1; j++)
                if (a[n][j] > a[n][j + 1]) {
                    temp = a[n][j];
                    a[n][j] = a[n][j + 1];
                    a[n][j + 1] = temp;
                }
    printMatrix(a, Wa, Ka);
    return a;
}

int **matrixGenerate(int W, int K,int min,int max)
{
    int **wynik = new int *[W];
    for (int i = 0; i < W; ++i)
        wynik[i] = new int[K];
//stara metoda
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++) {
            wynik[i][j] =rand()%max+min;
        }
    }
    printMatrix(wynik, W, K);

    return wynik;
}
double **matrixGenerate (int W, int K, double m, double M)
{
    double **wynik = new double *[W];
    for (int i = 0; i < W; ++i)
        wynik[i] = new double[K];

//nowa metoda
    std::uniform_real_distribution<double> unif(m,M);
    std::default_random_engine re;
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++) {
            wynik[i][j]=unif(re);
        }
    }
    printMatrix(wynik, W, K);

    return wynik;
}
