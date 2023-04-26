#include <stdio.h>
#include <string.h>

#define d 10

void rabinKarp(char pattern[], char text[], int q)
{
    int m = strlen(pattern);
    int n = strlen(text);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == m)
                printf("Pattern is found at position:  %d \n", i + 1);
        }

        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if (t < 0)
                t = (t + q);
        }
    }
}

int main()
{
    char text[100];
    char pattern[100];
    int q ;

    printf("Enter the text: ");
    fgets(text, 100, stdin);
    text[strcspn(text, "\n")] = 0; // remove newline character

    printf("Enter the pattern to be searched: ");
    fgets(pattern, 100, stdin);
    pattern[strcspn(pattern, "\n")] = 0; // remove newline character

    printf("Enter a prime number: ");
    scanf("%d", &q);
    rabinKarp(pattern, text, q);
}
