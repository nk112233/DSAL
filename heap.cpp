#include <iostream>
using namespace std;

class MyHeap {
public:
    void heapify(int arr[], int N, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < N && arr[l] > arr[largest])
            largest = l;

        if (r < N && arr[r] > arr[largest])
            largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, N, largest);
        }
    }

    void heapSort(int arr[], int N) {
        for (int i = N / 2 - 1; i >= 0; i--)
            heapify(arr, N, i);
        int  j = 1;
        for (int i = N - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
            cout<< "iteration " << j << ": ";
            printArray(arr, N);
        }
    }

    void printArray(int arr[], int N) {
        for (int i = 0; i < N; ++i)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

int main() {
    MyHeap heap;
    int arr[] = { 7, 6, 2, 8, 5, 4 };
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    heap.printArray(arr, N);
    heap.heapSort(arr, N);
 
    cout << "Sorted array is "<<endl;
    heap.printArray(arr, N);

    return 0;
}
