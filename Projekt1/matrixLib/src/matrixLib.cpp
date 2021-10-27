#include <iostream>
#include "../include/matrixLib.h"
#include <iomanip>
using namespace std;

/**
 * help - wyswietla pomocnicze informacje dotyczace programu
 */
void help()
{
    cout<<"MatrixCalculator - HELP:"<<endl;
    cout<<"./matrixCalculator [dzialanie]"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"Dzialania: "<<endl;
    cout<<"addMatrix \t\t- dodawanie dwoch macierzy"<<endl;
    cout<<"subtractMatrix \t\t- odejmowanie dwoch macierzy "<<endl;
    cout<<"multiplyMatrix \t\t- mnozenie dwoch macierzy "<<endl;
    cout<<"multiplyByScalar \t- mnozenie przez skalar "<<endl;
    cout<<"transpozeMatrix \t- transponowanie macierzy "<<endl;
    cout<<"powerMatrix \t\t- potegowanie macierzy "<<endl;
    cout<<"determinantMatrix \t- wyznacznik macierzy "<<endl;
    cout<<"matrixIsDiagonal \t- sprawdzanie, czy macierz jest diagonalna "<<endl;
    cout<<"sortRow \t\t- sortowanie tablicy za pomoca sortowania bombelkowego "<<endl;
    cout<<"sortRowsInMatrix \t- sortowanie wszystkich wierszy w macierzy"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"Wczytywanie macierzy: "<<endl;
    cout<<"Po podaniu odpowiedniego dzialania program poprosi o podanie typu macierzy, na ktorych chcemy wykonac dzialanie."<<endl;
    cout<<"Wpisujemy 1 dla macierzy typu \"int\" lub 2 dla macierzy typu \"double\" (bledny typ zatrzyma program)"<<endl;
    cout<<"Nastepnie podajemy wiersze i kolumny macierzy pierwszej (a/A) oraz identycznie dla macierzy drugiej (b/B)"<<endl;
    cout<<"Na koniec uzupelniamy macierze odpowiednimi wartosciami. \nMozemy dodatkowo otrzymac zapytanie o dodatkowa wartosc np.skalar,potega"<<endl;
    cout<<"(Wiersze, kolumny, wartosci w macierzy i inne sa wczytywane przez polecenie \"cin\"\n wiec mozemy wpisac wszystkie wartosci na raz - oddzielajac kazda wartosc spacja i zatwierdzic enterem)"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"Wynik dzialania:  "<<endl;
    cout<<"Program wyswietli nam wynik w postaci macierzy (lub liczby np. wyznacznik) \noraz linijke nizej wyswietli wynik[0][0] (zwracana wartosc z funkcji, ze wzgledu na wybrane dzialanie mozemy jej nie otrzymac)"<<endl;
    cout<<"--------------------------KONIEC--------------------------------------"<<endl;
    exit(2);
}


/**
 * checkInput - sprawdza czy urzytkownik nie podal zlych danych (np. litery zamiast liczby)
 */
void checkInput()
{
    if(cin.fail()==1)
    {
        cout<<"Bledna wartosc/typ danych.";
        exit(6);
    }
}


/**
 * printMatrix - wyświtela wskazaną macierz
 * @param wynik -tablica, w ktorej zawarta jest macierz
 * @param W - ilosc wierszy macierzy
 * @param K - ilosc kolumn w macierzy
 */
void printMatrix(double **wynik, int W, int K) {
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++) {
            cout << wynik[i][j] << "\t";
        }
        cout << endl;
    }
}
/**
 * printMatrix - wyświtela wskazaną macierz
 * @param wynik -tablica, w ktorej zawarta jest macierz
 * @param W - ilosc wierszy macierzy
 * @param K - ilosc kolumn w macierzy
 */
void printMatrix(int **wynik, int W, int K) {
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++) {
            cout << wynik[i][j] << "\t";
        }
        cout << endl;
    }
}


/**
 * addMatrix - dodaje 2 macierze
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param b - tablica, w ktorej zawarta jest macierz b
 * @param W - ilosc wierszy macierzy
 * @param K - ilosc kolumn w macierzy
 * @return - zwraca wynik dodawania w postaci macierzy
 */
int addMatrix(int **a, int **b, int W, int K) {
    int **wynik = new int *[W];
    for (int i = 0; i < K; ++i)
        wynik[i] = new int[K];
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++) {
            wynik[i][j] = a[i][j] + b[i][j];
        }
    }
    printMatrix(wynik, W, K);

    return **wynik;
}
/**
 * addMatrix - dodaje 2 macierze
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param b - tablica, w ktorej zawarta jest macierz b
 * @param W - ilosc wierszy macierzy
 * @param K - ilosc kolumn w macierzy
 * @return - zwraca wynik dodawania w postaci macierzy
 */
double addMatrix(double **a, double **b, int W, int K) {
    double **wynik = new double *[W];
    for (int i = 0; i < K; ++i)
        wynik[i] = new double[K];
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++) {
            wynik[i][j] = a[i][j] + b[i][j];
        }
    }
    printMatrix(wynik, W, K);

    return **wynik;
}


/**
 * substractMatrix - odejmuje macierze
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param b - tablica, w ktorej zawarta jest macierz b
 * @param W - ilosc wierszy macierzy
 * @param K - ilosc kolumn w macierzy
 * @return - zwraca wynik odejmowania w postaci macierzy
 */
int subtractMatrix(int **a, int **b, int W, int K) {
    int **wynik = new int *[W];
    for (int i = 0; i < K; ++i)
        wynik[i] = new int[K];
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++) {
            wynik[i][j] = a[i][j] - b[i][j];
        }
    }
    printMatrix(wynik, W, K);

    return **wynik;
}
/**
 * substractMatrix - odejmuje macierze
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param b - tablica, w ktorej zawarta jest macierz b
 * @param W - ilosc wierszy macierzy
 * @param K - ilosc kolumn w macierzy
 * @return - zwraca wynik odejmowania w postaci macierzy
 */
double subtractMatrix(double **a, double **b, int W, int K) {
    double **wynik = new double *[W];
    for (int i = 0; i < K; ++i)
        wynik[i] = new double[K];
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++) {
            wynik[i][j] = a[i][j] - b[i][j];
        }
    }
    printMatrix(wynik, W, K);

    return **wynik;
}


/**
 * multiplyMatrix - mnozy macierze
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param b - tablica, w ktorej zawarta jest macierz b
 * @param Wa - ilosc wierszy macierzy a
 * @param Ka - ilosc kolumn macierzy a
 * @param Kb - ilosc kolumn macierzy b
 * @return - zwraca wynik mnozenia w postaci macierzy
 */
int multiplyMatrix(int **a, int **b, int Wa, int Ka, int Kb) {
    int j = 0, i = 0, n = 0;
    int **wynik = new int *[Wa];
    for (i = 0; i < Kb; ++i)
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

    return **wynik;

}
/**
 * multiplyMatrix - mnozy macierze
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param b - tablica, w ktorej zawarta jest macierz b
 * @param Wa - ilosc wierszy macierzy a
 * @param Ka - ilosc kolumn macierzy a
 * @param Kb - ilosc kolumn macierzy b
 * @return - zwraca wynik mnozenia w postaci macierzy
 */
double multiplyMatrix(double **a, double **b, int Wa, int Ka, int Kb) {
    int j = 0, i = 0, n = 0;
    double **wynik = new double *[Wa];
    for (i = 0; i < Kb; ++i)
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

    return **wynik;

}


/**
 * multiplyByScalar -mnorzy macierz przez skalar
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Wa -ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @param s - skalar
 * @return - zwraca wynik mnozenia w postaci macierzy
 */
int multiplyByScalar(int **a, int Wa, int Ka, double s) {
    int j = 0, i = 0, n = 0;
    int **wynik = new int *[Wa];
    for (i = 0; i < Ka; ++i)
        wynik[i] = new int[Ka];

    for (i = 0; i < Wa; ++i)
        for (j = 0; j < Ka; ++j) {
            wynik[i][j] = a[i][j] * s;
        }

    printMatrix(wynik, Wa, Ka);

    return **wynik;
}
/**
 * multiplyByScalar -mnorzy macierz przez skalar
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Wa -ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @param s - skalar
 * @return - zwraca wynik mnozenia w postaci macierzy
 */
double multiplyByScalar(double **a, int Wa, int Ka, double s) {
    int j = 0, i = 0, n = 0;
    double **wynik = new double *[Wa];
    for (i = 0; i < Ka; ++i)
        wynik[i] = new double[Ka];

    for (i = 0; i < Wa; ++i)
        for (j = 0; j < Ka; ++j) {
            wynik[i][j] = a[i][j] * s;
        }

    printMatrix(wynik, Wa, Ka);

    return **wynik;
}


/**
 * transpozeMatrix - transponuje macierz
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Wa - ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @return - zwraca wynik transponowania w postaci macierzy
 */
int transpozeMatrix(int **a, int Wa, int Ka) {
    int j = 0, i = 0, n = 0;
    int **wynik = new int *[Ka];
    for (i = 0; i < Wa; ++i)
        wynik[i] = new int[Wa];

    for (i = 0; i < Wa; ++i)
        for (j = 0; j < Ka; ++j) {
            wynik[j][i] = a[i][j];
        }
    printMatrix(wynik, Ka, Wa);

    return **wynik;
}
/**
 * transpozeMatrix - transponuje macierz
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Wa - ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @return - zwraca wynik transponowania w postaci macierzy
 */
double transpozeMatrix(double **a, int Wa, int Ka) {
    int j = 0, i = 0, n = 0;
    double **wynik = new double *[Ka];
    for (i = 0; i < Wa; ++i)
        wynik[i] = new double[Wa];

    for (i = 0; i < Wa; ++i)
        for (j = 0; j < Ka; ++j) {
            wynik[j][i] = a[i][j];
        }
    printMatrix(wynik, Ka, Wa);

    return **wynik;
}


/**
 * powerMatrix - podnosi macierz do wskazanej potegi
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Wa - ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @param st - stopien potegi
 * @return - zwraca wynik potegowania w postaci macierzy
 */
int powerMatrix(int **a, int Wa, int Ka, unsigned st) {
    int j = 0, i = 0, n = 0, d = 0, b = 0, k = 0, sum;
    int **wynik = new int *[Wa];
    for (i = 0; i < Ka; ++i)
        wynik[i] = new int[Ka];
    int **temp = new int *[Wa];
    for (i = 0; i < Ka; ++i)
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

    return **wynik;
}
/**
 * powerMatrix - podnosi macierz do wskazanej potegi
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Wa - ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @param st - stopien potegi
 * @return - zwraca wynik potegowania w postaci macierzy
 */
double powerMatrix(double **a, int Wa, int Ka, unsigned st) {
    int j = 0, i = 0, n = 0, d = 0, b = 0, k = 0, sum;
    double **wynik = new double *[Wa];
    for (i = 0; i < Ka; ++i)
        wynik[i] = new double[Ka];
    double **temp = new double *[Wa];
    for (i = 0; i < Ka; ++i)
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

    return **wynik;
}


/**
 * LUdecomposition -rozklad LU macierzy (do wyznacznika)
 * @param a -macierz do rozkladu
 * @param n -rozmiar macierzy (ilosc wierszy/kolumn - macierz musi byc kwadratowa)
 */
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


/**
 * determinantMatrix - liczy wyznacznik macierzy
 * @param a - tablica, w ktorej zawarta jest macierz a (jest to tablica typu double ze wzgledu na dzielenie w rozkladzie LU)
 * @param Wa - ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @return - zwraca wyznacznik macierzy
 */
double determinantMatrix(double **a, int Wa, int Ka) {
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


/**
 * matrixIsDiagonal - sprawdza czy macierz jest diagonalna
 * @param a -sprawdzana macierz
 * @param Wa -ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @return -zwraca watrosc "true" jesli macierz jest diagonalna lub wartosc "false" gdy nie jest diagonalna
 */
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
/**
 * matrixIsDiagonal - sprawdza czy macierz jest diagonalna
 * @param a -sprawdzana macierz
 * @param Wa -ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @return -zwraca watrosc "true" jesli macierz jest diagonalna lub wartosc "false" gdy nie jest diagonalna
 */
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


/**
 * sortRow - sortuje pierwszy rzad w macierzy (rosnaco)
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Ka -ilosc kolumn w macierzy
 * @return - zwraca marcierz z posortowanym pierwszym rzedem macierzy
 */
int sortRow(int **a, int Ka)
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
    return **a;
}
/**
 * sortRow - sortuje pierwszy rzad w macierzy (rosnaco)
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Ka -ilosc kolumn w macierzy
 * @return - zwraca marcierz z posortowanym pierwszym rzedem macierzy
 */
double sortRow(double **a, int Ka)
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
    return **a;
}


/**
 * sortRowsInMatrix -sortuje wszystkie rzedy macierzy (rosnaco)
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Wa -ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @return - zwraca marcierz z posortowanymi rzedami
 */
int sortRowsInMatrix(int **a, int Wa, int Ka) {
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
    return **a;
}
/**
 * sortRowsInMatrix -sortuje wszystkie rzedy macierzy (rosnaco)
 * @param a - tablica, w ktorej zawarta jest macierz a
 * @param Wa -ilosc wierszy w macierzy
 * @param Ka -ilosc kolumn w macierzy
 * @return - zwraca marcierz z posortowanymi rzedami
 */
double sortRowsInMatrix(double **a, int Wa, int Ka) {
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
    return **a;
}