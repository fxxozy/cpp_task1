#include <iostream>

using namespace std;

void readArray(int** array, int rowsCount, int columnsCount) {
    for (int i = 0; i < rowsCount; i++) {
        *(array + i) = new int[columnsCount];
        for (int j = 0; j < columnsCount; j++) {
            cin >> *(*(array + i) + j);
        }
    }
}

int** convertArray(int** array, int rowsCount) {
    int* temp;
    for (int i = 0; i < rowsCount / 2; i++) {
            temp = *(array + i);
            *(array + i) = *(array + rowsCount - i - 1);
            *(array + rowsCount - i - 1) = temp;
    }
    return array;
}

int** convertArrayByElement(int** array, int rowsCount, int columnsCount) {
    int temp;
    for (int i = 0; i < rowsCount / 2; i++) {
        for (int j = 0; j < columnsCount; j++) {
            temp = *(*(array + i) + j);
            *(*(array + i) + j) = *(*(array + rowsCount - i - 1) + j);
            *(*(array + rowsCount - i - 1) + j) = temp;
        }
    }
    return array;
}

void printArray(int** array, int rowsCount, int columnsCount) {
    for (int i = 0; i < rowsCount; i++) {
        for (int j = 0; j < columnsCount; j++) {
            cout << *(*(array + i) + j) << ' ';
        }
        cout << endl;
    }
}

void deleteArray(int** array, int rowsCount) {
    for (int i = 0; i < rowsCount; i++) {
        delete[] *(array + i);
    }
    delete[] array;
}


int main() {
    int rowsCount, columnsCount;
    cout << "Input the number of rows:";
    cin >> rowsCount;
    cout << "Input the number of columns:";
    cin >> columnsCount;

    int** array = new int* [rowsCount];
    readArray(array, rowsCount, columnsCount);

    convertArrayByElement(array, rowsCount, columnsCount);

    cout << "\n" << "Output matrix:" << endl;
    printArray(array, rowsCount, columnsCount);
    deleteArray(array, rowsCount);
}


