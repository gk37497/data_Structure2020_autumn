#include <stdio.h>
#include <stdlib.h>
#include "file.h"
// урьдчилан эрэмбэлэгдсэн a_l урт бүхий a хүснэгт болон b_l урт бүхий b хүснэгтийг эрэмбэлэн нийлүүлэж out хүснэгтэд хадгал
void merge(int *out, int *a, int *b, int a_l, int b_l)
{
    int i = 0, j = 0, k = 0;
    while (i < a_l && j < b_l)
    {
        if (a[i] <= b[j])
        {
            out[k] = a[i];
            i++;
        }
        else
        {
            out[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < a_l)
    {
        out[k] = a[i];
        i++;
        k++;
    }
    while (j < b_l)
    {
        out[k] = b[j];
        j++;
        k++;
    }
}
//a хүснэгтийн begin-ээс end завсарт орших элементүүдийг эрэмбэл
void merge_sort(int *a, int begin, int end)
{
    if (begin < end)
    {
        int mid = (begin + end) / 2;
        int n1 = mid - begin + 1;
        int n2 = end - mid;
        int arr1[n1], arr2[n2];
        // for (int i = 0; i < n1; i++)
        // {
        //     arr1[i] = a[begin + i];
        // }
        // for (int j = 0; j < n2; j++)
        // {
        //     arr2[j] = a[mid + 1 + j];
        // }
        merge_sort(a, mid + 1, end);
        merge_sort(a, begin, mid);
        merge(a, arr1, arr2, n1, n2);
    }
}
int main()
{
    int a_l = count_integers("unSortedInput.txt");
    printf("%d\n", a_l);
    int *a = read_integers("unSortedInput.txt", a_l);
    merge_sort(a, 0, a_l - 1);
    write_integers("sortedOut.txt", a, a_l);
    printf("ehniih \n");
    for (int i = 0; i < a_l; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");
    printf("suuliinh\n");
    int b_l = count_integers("sortedInput1.txt");
    int *b = read_integers("sortedInput1.txt", b_l);
    int c_l = count_integers("sortedInput2.txt");
    int *c = read_integers("sortedInput2.txt", c_l);
    int *out = (int *)malloc(sizeof(int) * (b_l + c_l));
    merge(out, b, c, b_l, c_l);
    write_integers("mergedOut.txt", out, b_l + c_l);
    for (int i = 0; i < b_l + c_l; i++)
    {
        printf("%d  ", out[i]);
    }
    printf("\n");
    return 0;
}

//   printf("haahah\n");
//     for (int i = 0; i < b_l; i++)
//     {
//         printf("%d  ", b[i]);
//     }
//     printf("\n");
