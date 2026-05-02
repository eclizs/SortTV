#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mergeSort.h"
#include "visualize.h"

static void merge(int *array, int left, int mid, int right, int size, double intervalInSeconds)
{
    int i = left, j = mid + 1, k = 0;
    int *temp = (int *)malloc((right - left + 1) * sizeof(int));

    while (i <= mid && j <= right)
    {
        if (array[i] < array[j])
        {
            temp[k++] = array[i++];
        }
        else
        {
            temp[k++] = array[j++];
        }
        VISUALIZE(array, size, intervalInSeconds);
    }

    while (i <= mid)
    {
        temp[k++] = array[i++];
    }

    while (j <= right)
    {
        temp[k++] = array[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++)
    {
        array[i] = temp[k];
        VISUALIZE(array, size, intervalInSeconds);
    }

    free(temp);
}

static void mergeSort_rec(int *array, int left, int right, int size, double intervalInSeconds)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        VISUALIZE(array, size, intervalInSeconds);
        mergeSort_rec(array, left, mid, size, intervalInSeconds);
        mergeSort_rec(array, mid + 1, right, size, intervalInSeconds);

        merge(array, left, mid, right, size, intervalInSeconds);
    }
}

void mergeSort(int *array, int size, double intervalInSeconds)
{
    mergeSort_rec(array, 0, size - 1, size, intervalInSeconds);
}
