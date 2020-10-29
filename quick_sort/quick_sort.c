#include <stdio.h>
#include <stdlib.h>
// #include "file.h"
// a хүснэгтийн begin-ээс end завсарт орших элементүүдээс
//pivot элементийг сонгоод зөв байрлалд оруулан, pivot элементийн index-ийг буцаана.
int partition(int *a, int begin, int end)
{
    int p = a[begin];
    int i = end + 1;
    int temp;
    for (int j = end; j >= begin + 1; j--)
    {
        if (a[j] > p)
        {
            i--;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i - 1];
    a[i - 1] = a[begin];
    a[begin] = temp;
    return (i - 1);
}
//a хүснэгтийн begin-ээс end завсарт орших элементүүдийг эрэмбэлнэ
void quick_sort(int *a, int begin, int end)
{

    if (begin < end)
    {
        int p = partition(a, begin, end);
        quick_sort(a, begin, p - 1);
        quick_sort(a, p + 1, end);
    }
}
// a хүснэгтийг хэвлэх
void printArray(int *a, int l)
{
    int i;
    printf("\n");
    for (i = 0; i < l; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main()
{
    int n = 10;
    int a[] = {10, 15, 20, 8, 12, 17, 11, 1, 9, 5};
    printArray(a, n);
    quick_sort(a, 0, n - 1);
    printArray(a, n);
    return 0;
}
