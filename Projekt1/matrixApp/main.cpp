#include <iostream>
#include "../include/matrixLib.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argv[1] == NULL) {
        cout << "Brak dzialania. (Wpisz \"help\" jako dzialanie, aby ponownie wyswietlic pomoc.)" << endl;
        help();
        exit(3);
    }

    string dzialanie = argv[1];

    if (dzialanie == "help")
        help();

    int Wa, Ka, Wb, Kb, typ = 0;
    double s = 0;
    unsigned st;

    cout << "Macierze typu int: wpisz \"1\" \nMacierze typu double: wpisz \"2\""
         << endl;     //alokacja pamieci na macierze
    cin >> typ;
    checkInput();

    if (dzialanie == "swap") {
        if (typ == 1) {
            int **x = new int *[1];
            for (int i = 0; i < 1; ++i)
                x[i] = new int[2];
            cout << "Podaj liczby do zamiany miejscami: ";
            cin >> x[0][0] >> x[0][1];
            checkInput();
            cout << "Podano liczby: " << x[0][0] << " " << x[0][1] << endl;
            swap(x[0][0], x[0][1]);
            cout << "Zamienione liczby =" << x[0][0] << " " << x[0][1];
            exit(1);
        } else {
            double **x = new double *[1];
            for (int i = 0; i < 1; ++i)
                x[i] = new double[2];
            cout << "Podaj liczby do zamiany miejscami: ";
            cin >> x[0][0] >> x[0][1];
            checkInput();
            cout << "Podano liczby: " << x[0][0] << " " << x[0][1] << endl;
            swap(x[0][0], x[0][1]);
            cout << "Zamienione liczby = " << x[0][0] << "  " << x[0][1];
            exit(1);
        }
    }

    cout
            << " Podaj ilosc wierszy i kolumn macierzy a [W] [K]:";         //zapisywanie ilosci wierszy i kolumn w macierzach
    cin >> Wa >> Ka;
    checkInput();
    cout << endl << "Podaj ilosc wierszy i kolumn macierzy b [W] [K]: ";
    cin >> Wb >> Kb;
    checkInput();


    int **a = new int *[Wa];
    for (int i = 0; i < Wa; ++i)
        a[i] = new int[Ka];

    int **b = new int *[Wb];
    for (int i = 0; i < Wb; ++i)
        b[i] = new int[Kb];

    double **A = new double *[Wa];
    for (int i = 0; i < Wa; ++i)
        A[i] = new double[Ka];
    double **B = new double *[Wb];
    for (int i = 0; i < Wb; ++i)
        B[i] = new double[Kb];

    if (typ != 2 && typ != 1) {
        cout << "Podano zly typ danych w macierzy.";
        exit(4);
    }


    if (typ == 1) {
        for (int i = 0; i < Wa; i++) {
            cout << endl << "Podaj " << i + 1 << " wiersz macierzy a:";
            for (int j = 0; j < Ka; j++) {
                cin >> a[i][j];
                checkInput();
            }
        }
        cout << endl << "Podano macierz: \n";
        printMatrix(a, Wa, Ka);

        for (int i = 0; i < Wb; i++) {
            cout << endl << "Podaj " << i + 1 << " wiersz macierzy b:";
            for (int j = 0; j < Kb; j++) {
                cin >> b[i][j];
                checkInput();
            }
        }
        cout << endl << "Podano macierz: \n";
        printMatrix(b, Wb, Kb);
    } else {
        for (int i = 0; i < Wa; i++) {
            cout << endl << "Podaj " << i + 1 << " wiersz macierzy A:";
            for (int j = 0; j < Ka; j++) {
                cin >> A[i][j];
                checkInput();
            }
        }
        cout << endl << "Podano macierz: \n";
        printMatrix(A, Wa, Ka);

        for (int i = 0; i < Wb; i++) {
            cout << endl << "Podaj " << i + 1 << " wiersz macierzy b:";
            for (int j = 0; j < Kb; j++) {
                cin >> B[i][j];
                checkInput();
            }
        }
        cout << endl << "Podano macierz: \n";
        printMatrix(B, Wb, Kb);
    }


    cout << "\n\nWybrano dzialanie: " << dzialanie << endl;

    if (dzialanie == "addMatrix") {
        if (typ == 1)
            cout << "Wynik dodawania macierzy= \n" << addMatrix(a, b, Wa, Kb);
        else
            cout << "Wynik dodawania macierzy= \n" << addMatrix(A, B, Wa, Kb);
    }


    if (dzialanie == "subtractMatrix") {
        if (typ == 1)
            cout << "Wynik odejmowania macierzy= \n" << subtractMatrix(a, b, Wa, Kb);
        else
            cout << "Wynik odejmowania macierzy= \n" << subtractMatrix(A, B, Wa, Kb);
    }


    if (dzialanie == "multiplyMatrix") {
        if (typ == 1)
            cout << "Wynik mnorzenia macierzy= \n" << multiplyMatrix(a, b, Wa, Ka, Kb);
        else
            cout << "Wynik mnorzenia macierzy= \n" << multiplyMatrix(A, B, Wa, Ka, Kb);
    }


    if (dzialanie == "multiplyByScalar") {
        cout << "Podaj skalar: ";
        cin >> s;
        checkInput();
        if (typ == 1)
            cout << "Wyniki mnorzenia przez skalar=\n" << multiplyByScalar(a, Wa, Ka, s);
        else
            cout << "Wyniki mnorzenia przez skalar=\n" << multiplyByScalar(A, Wa, Ka, s);;

    }


    if (dzialanie == "transpozeMatrix") {
        if (typ == 1)
            cout << "Wynik transponowania macierzy=\n" << transpozeMatrix(a, Wa, Ka);
        else
            cout << "Wynik transponowania macierzy=\n" << transpozeMatrix(A, Wa, Ka);
    }


    if (dzialanie == "powerMatrix") {
        cout << "Podaj stopien: ";
        cin >> st;
        checkInput();
        if (typ == 1)
            cout << "Wynik potegowania macierzy=\n" << powerMatrix(a, Wa, Ka, st);
        else
            cout << "Wynik potegowania macierzy=\n" << powerMatrix(A, Wa, Ka, st);

    }


    if (dzialanie == "determinantMatrix")
        cout << "Wyznacznik macierzy = " << determinantMatrix(A, Wa, Ka);


    if (dzialanie == "matrixIsDiagonal") {
        if (typ == 1)
            if (matrixIsDiagonal(a, Wa, Ka))
                cout << "Macierz jest diagonalna";
            else
                cout << "Macierz nie jest diagonalna";
        else if (matrixIsDiagonal(A, Wa, Ka))
            cout << "Macierz jest diagonalna";
        else
            cout << "Macierz nie jest diagonalna";
    }


    if (dzialanie == "sortRow") {
        if (typ == 1)
            cout << "Posortowany rzad macierzy = \n" << sortRow(a, Ka);
        else
            cout << "Posortowany rzad macierzy = \n" << sortRow(A, Ka);
    }


    if (dzialanie == "sortRowsInMatrix") {
        if (typ == 1)
            cout << "Posortowane rzedy w macierzy =\n" << sortRowsInMatrix(a, Wa, Ka);
        else
            cout << "Posortowane rzedy w macierzy =\n" << sortRowsInMatrix(A, Wa, Ka);
    }


    for (int i = 0; i < Wa; ++i) { //czyszczenie pamieci
        delete[] a[i];
    }
    delete[] a;

    for (int i = 0; i < Wb; ++i) {
        delete[] b[i];
    }
    delete[] b;
    for (int i = 0; i < Wa; ++i) {
        delete[] A[i];
    }
    delete[] A;

    for (int i = 0; i < Wb; ++i) {
        delete[] B[i];
    }
    delete[] B;

    return 0;
}

