/*
* Худшее время	    O(n^2)
* Лучшее время	    O(n log n) (обычное разделение) или O(n) (разделение на 3 части)
* Среднее время	    O(n log n)
* Затраты памяти	O(n) вспомогательных
*                   O(log n) вспомогательных (Седжвик 1978)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void generateRandomArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

void printArr(int* arr, int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        if (i == size - 1)
            printf("%d", arr[i]);
        else
            printf("%d, ", arr[i]);
    }
    printf(" ]\n");
}

void quickSort(int* arr, int left_bound, int right_bound) {
    int prop = arr[right_bound];
    int left_index = left_bound;
    int right_index = right_bound;
    while (left_index < right_index) {
        if (arr[left_index] > prop) {
            int tmp = arr[left_index];
            arr[left_index] = arr[right_index - 1];
            arr[right_index - 1] = tmp;

            tmp = arr[right_index - 1];
            arr[right_index - 1] = arr[right_index];
            arr[right_index] = tmp;

            right_index--;
        }
        else {
            left_index++;
        }
    }

    if (left_bound != right_index)
        quickSort(arr, left_bound, right_index - 1);
    if (right_bound != left_index)
        quickSort(arr, right_index + 1, right_bound);
}

int main()
{
    srand(time(NULL));
    int a[10];
    generateRandomArray(a, 10);
    printArr(a, 10);
    quickSort(a, 0, 9);
    printArr(a, 10);
}
