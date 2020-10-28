#include <stdio.h>
#include <stdlib.h>
// #include "file.h"
// a хүснэгтийн begin-ээс end завсарт орших элементүүдээс
//pivot элементийг сонгоод зөв байрлалд оруулан, pivot элементийн index-ийг буцаана.
int partition(int *a, int begin, int end)
{
    int pivot = a[end];
    int temp;
    int i = (begin - 1);

    for (int j = begin; j <= end - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i + 1];
    a[i + 1] = a[end];
    a[end] = temp;
    return (i + 1);
}
//a хүснэгтийн begin-ээс end завсарт орших элементүүдийг эрэмбэлнэ
void quick_sort(int *a, int begin, int end)
{
    if (begin < end)
    {
        int pi = partition(a, begin, end);
        quick_sort(a, begin, pi - 1);
        quick_sort(a, pi + 1, end);
    }
}
// a хүснэгтийг хэвлэх
void printArray(int *a, int l)
{
    int i;
    for (i = 0; i < l; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main()
{
    int n = 10;
    int a[] = {10, 15, 20, 8, 12, 17, 11, 1, 9, 5};
    quick_sort(a, 0, n - 1);
    printArray(a, n);
    return 0;
}
