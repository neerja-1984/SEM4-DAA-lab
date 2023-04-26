#include <stdio.h>
#include <string.h>
#define d 256

void search(char pat[], char txt[], int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    int prime = 101; // prime number

    // h = d^(M-1)
    for (i = 0; i < M-1; i++)
        h = (h*d)%prime;

    // calculate hash value of pattern and first window of text
    for (i = 0; i < M; i++) {
        p = (d*p + pat[i])%prime;
        t = (d*t + txt[i])%prime;
    }

    // slide the pattern over text one by one
    for (i = 0; i <= N - M; i++) {
        // check hash values of current window of text and pattern
        if (p == t) {
            // check for characters one by one
            for (j = 0; j < M; j++) {
                if (txt[i+j] != pat[j])
                    break;
            }
            if (j == M)
                printf("Pattern found at index %d\n", i+1);
            else
            {
                printf("Pattern not found\n");
            }
        }
        // calculate hash value for next window of text
        if (i < N-M) {
            t = (d*(t - txt[i]*h) + txt[i+M])%prime;

            // t could be negative, so if it's negative, make it positive
            if (t < 0)
                t = (t + prime);
        }
    }
}

int main()
{
    char txt[100];
    char pat[100];
    int q;
    
    printf("Enter the text: ");
    fgets(txt, 100, stdin);
    txt[strcspn(txt, "\n")] = 0; // remove newline character

    printf("Enter the pattern to be searched: ");
    fgets(pat, 100, stdin);
    pat[strcspn(pat, "\n")] = 0; // remove newline character

    printf("Enter a prime number: ");
    scanf("%d", &q);

    search(pat, txt, q);
    return 0;
}
