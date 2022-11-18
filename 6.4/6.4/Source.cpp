#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        a[i] = min + rand() % (max - min + 1);
    }
}

void Print(int* a, int size) {
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << setw(4) << a[i];
    }
    cout << endl;
}

void Task1_1(int* a, int size, int& highest) {
    highest = a[0];
    for (int i = 0; i < size; i++) {
        if (a[i] > highest) {
            highest = a[i];
        }
    }
}

void Task1_2(int* a, int size, int& sumToTheLast) {
    int n = 0;
    sumToTheLast = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] > 0) {
            n = i;
        }
    }
    for (int i = 0; i < n; i++) {
        sumToTheLast += a[i];
    }
}

void Task1_3(int* a, int size) {
    int ld, rd;
    cout << "enter min value of interval: "; cin >> ld;
    cout << "enter max value of interval: "; cin >> rd;
    int n = 0;
    for (int i = 0; i < size - n; i++) {
        if (ld <= a[i] && a[i] <= rd) {
            for (int j = i; j < size - 1; j++) {
                a[j] = a[j + 1];
            }
            i--;
            n++;
        }
    }
    for (int i = size - n; i < size; i++) {
        a[i] = 0;
    }
}

int main() {
    srand((unsigned)time(NULL));

    int size;
    cout << "size = "; cin >> size;
    int min = -10; int max = 10;
    int* a = new int [size];
   
    int highest = a[0];
    int sumToTheLast = 0;

    Create(a, size, min, max);
    Print(a, size);

    Task1_1(a, size, highest);
    cout << "the highest in array = " << highest << endl;

    Task1_2(a, size, sumToTheLast);
    cout << "sum to the last positive = " << sumToTheLast << endl;

    Task1_3(a, size);
    Print(a, size);

    
    delete[] a;
    return 0;
}