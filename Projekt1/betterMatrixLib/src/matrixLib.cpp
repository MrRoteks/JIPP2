#include <iostream>
#include "../include/matrixLib.h"
#include <iomanip>
#include<random>
#include <utility>

using namespace std;


void help() {
    const char *pomoc = "                        MatrixCalculator - HELP:\n"
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

    cout << pomoc;
    exit(2);
}


void checkInput() {
    if (cin.fail() == 1) {
        cout << "Bledna wartosc/typ danych.";
        exit(6);
    }
}


void printMatrix(float **wynik, int W, int K) {
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++) {
            cout << wynik[i][j] << "\t";
        }
        cout << endl;
    }
}

void printMatrix(long int **wynik, int W, int K) {
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++) {
            cout << wynik[i][j] << "\t";
        }
        cout << endl;
    }
}


long int **matrixAdd(long int **a, long int **b, int W, int K) {
    long int **wynik = new long int *[W];
    for (int i = 0; i < W; ++i)
        wynik[i] = new long int[K];
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++) {
            wynik[i][j] = a[i][j] + b[i][j];
        }
    }
    printMatrix(wynik, W, K);

    return wynik;
}

float **matrixAdd(float **a, float **b, int W, int K) {
    float **wynik = new float *[W];
    for (int i = 0; i < W; ++i)
        wynik[i] = new float[K];
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++) {
            wynik[i][j] = a[i][j] + b[i][j];
        }
    }
    printMatrix(wynik, W, K);

    return wynik;
}


long int **matrixSubtract(long int **a, long int **b, int W, int K) {
    long int **wynik = new long int *[W];
    for (int i = 0; i < W; ++i)
        wynik[i] = new long int[K];
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++) {
            wynik[i][j] = a[i][j] - b[i][j];
        }
    }
    printMatrix(wynik, W, K);

    return wynik;
}

float **matrixSubtract(float **a, float **b, int W, int K) {
    float **wynik = new float *[W];
    for (int i = 0; i < W; ++i)
        wynik[i] = new float[K];
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++) {
            wynik[i][j] = a[i][j] - b[i][j];
        }
    }
    printMatrix(wynik, W, K);

    return wynik;
}


long int **matrixMultiply(long int **a, long int **b, int Wa, int Ka, int Kb) {
    int j = 0, i = 0, n = 0;
    long int **wynik = new long int *[Wa];
    for (i = 0; i < Wa; ++i)
        wynik[i] = new long int[Kb];

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

float **matrixMultiply(float **a, float **b, int Wa, int Ka, int Kb) {
    int j = 0, i = 0, n = 0;
    float **wynik = new float *[Wa];
    for (i = 0; i < Wa; ++i)
        wynik[i] = new float[Kb];

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


long int **matrixMultiplyByScalar(long int **a, int Wa, int Ka, long int s) {
    int j = 0, i = 0, n = 0;
    long int **wynik = new long int *[Wa];
    for (i = 0; i < Wa; ++i)
        wynik[i] = new long int[Ka];

    for (i = 0; i < Wa; ++i)
        for (j = 0; j < Ka; ++j) {
            wynik[i][j] = a[i][j] * s;
        }

    printMatrix(wynik, Wa, Ka);

    return wynik;
}

float **matrixMultiplyByScalar(float **a, int Wa, int Ka, float s) {
    int j = 0, i = 0, n = 0;
    float **wynik = new float *[Wa];
    for (i = 0; i < Wa; ++i)
        wynik[i] = new float[Ka];

    for (i = 0; i < Wa; ++i)
        for (j = 0; j < Ka; ++j) {
            wynik[i][j] = a[i][j] * s;
        }

    printMatrix(wynik, Wa, Ka);

    return wynik;
}


long int **matrixTranspoze(long int **a, int Wa, int Ka) {
    int j = 0, i = 0, n = 0;
    long int **wynik = new long int *[Ka];
    for (i = 0; i < Ka; ++i)
        wynik[i] = new long int[Wa];

    for (i = 0; i < Wa; ++i)
        for (j = 0; j < Ka; ++j) {
            wynik[j][i] = a[i][j];
        }
    printMatrix(wynik, Ka, Wa);

    return wynik;
}

float **matrixTranspoze(float **a, int Wa, int Ka) {
    int j = 0, i = 0, n = 0;
    float **wynik = new float *[Ka];
    for (i = 0; i < Ka; ++i)
        wynik[i] = new float[Wa];

    for (i = 0; i < Wa; ++i)
        for (j = 0; j < Ka; ++j) {
            wynik[j][i] = a[i][j];

        }
    printMatrix(wynik, Ka, Wa);

    return wynik;
}


long int **matrixPower(long int **a, int Wa, int Ka, unsigned short st) {
    int j = 0, i = 0, n = 0, d = 0, b = 0, k = 0, sum;
    long int **wynik = new long int *[Wa];
    for (i = 0; i < Wa; ++i)
        wynik[i] = new long int[Ka];
    long int **temp = new long int *[Wa];
    for (i = 0; i < Wa; ++i)
        temp[i] = new long int[Ka];

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

float **matrixPower(float **a, int Wa, int Ka, unsigned short st) {
    int j = 0, i = 0, n = 0, d = 0, b = 0, k = 0, sum;
    float **wynik = new float *[Wa];
    for (i = 0; i < Wa; ++i)
        wynik[i] = new float[Ka];
    float **temp = new float *[Wa];
    for (i = 0; i < Wa; ++i)
        temp[i] = new float[Ka];

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


bool LUdecomposition(int n, float **a) {
    int i, j, k;
    const float eps = 1e-12;
    for (k = 0; k < n - 1; k++) {
        if (abs(a[k][k]) < eps)
            return false;

        for (i = k + 1; i < n; i++) {
            a[i][k] /= a[k][k];
        }
        for (i = k + 1; i < n; i++)
            for (j = k + 1; j < n; j++)
                a[i][j] -= a[i][k] * a[k][j];
    }
    return true;
}


float matrixDeterminant(float **a, int Wa, int Ka) {
    float det = 0;
    int n = Wa, i, j;
    cout << setprecision(4) << fixed;
    if (LUdecomposition(n, a)) {
        det = a[0][0];
        for (i = 1; i < n; i++)
            det *= a[i][i];
    } else
        cout << "DZIELNIK ZERO\n";

    return det;
}


bool matrixIsDiagonal(long int **a, int Wa, int Ka) {
    for (int i = 0; i < Wa; i++)
        for (int j = 0; j < Ka; j++) {
            if (a[i][j] != 0 && i != j)
                return false;
        }
    return true;
}

bool matrixIsDiagonal(float **a, int Wa, int Ka) {
    for (int i = 0; i < Wa; i++)
        for (int j = 0; j < Ka; j++) {
            if (a[i][j] != 0 && i != j)
                return false;
        }
    return true;
}


void swap(long int *a, long int *b) {
    long int temp = *a;
    *a = *b;
    *b = temp;

}

void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}


long int **sortRow(long int **a, int Ka) {
    long int temp = 0;
    for (int i = 0; i < Ka - 1; i++)

        // Last i elements are already in place
        for (int j = 0; j < Ka - i - 1; j++)
            if (a[0][j] > a[0][j + 1]) {
                temp = a[0][j];
                a[0][j] = a[0][j + 1];
                a[0][j + 1] = temp;

            }
    for (int i = 0; i < Ka; i++)
        cout << a[0][i];
    cout << endl;
    return a;
}

float **sortRow(float **a, int Ka) {
    float temp = 0;
    for (int i = 0; i < Ka - 1; i++)

        // Last i elements are already in place
        for (int j = 0; j < Ka - i - 1; j++)
            if (a[0][j] > a[0][j + 1]) {
                temp = a[0][j];
                a[0][j] = a[0][j + 1];
                a[0][j + 1] = temp;

            }
    for (int i = 0; i < Ka; i++)
        cout << a[0][i] << " ";
    cout << endl;
    return a;
}


long int **matrixSortRows(long int **a, int Wa, int Ka) {
    long int temp = 0;
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

float **matrixSortRows(float **a, int Wa, int Ka) {
    float temp = 0;
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

long int **matrixGenerate(int W, int K, long int min, long int max) {
    long int **wynik = new long int *[W];
    for (int i = 0; i < W; ++i)
        wynik[i] = new long int[K];
//stara metoda
    unsigned seed = time(0);
    srand(seed);

    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++) {
            wynik[i][j] = rand() % max + min;
        }
    }
    printMatrix(wynik, W, K);

    return wynik;
}

float **matrixGenerate(int W, int K, float m, float M) {
    float **wynik = new float *[W];
    for (int i = 0; i < W; ++i)
        wynik[i] = new float[K];

//nowa metoda

    std::uniform_real_distribution<float> unif(m, M);
    std::default_random_engine re;
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++) {
            wynik[i][j] = unif(re);
        }
    }
    printMatrix(wynik, W, K);

    return wynik;
}
