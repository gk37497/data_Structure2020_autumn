#include <stdio.h>
int main(){
    int a[100],n,i,j;
    printf("Hedn elementtei baih ve ");
    scanf("%d",&n);
    printf("elemntuudee oruulna uu \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    int temp;
    for (i = 0; i < n-1; i++)
    {
        for( j = 0;j < n-1;j++){
            if (a[j]>a[j + 1])
            {
               temp = a[j];
               a[j] = a[j + 1];
               a[j+1] = temp; 
            }
            
        }
    }
    printf("erembelegsen husnegt\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d \n" , a[i]);
    }
}