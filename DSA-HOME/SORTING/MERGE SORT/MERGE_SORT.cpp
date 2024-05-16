#include <iostream>
#include <iomanip>
using namespace std;

void conquer(int arr[], int start, int mid, int end, int size) {
    int merge[size];

    int index_1 = start;
    int index_2 = mid + 1;
    int x = 0;

    while (index_1 <= mid && index_2 <= end) {
        if (arr[index_1] <= arr[index_2]) {
            merge[x++] = arr[index_1++];
        } else {
            merge[x++] = arr[index_2++];
        }
    }

    while (index_1 <= mid) {
        merge[x++] = arr[index_1++];
    }
    while (index_2 <= end) {
        merge[x++] = arr[index_2++];
    }

    for (int i = 0; i < x; i++) {
        arr[start + i] = merge[i];
    }
}

void divide(int arr[], int start, int end, int size) {
    if (start >= end) {
        return;
    }

    int mid = (start + end) / 2;
    divide(arr, start, mid, size);
    divide(arr, mid + 1, end, size);

    conquer(arr, start, mid, end, size);
}

int main() {
    int arr[] = {7, 8, 3, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    divide(arr, 0, n - 1, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
