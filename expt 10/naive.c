#include <stdio.h>
#include <string.h>
 
void search(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
 
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;
        if (j == M) 
            printf("Pattern found at index %d \n", i);
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

    search(pattern, text);
    return 0;
}


