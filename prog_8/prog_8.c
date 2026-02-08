#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comp, swaps;

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++) {
            comp++;
            if (a[j] > a[j + 1]) {
                int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
                swaps++;
            }
        }
}

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            comp++;
            if (a[j] < a[min]) min = j;
        }
        if (min != i) {
            int t = a[i]; a[i] = a[min]; a[min] = t;
            swaps++;
        }
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            comp++;
            a[j + 1] = a[j];
            swaps++;
            j--;
        }
        if (j >= 0) comp++;
        a[j + 1] = key;
    }
}

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int i = 0; i < n2; i++) R[i] = a[m + 1 + i];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        comp++;
        a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void print(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int n, choice;
    
    printf("Enter N: ");
    scanf("%d", &n);
    
    int a[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) a[i] = rand() % 1000 + 1;
    
    printf("\nBefore Sorting:\n");
    print(a, n);
    
    printf("\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    comp = swaps = 0;
    
    switch(choice) {
        case 1: bubbleSort(a, n); break;
        case 2: selectionSort(a, n); break;
        case 3: insertionSort(a, n); break;
        case 4: mergeSort(a, 0, n - 1); break;
        default: printf("Invalid\n"); return 0;
    }
    
    printf("\nAfter Sorting:\n");
    print(a, n);
    printf("\nComparisons: %d, Swaps: %d\n", comp, swaps);
    
    return 0;
}