#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search(char pattern[], char text[])
{
    int lengthPattern = strlen(pattern);
    int lengthText = strlen(text);

    for (int i = 0; i <= lengthText - lengthPattern; i++)
    {
        int j;
        for (j = 0; j < lengthPattern; j++)
            if (text[i + j] != pattern[j])
                break;

        if (j == lengthPattern)
            printf("Pattern found at index %d\n", i);
    }
}
int main()
{
    // char txt[100], pat[100];
    // printf("Enter the input string: \n");
    // fgets(txt, sizeof(txt), stdin);
    // printf("Enter the pattern string: \n");
    // fgets(pat, sizeof(pat), stdin);

    // search(pat, txt);

    char txt1[] = "AABAACAADAABAABA";
    char pat1[] = "AABA";
    printf("Example 1:\n");
    search(pat1, txt1);
    return 0;
}