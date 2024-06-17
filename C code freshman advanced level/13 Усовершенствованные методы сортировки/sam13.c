#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int assignments = 0;
int comparisons = 0;

int N1;

void print_array(int *arr, int n) {
      for (int i = 1; i < n+1; i++) {
        printf("%3d ", i);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%3d ", arr[i]);
    }
    printf("\n\n");
}

void merge(int *arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
        assignments++;
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
        assignments++;
    }

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
            assignments++;
        } else {
            arr[k] = R[j];
            j++;
            assignments++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        assignments++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        assignments++;
    }

    free(L);
    free(R);
}

void merge_sort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void improved_merge_sort(int *arr, int left, int right) {
    if (right - left <= 43) {
        for (int i = left + 1; i <= right; i++) {
            int temp = arr[i];
            assignments++;
            int j = i - 1;
            while (j >= left && arr[j] > temp) {
                comparisons++;
                arr[j + 1] = arr[j];
                assignments++;
                j--;
            }
            comparisons++;
            arr[j + 1] = temp;
            assignments++;
            print_array(arr, N1);
        }
    } else if (left < right) {
        int mid = left + (right - left) / 2;

        improved_merge_sort(arr, left, mid);
        improved_merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    N1 = N;
    int *arr1 = malloc(N * sizeof(int));
  
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr1[i]);
    }
    
    int *arr2 = malloc(N * sizeof(int));
    memcpy(arr2, arr1, N * sizeof(int));
    
//    assignments = 0;
//   comparisons = 0;
    
//    merge_sort(arr1, 0, N - 1);
    
//    printf("%3d %3d\n", assignments, comparisons);
    
//    free(arr1);
    
    assignments = 0;
    comparisons = 0;
    
    improved_merge_sort(arr2, 0, N - 1);
    
    printf("%3d %3d\n", assignments, comparisons);
    
    free(arr2);
    
    return 0;
}




#include <stdio.h>
#include <stdlib.h>

