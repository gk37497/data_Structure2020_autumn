#include <stdio.h>

int main()
{
    int n, A[1000], i, j, t, k = 0;

    printf("Elementiin toogooo oruualna uu = ");
    scanf("%d", &n);

    printf("Husnegtiin %d elementee oruulana uu : \n", n);

    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    for (i = 1; i <= n - 1; i++)
    {
        t = A[i];

        for (j = i - 1; j >= 0; j--)
        {
            if (A[j] > t)
            {
                A[j + 1] = A[j];
                k = 1;
            }
            else
                break;
        }
        if (k == 1)
            A[j + 1] = t;
    }

    printf("Erembelegdsen husnegt :\n");

    for (i = 0; i <= n - 1; i++)
    {
        printf("%d\n", A[i]);
    }

    return 0;
}