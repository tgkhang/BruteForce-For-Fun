#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& a) {
    int n = a.size();

    for (int i = 0; i < n - 1; ++i) {
        bool tmp = false;

        for (int j = 0; j < n - 1 - i; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                tmp = true;
            }
        }
        if (!tmp) break;
    }
}

void selectionSort(vector<int>& a) {
    int n = a.size();

    for (int i = 0; i < n - 1; ++i) {
        int minId = i;
        for (int j = i + 1; j < n; ++j)
            if (a[j] < a[minId]) minId = j;

        if (minId != i) swap(a[i], a[minId]);
    }
}

void insertionSort(vector<int>& a) {
    int n = a.size();

    for (int i = 1; i < n; ++i) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
    }
}

int main() {
    return 0;
}
