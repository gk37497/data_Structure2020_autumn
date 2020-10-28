#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>
// url файлыг уншихаар нээж, эхний size бүхэл тоог уншин хүснэгтэд хадгалан буцаана
int *read_integers(char *url, int size)
{
    int *b, c, i = 0;
    FILE *file;
    file = fopen(url, "r");
    b = (int *)malloc(sizeof(int) * size);
    while (i < size)
    {
        fscanf(file, "%d", &b[i]);
        i++;
    }
    fclose(file);
    return b;
}
// url файлыг уншихаар нээж нийт хичнээн бүхэл тоо байгааг тоолон буцаана
int count_integers(char *url)
{
    int c, size = 0;
    FILE *file;
    file = fopen(url, "r");
    while (1)
    {
        if (fscanf(file, "%d", &c) == EOF)
        {
            break;
        }
        size++;
    }
    fclose(file);
    return size;
}

// url файлыг бичихээр нээж, size тооны утгатай а хүснэгтийн бүх утгыг зайгаар тусгаарлан бич
void write_integers(char *url, int *a, int size)
{
    FILE *file;
    file = fopen(url, "r");
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%d ", a[i]);
    }
    fclose(file);
}
#endif
