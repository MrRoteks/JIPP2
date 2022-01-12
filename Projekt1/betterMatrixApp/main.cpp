#include <iostream>
#include <iomanip>
#include "../include/matrixLib.h"
#include <limits.h>
#include <math.h>
#include <utility>


using namespace std;

int main(int argc, char *argv[]) {
    if (argv[1] == NULL || argc > 3) {
        cout << "Brak dzialania lub za duzo argumentow  (Wpisz \"help\" jako dzialanie, aby ponownie wyswietlic pomoc.)"
             << endl;
        help();
        exit(3);
    }
    string dzialanie = argv[1];

    unsigned seed = time(0);
    srand(seed);

    bool losowa = false;
    if (argc > 2) {
        string dzialanie2 = argv[2];
        if (dzialanie2 == "generate")
            losowa = true;
        else if (argv[2] != NULL) {
            cout << "Blad w [dzialanie2]!";
            exit(3);
        }
    }

    if (dzialanie == "matrixAdd" || dzialanie == "matrixSubtract" || dzialanie == "matrixMultiply" ||
        dzialanie == "matrixMultiplyByScalar" || dzialanie == "swap" || dzialanie == "help" ||
        dzialanie == "matrixTranspoze" || dzialanie == "matrixPower" || dzialanie == "matrixDeterminant" ||
        dzialanie == "matrixIsDiagonal" || dzialanie == "sortRow" || dzialanie == "matrixSortRows" ||
        dzialanie == "matrixGenerate") {
        if (dzialanie == "help") {
            help();
            exit(4);
        }

        int typ = 0; //Wa = matrix.first, Ka = matrix.second
        //   wiersz             kolumna
        pair<int, int> mxa;
        pair<int, int> mxb;
        float s = 0;
        unsigned short st;

        cout << "Macierze typu long int: wpisz \"1\" \nMacierze typu float: wpisz \"2\""
             << endl;     //alokacja pamieci na macierze
        cin >> typ;
        checkInput();

        if (typ != 2 && typ != 1) {
            cout << "Podano zly typ danych w macierzy.";
            exit(5);
        }
        if (dzialanie == "swap") {
            if (typ == 1) {
                long int **x = new long int *[1];
                for (int i = 0; i < 1; ++i)
                    x[i] = new long int[2];

                cout << "Podaj liczby do zamiany miejscami: ";
                cin >> x[0][0] >> x[0][1];
                checkInput();
                cout << "Podano liczby: " << x[0][0] << " " << x[0][1] << endl;
                swap(x[0][0], x[0][1]);
                cout << "Zamienione liczby =" << x[0][0] << " " << x[0][1];

                for (int i = 0; i < 1; ++i) {
                    delete[] x[i];
                }
                delete[] x;
                exit(1);
            } else {
                float **x = new float *[1];
                for (int i = 0; i < 1; ++i)
                    x[i] = new float[2];
                cout << "Podaj liczby do zamiany miejscami: ";
                cin >> x[0][0] >> x[0][1];
                checkInput();
                cout << "Podano liczby: " << x[0][0] << " " << x[0][1] << endl;
                swap(x[0][0], x[0][1]);
                cout << "Zamienione liczby = " << x[0][0] << "  " << x[0][1];
                exit(0);
            }
        }


        cout
                << " Podaj ilosc wierszy i kolumn macierzy a [W] [K]:";         //zapisywanie ilosci wierszy i kolumn w macierzach
        cin >> mxa.first >> mxa.second; //zamienione z wa ka
        checkInput();

        if (dzialanie == "matrixGenerate") {
            if (typ == 1) {
                long int m, M;
                cout << " Podaj dolny oraz gorny zakres liczb: " << endl;
                cin >> m >> M;
                checkInput();
                if (m >= M) {
                    cout << "Bledne dane.";
                    help();
                    exit(4);
                }
                cout << "Wygenerowana macierz= \n" << matrixGenerate(mxa.first, mxa.second, m, M);
            } else if (typ == 2) {
                float m, M;
                cout << " Podaj dolny oraz gorny zakres liczb: " << endl;
                cin >> m >> M;
                checkInput();
                if (m >= M) {
                    cout << "Bledne dane.";
                    help();
                    exit(4);
                }

                cout << "Wygenerowana macierz= \n" << matrixGenerate(mxa.first, mxa.second, m, M);
            }
            exit(0);
        }


        cout << endl << "Podaj ilosc wierszy i kolumn macierzy b [W] [K]: ";
        cin >> mxb.first >> mxb.second;
        checkInput();


        long int **a = new long int *[mxa.first];
        for (int i = 0; i < mxa.first; ++i)
            a[i] = new long int[mxa.second];

        long int **b = new long int *[mxb.first];
        for (int i = 0; i < mxb.first; ++i)
            b[i] = new long int[mxb.second];

        float **A = new float *[mxa.first];
        for (int i = 0; i < mxa.first; ++i)
            A[i] = new float[mxb.second];
        float **B = new float *[mxb.first];
        for (int i = 0; i < mxb.first; ++i)
            B[i] = new float[mxb.second];


        if (typ == 1) {
            if (losowa == true) {
                long int m, M;
                cout << " Podaj dolny oraz gorny zakres liczb losowych: " << endl;
                cin >> m >> M;
                checkInput();
                if (m >= M) {
                    cout << "Bledne dane.";
                    help();
                    exit(4);
                }
                cout << "Wygenerowana macierz=" << endl;
                long int **wynik = matrixGenerate(mxa.first, mxa.second, m, M);

                for (int i = 0; i < mxa.first; i++)
                    for (int j = 0; j < mxa.second; j++)
                        a[i][j] = wynik[i][j];
            } else {
                for (int i = 0; i < mxa.first; i++) {
                    cout << endl << "Podaj " << i + 1 << " wiersz macierzy a:";
                    for (int j = 0; j < mxa.second; j++) {
                        cin >> a[i][j];
                        checkInput();
                    }

                }
                cout << endl << "Podano macierz: \n";
                printMatrix(a, mxa.first, mxa.second);
            }

            if (losowa == true) {
                long int m, M;
                cout << " Podaj dolny oraz gorny zakres liczb losowych: " << endl;
                cin >> m >> M;
                checkInput();
                if (m >= M) {
                    cout << "Bledne dane.";
                    help();
                    exit(4);
                }
                cout << "Wygenerowana macierz=" << endl;
                long int **wynik = matrixGenerate(mxb.first, mxb.second, m, M);

                for (int i = 0; i < mxb.first; i++)
                    for (int j = 0; j < mxb.second; j++)
                        b[i][j] = wynik[i][j];
            } else {
                for (int i = 0; i < mxb.first; i++) {
                    cout << endl << "Podaj " << i + 1 << " wiersz macierzy b:";
                    for (int j = 0; j < mxb.second; j++) {
                        cin >> b[i][j];
                        checkInput();
                    }
                }
                cout << endl << "Podano macierz: \n";
                printMatrix(b, mxb.first, mxb.second);
            }
        } else {
            if (losowa == true) {
                float m, M;
                cout << " Podaj dolny oraz gorny zakres liczb losowych: " << endl;
                cin >> m >> M;
                checkInput();
                if (m >= M) {
                    cout << "Bledne dane.";
                    help();
                    exit(4);
                }
                cout << "Wygenerowana macierz=" << endl;
                float **wynik = matrixGenerate(mxa.first, mxa.second, m, M);

                for (int i = 0; i < mxa.first; i++)
                    for (int j = 0; j < mxa.second; j++)
                        A[i][j] = wynik[i][j];
            } else {
                for (int i = 0; i < mxa.first; i++) {
                    cout << endl << "Podaj " << i + 1 << " wiersz macierzy A:";
                    for (int j = 0; j < mxa.second; j++) {
                        cin >> A[i][j];
                        checkInput();
                    }
                }
                cout << endl << "Podano macierz: \n";
                printMatrix(A, mxa.first, mxa.second);
            }

            if (losowa == true) {
                float m, M;
                cout << " Podaj dolny oraz gorny zakres liczb losowych: " << endl;
                cin >> m >> M;
                checkInput();
                if (m >= M) {
                    cout << "Bledne dane.";
                    help();
                    exit(4);
                }
                cout << "Wygenerowana macierz=" << endl;
                float **wynik = matrixGenerate(mxb.first, mxb.second, m, M);

                for (int i = 0; i < mxa.first; i++)
                    for (int j = 0; j < mxa.second; j++)
                        B[i][j] = wynik[i][j];
            } else {
                for (int i = 0; i < mxb.first; i++) {
                    cout << endl << "Podaj " << i + 1 << " wiersz macierzy b:";
                    for (int j = 0; j < mxb.second; j++) {
                        cin >> B[i][j];
                        checkInput();
                    }
                }
                cout << endl << "Podano macierz: \n";
                printMatrix(B, mxb.first, mxb.second);
            }

        }
        cin.clear();
        cin.ignore(INT_MAX, '\n');


        cout << "\n\nWybrano dzialanie: " << dzialanie << endl;

        if (dzialanie == "matrixAdd") {
            if (typ == 1)
                cout << "Wynik dodawania macierzy= \n" << matrixAdd(a, b, mxa.first, mxb.second);

            else if (typ == 2)
                cout << "Wynik dodawania macierzy= \n" << matrixAdd(A, B, mxa.first, mxb.second);

        } else if (dzialanie == "matrixSubtract") {
            if (typ == 1)
                cout << "Wynik odejmowania macierzy= \n" << matrixSubtract(a, b, mxa.first, mxb.second);
            else if (typ == 2)
                cout << "Wynik odejmowania macierzy= \n" << matrixSubtract(A, B, mxa.first, mxb.second);
        } else if (dzialanie == "matrixMultiply") {
            if (typ == 1)
                cout << "Wynik mnorzenia macierzy= \n" << matrixMultiply(a, b, mxa.first, mxa.second, mxb.second);
            else if (typ == 2)
                cout << "Wynik mnorzenia macierzy= \n" << matrixMultiply(A, B, mxa.first, mxa.second, mxb.second);
        } else if (dzialanie == "matrixMultiplyByScalar") {
            cout << "Podaj skalar: ";
            cin >> s;
            checkInput();
            if (typ == 1)
                cout << "Wyniki mnorzenia przez skalar=\n" << matrixMultiplyByScalar(a, mxa.first, mxa.second, s);
            else if (typ == 2)
                cout << "Wyniki mnorzenia przez skalar=\n" << matrixMultiplyByScalar(A, mxa.first, mxa.second, s);;

        } else if (dzialanie == "matrixTranspoze") {
            if (typ == 1)
                cout << "Wynik transponowania macierzy=\n" << matrixTranspoze(a, mxa.first, mxa.second);
            else if (typ == 2)
                cout << "Wynik transponowania macierzy=\n" << matrixTranspoze(A, mxa.first, mxa.second);
        } else if (dzialanie == "matrixPower") {
            cout << "Podaj stopien: ";
            cin >> st;
            checkInput();
            if (typ == 1)
                cout << "Wynik potegowania macierzy=\n" << matrixPower(a, mxa.first, mxa.second, st);
            else if (typ == 2)
                cout << "Wynik potegowania macierzy=\n" << matrixPower(A, mxa.first, mxa.second, st);

        } else if (dzialanie == "matrixDeterminant") {
            cout << "Wyznacznik macierzy = " << matrixDeterminant(A, mxa.first, mxa.second);
        } else if (dzialanie == "matrixIsDiagonal") {
            if (typ == 1) {
                if (matrixIsDiagonal(a, mxa.first, mxa.second))
                    cout << "Macierz jest diagonalna";
                else
                    cout << "Macierz nie jest diagonalna";
            } else if (typ == 2) {
                if (matrixIsDiagonal(A, mxa.first, mxa.second))
                    cout << "Macierz jest diagonalna";
                else
                    cout << "Macierz nie jest diagonalna";
            }
        } else if (dzialanie == "sortRow") {
            if (typ == 1)
                cout << "Posortowany rzad macierzy = \n" << sortRow(a, mxa.second);
            else if (typ == 2)
                cout << "Posortowany rzad macierzy = \n" << sortRow(A, mxa.second);
        } else if (dzialanie == "matrixSortRows") {
            if (typ == 1)
                cout << "Posortowane rzedy w macierzy =\n" << matrixSortRows(a, mxa.first, mxa.second);
            else if (typ == 2)
                cout << "Posortowane rzedy w macierzy =\n" << matrixSortRows(A, mxa.first, mxa.second);
        }





//czyszczenie pamieci
        for (int i = 0; i < mxa.first; ++i) {
            delete[] a[i];
        }
        delete[] a;

        for (int i = 0; i < mxb.first; ++i) {
            delete[] b[i];
        }
        delete[] b;
        for (int i = 0; i < mxa.first; ++i) {
            delete[] A[i];
        }
        delete[] A;

        for (int i = 0; i < mxb.first; ++i) {
            delete[] B[i];
        }
        delete[] B;

        return 0;
    } else {
        {
            cout << "Bledne dzialanie. (Wpisz \"help\" jako dzialanie, aby ponownie wyswietlic pomoc.)"
                 << endl;
            help();
            exit(3);
        }
    }

}

