#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (){

    printf("HHAHHAAH = ");
    int a = 0;
    char b[100] = "DRS7183439";
    char c[11];
    for (int i = strlen(b) - 1; i >= 0; i--)
    {
        c[a] = b[i];
        a++;
    }
    int k = atoi(c); 
    printf(" %s\n" ,c);
    printf("HHAHHAAH = ");
    printf("%d \n" ,k % 13);
}