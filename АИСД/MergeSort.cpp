/*
* Худшее время	        O(n log n)
* Лучшее время	        O(n log n)
* Среднее время	        O(n log n)
* Затраты памяти	    O(1) для списка, O(n) для массива
*/

#include <stdio.h>
#include <stdlib.h>


// Объединение двух отсортированных массивов в один отсортированный массив
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // Копируем данные во временные массивы L[] и R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Объединяем временные массивы обратно в arr[l..r]
    i = 0; // Индекс первого подмассива
    j = 0; // Индекс второго подмассива
    k = l; // Индекс объединенного массива
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Копируем оставшиеся элементы массива L[] (если они остались)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Копируем оставшиеся элементы массива R[] (если они остались)
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// Главная функция, которая рекурсивно разделяет и сортирует массив
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Находим средину массива
        int m = l + (r - l) / 2;

        // Сортируем первую и вторую половину
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Объединяем отсортированные части
        merge(arr, l, m, r);
    }
}


int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Исходный массив:\n");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr, 0, arr_size - 1);

    printf("\nОтсортированный массив:\n");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

