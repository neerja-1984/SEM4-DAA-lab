// performing strassen matrix multiplicaton

#include <stdio.h>
#include <time.h>
void main()
{
    int a[2][2], b[2][2], c[2][2], i, j;
    int p[7];
    int s[10];
    clock_t start, end;
    printf("Enter the elements of 1st matrix:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the elements of 2nd matrix:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    start = clock();
    s[0] = b[0][1] - b[1][1];
    s[1] = a[0][0] + a[0][1];
    s[2] = a[1][0] + a[1][1];
    s[3] = b[1][0] - b[0][0];
    s[4] = a[0][0] + a[1][1];
    s[5] = b[0][0] + b[1][1];
    s[6] = a[0][1] - a[1][1];
    s[7] = b[1][0] + b[1][1];
    s[8] = a[0][0] - a[1][0];
    s[9] = b[0][0] + b[0][1];

    // 7 strssen calculations
    p[0] = s[0] * a[0][0];
    p[1] = s[1] * b[1][1];
    p[2] = s[2] * b[0][0];
    p[3] = s[3] * a[1][1];
    p[4] = s[4] * s[5];
    p[5] = s[6] * s[7];
    p[6] = s[8] * s[9];

    // 4 final output
    c[0][0] = p[4] + p[3] - p[1] + p[5];
    c[0][1] = p[0] + p[1];
    c[1][0] = p[2] + p[3];
    c[1][1] = p[4] + p[0] - p[2] - p[6];

    for (i = 0; i < 10; i++)
    {
        printf("\nS[%d] = %d ", i + 1, s[i]);
    }
    printf("\n");
    for (j = 0; j < 7; j++)
    {
        printf("\np[%d] = %d ", j + 1, p[j]);
    }
    printf("\n\n");
    printf("MATRIX A: \n");
    for (i = 0; i < 2; i++)
    {
        printf("\n");
        for (j = 0; j < 2; j++)
        {
            printf("%d\t", a[i][j]);
        }
    }
    printf("\n");

    printf("MATRIX B: \n");
    for (i = 0; i < 2; i++)
    {
        printf("\n");
        for (j = 0; j < 2; j++)
        {
            printf("%d\t", b[i][j]);
        }
    }
    printf("\n");
    printf("MATRIX C: \n\n");
    printf("%d\t %d\n%d\t %d\n", c[0][0], c[0][1], c[1][0], c[1][1]);
    end = clock();
    printf("The time taken by the program: ");
    printf("%lf", (double)(end - start) / CLOCKS_PER_SEC);
}
