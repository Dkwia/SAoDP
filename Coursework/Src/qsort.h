//
// Created by BobroMacbook on 02.09.24.
//

#ifndef QSORT_H
#define QSORT_H

#endif //QSORT_H

void swap(int *elementA, int *elementB)
{
    int temp = *elementA;
    *elementA = *elementB;
    *elementB = temp;
}

int partition(int arr[], int start, int end, int &M, int &C)
{

    int pivot = arr[(start + end) / 2];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        C++;
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    M+3;
    swap(&arr[pivotIndex], &arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
            C++;
        }

        while (arr[j] > pivot) {
            j--;
            C++;
        }

        if (i < pivotIndex && j > pivotIndex) {
            M+=3;
            swap(&arr[i++], &arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort2(int arr[], int start, int end, int &M, int &C)
{

    if (start >= end)
        return;
    while (end > start) {

        int p = partition(arr, start, end, M, C);
        if (p - 1 < end - p - 1) {
            quickSort2(arr, start, p - 1, M, C);
            start = p + 1;
        } else {
            quickSort2(arr, p + 1, end, M, C);
            end = p - 1;
        }
    }
}