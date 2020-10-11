#include <stdio.h>

int main()
{
    int A[100], n, i, j, temp;
    printf("Elementiin toogooo oruulna uu = ");
    scanf("%d", &n);

    printf("Husnegtiin %d elementee oruulana uu : \n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    for (i = 0; i < n - 1; i++){

        for (j = 0; j < n - 1; j++){
    
            if (A[j] > A[j + 1]){
                
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                
            }
        }
    }
    printf("erembelegdsen husnegt:\n");

    for (i = 0; i < n; i++)
        printf("%d\n", A[i]);

    return 0;
}