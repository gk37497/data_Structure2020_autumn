#include <stdio.h>

int main()
{
    int A[100], n, i, j, pos, t;

    printf("Elementiin toogooo oruulna uu = ");
    scanf("%d", &n);

    printf("Husnegtiin %d elementee oruulana uu : \n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    for (i = 0; i < (n - 1); i++){
        pos = i;

        for (j = i + 1; j < n; j++){
            if (A[pos] > A[j])
                pos = j;
        }
        if (pos != i)
        {
            t = A[i];
            A[i] = A[pos];
            A[pos] = t;
        }
    }

    printf("Erembelegdsen husnegt:\n");

    for (i = 0; i < n; i++)
        printf("%d\n", A[i]);

    return 0;
}