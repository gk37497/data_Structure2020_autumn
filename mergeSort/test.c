#include <stdio.h>
#include <stdlib.h>
// #include "file.h"
int largeXY(int *a, int *b)
{
    if (a > b)
    {
        return *a;
    }
    else
    {
        return *b;
    }
}
int main()
{
    int x = 4, y = 6;
    printf("hamgiin ih ni %d\n", largeXY(&y, &x));
}
// #include <stdio.h>
// #include "file.h"
// int main()
// {

//     FILE *fp;
//     int i = 1, j = 2, k = 3, num;
//     fp = fopen("test.txt", "w");
//     putw(i, fp);
//     putw(j, fp);
//     putw(k, fp);
//     fclose(fp);

//     fp = fopen("test.txt", "r");

//     while (fgetc(fp) != EOF)
//     {
//         num = getw(fp);
//         printf("%c\n", num);
//     }
//     fclose(fp);
//     return 0;
// }