#include <iostream>
using namespace std;

// Function to partition the array and return the pivot index.
int partition(int arr[], int low, int high) {
    
    int pivot = arr[high];
    int idx = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            idx++;
            swap(arr[idx], arr[j]);
        }
    }
    idx++;
    swap(arr[idx], arr[high]);

    return idx;
}

// Function to recursively sort the array using Quick Sort.
void quickSort(int arr[], int low, int high) {

    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// Function to initiate the Quick Sort process.
void processQuickSort(int arr[], int n) {
    if (n > 1)
    {
        quickSort(arr, 0, n - 1);
    }
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to dynamically allocate an array and fill it with random values.
void fillDynamicArrayWithRandomValues(int** arr, int* n) {
    cout << "Enter the size of the array: ";
    cin >> *n;
    *arr = new int[*n];
    srand(time(0)); // Seed for random number generation
    for (int i = 0; i < *n; i++) {
        (*arr)[i] = rand() % 1000; // Fill with random numbers between 0 and 999
    }
}

int main() {
    int* arr;
    int n;
    fillDynamicArrayWithRandomValues(&arr, &n);
    cout << "Unsorted array: ";
    displayArray(arr, n);
    processQuickSort(arr, n);
    cout << "Sorted array: ";
    displayArray(arr, n);
    delete[] arr; // Deallocate dynamically allocated memory
    return 0;
}

