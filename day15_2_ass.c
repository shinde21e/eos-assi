#include <stdio.h>
#include <pthread.h>

// Define the struct to hold the array and its size
struct array {
    int *arr;
    int size;
};

// Function for bubble sort
void bubble_sort(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Thread function to sort the array
void* thread_func(void *param) {
    struct array *arr_struct = (struct array*)param;
    bubble_sort(arr_struct->arr, arr_struct->size);
    return NULL;
}

int main() {
    int n = 10;
    int arr[10] = {64, 25, 12, 22, 11, 34, 90, 78, 56, 1};
    struct array arr_struct = {arr, n};
    pthread_t tid;

    // Create a thread to sort the array
    pthread_create(&tid, NULL, thread_func, (void*)&arr_struct);

    // Wait for the sorting thread to complete
    pthread_join(tid, NULL);

    // Print the sorted array
    printf("Bubble Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

