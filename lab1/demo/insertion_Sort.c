#include <stdio.h>
int main(){
    int a[100],n,i,j,temp;
    printf("Hedn elementtei baih ve ");
    scanf("%d",&n);
    printf("elemntuudee oruulna uu \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    for ( i = 1; i < n; i++)
    {
        for ( j = i - 1; j >= 0; j--)
        {
            if (a[i] < a[j])
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }          
        }
        
    }
    printf("erembelegsen husnegt\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d \n" , a[i]);
    }
    
}//dutuu