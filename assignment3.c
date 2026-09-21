#include <stdio.h>
#include <stdlib.h>

#define MAX 100   /* largest array merge sort can handle */

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int smallestindx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[smallestindx]) {
                smallestindx = j;
            }
        }
        swap(&arr[i], &arr[smallestindx]);
    }
}

void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void insertionsort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int curr = arr[i];
        int prev = i - 1;

        while (prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}

void merge(int arr[], int l, int m, int h) {
    int temp[MAX];
    int i = l;
    int j = m + 1;
    int k = 0;

    while (i <= m && j <= h) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= m) temp[k++] = arr[i++];
    while (j <= h) temp[k++] = arr[j++];

    for (i = l, k = 0; i <= h; i++, k++)
        arr[i] = temp[k];
}

void mergesort(int arr[], int l, int h) {
    if (l < h) {
        int m = (l + h) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, h);
        merge(arr, l, m, h);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n = 5;
    int arr[] = {4, 9, 234, 56, 10};
    int ch;

    printf("Enter the choice\n");
    printf("1. Selection Sorting\n");
    printf("2. Insertion Sorting\n");
    printf("3. Bubble Sorting\n");
    printf("4. Merge Sorting\n");
    printf("5. Quick Sorting\n");
    if (scanf("%d", &ch) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    switch (ch) {
        case 1:
            SelectionSort(arr, n);
            printArr(arr, n);
            break;

        case 2:
            insertionsort(arr, n);
            printArr(arr, n);
            break;

        case 3:
            BubbleSort(arr, n);
            printArr(arr, n);
            break;

        case 4:
            mergesort(arr, 0, n - 1);
            printArr(arr, n);
            break;

        case 5:
            quicksort(arr, 0, n - 1);
            printArr(arr, n);
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}