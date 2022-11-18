#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, int size, int min, int max, int i) {
    if (i < size) {
        a[i] = min + rand() % (max - min + 1);
        Create(a, size, min, max, i + 1);
    }
}

void Print(int* a, int size, int i) {
    if (i < size) {
        cout << setw(4) << a[i];
        Print(a, size, i + 1);
    }
    else {
        cout << endl;
    }
}

int Task1_1(int* a, int size, int i, int highest) {
    if (i < size) {
        if (highest < a[i]) {
            highest = a[i];
        }
        return Task1_1(a, size, i + 1, highest);
    }
    return highest;
}

int Task1_2subSet(int* a, int size, int i, int& n) {
    if (i < size) {
        if (a[i] > 0) {
            n = i;
        }
        return Task1_2subSet(a, size, i + 1, n);
    }
}

int Task1_2Complete(int* a, int size, int& sumToTheLast, int& n, int i) {
    if (i < n) {
        sumToTheLast += a[i];
        Task1_2Complete(a, size, sumToTheLast, n, i + 1);
    }
    else {
        return sumToTheLast;
    }
}

void Task1_3Subset(int* a, int size, int count, int j, int i) {
    if (j < size - count - 1) {
        a[j] = a[j + 1];
        Task1_3Subset(a, size, count, j + 1, i);
    }
}

int Task1_3(int* a, int size, int ld, int rd, int count, int i) {
    if (i < size - count) {
        if (ld <= a[i] && a[i] <= rd) {
            Task1_3Subset(a, size, count, i, i);
            a[size - count - 1] = 0;
            i--;
            count++;
        }
        return Task1_3(a, size, ld, rd, count, i + 1);
    }
    return count;
}

int main() {
    srand((unsigned)time(NULL));

    int size;
    cout << "size = "; cin >> size;
    int min = -10; int max = 10;
    int* a = new int[size];
    int task1Index = 0;
    int task2Index = 0;
    int sumToTheLast = 0;

    Create(a, size, min, max, 0);
    Print(a, size, 0);

    int highest = Task1_1(a, size, 1, a[0]);
    cout << "the highest in array = " << highest << endl;

    Task1_2subSet(a, size, 0, task2Index);
    Task1_2Complete(a, size, sumToTheLast, task2Index, 0);
    cout << "sum to the last positive = " << sumToTheLast << endl;

    int ld, rd;
    cout << "enter min value of interval: "; cin >> ld;
    cout << "enter max value of interval: "; cin >> rd;
    Task1_3(a, size, ld, rd, 0, 0);
    Print(a, size, 0);
    delete[] a;
    return 0;
}