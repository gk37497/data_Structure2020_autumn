#include <stdio.h>
int main(){
    int a[100],i,j,n,temp,k;
    printf("Hedn elementtei baih ve ");
    scanf("%d",&n);
    printf("elemntuudee oruulna uu \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    //sorting
    for ( i = 0; i < n - 1; i++)
    {
        temp  = i;
        for ( j = i + 1; j < n ; j++)
        {
            if (a[temp] > a[j])
            {
                temp = j;
            }
        }
        if (temp != i)
        {
            k = a[i];
            a[i] = a[temp];
            a[temp] = k;
            
        }    
    }
    printf("erembelegsen husnegt\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d \n" , a[i]);
    }
    
}