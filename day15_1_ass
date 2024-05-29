#include <stdio.h>
#include <pthread.h>

// Function for selection sort
void selection_sort(int *arr, int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Thread function to sort the array
void* thread_func(void *param) {
    int *arr = (int*)param;
    selection_sort(arr, 10);
    return NULL;
}

int main() {
    int arr[10] = {64, 25, 12, 22, 11, 34, 90, 78, 56, 1};
    pthread_t tid;

    // Create a thread to sort the array
    pthread_create(&tid, NULL, thread_func, (void*)arr);

    // Wait for the sorting thread to complete
    pthread_join(tid, NULL);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

