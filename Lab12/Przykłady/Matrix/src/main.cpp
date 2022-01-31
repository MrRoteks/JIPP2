//
// Created by filip on 16.01.2022.
//

#include <iostream>
#include <vector>
#include <random>
#include <thread>
#include "TimeMeasure.h"

using namespace std;

void setSizeOfMatrix(vector<vector<unsigned>> *matrix, unsigned rows, unsigned columns);

void generateDataInMatrix(vector<vector<unsigned>> *matrix);

vector<vector<unsigned>> copyMatrix(vector<vector<unsigned>> *matrix);

void calculate(vector<vector<unsigned>> *matrix, vector<vector<unsigned>> *resultMatrix);

int main() {
    vector<vector<unsigned>> matrix;
    TimeMeasure timer1,timer2,timer3;

    setSizeOfMatrix(&matrix, 20000, 9590);
    timer3.timerStart();
    cout<< "Generating data in matrix" << endl;

    timer1.timerStart();
    thread th1(generateDataInMatrix,&matrix);
    timer1.timerStop();



    //system("PAUSE");

    cout<< "Copying matrix" << endl;

    timer2.timerStart();
    vector<vector<unsigned>> resultsMatrix = copyMatrix(&matrix);
    timer2.timerStop();


    cout<< "Calculations on matrix" << endl;


    thread th2(calculate,&matrix, &resultsMatrix);
    timer3.timerStop();

    cout << "Generating data in matrix: " << timer1.getTimerTimeInMilliseconds() << "ms" << endl;

    cout << "Copying matrix: " << timer2.getTimerTimeInMilliseconds() << "ms" << endl;

    cout << "Calculations on matrix: " << timer3.getTimerTimeInMilliseconds() << "ms" << endl;
    th1.join();
    th2.join();

    return 0;
}

void setSizeOfMatrix(vector<vector<unsigned>> *matrix, unsigned rows, unsigned columns) {
    matrix->resize(rows);
    for(auto &row: *matrix) {
        row.resize(columns);
    }
}

void generateDataInMatrix(vector<vector<unsigned>> *matrix) {
    default_random_engine defEngine;
    uniform_int_distribution<unsigned> intDistro(0,2000);
    for(auto &row: *matrix) {
        for(auto &cell: row)
            cell = intDistro(defEngine);
    }
}

vector<vector<unsigned>> copyMatrix(vector<vector<unsigned>> *matrix) {
    vector<vector<unsigned>> returnMatrix;
    returnMatrix.resize(matrix->size());
    returnMatrix = *matrix;
    return move(returnMatrix);
}

void calculate(vector<vector<unsigned>> *matrix, vector<vector<unsigned>> *resultMatrix) {
    for(int i = 1; i < matrix->size() - 1; ++i) {
        for(int j = 1; j < matrix->at(i).size() - 1; ++j) {
            unsigned sum = 0;
            for(int k = i - 1; k < i + 2; ++k) {
                for(int n = j - 1; n < j + 2; ++n) {
                    sum += matrix->at(k)[n];
                }
            }

            resultMatrix->at(i)[j] = sum/9;
        }
    }
}
