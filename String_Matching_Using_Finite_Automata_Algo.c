#include <stdio.h>
#include <string.h>
#define charNumbers 256

int getNextState(char *pattern, int m, int state, int x)
{
    if (state < m && x == pattern[state])
        return state + 1;

    int ns, i;

    for (ns = state; ns > 0; ns--)
        if (pattern[ns - 1] == x)
        {
            for (i = 0; i < ns - 1; i++)
                if (pattern[i] != pattern[state - ns + 1 + i])
                    break;

            if (i == ns - 1)
                return ns;
        }

    return 0;
}

void computeTranstitonFunction(char *pat, int m, int tf[][charNumbers])
{
    int state, x;
    for (state = 0; state <= m; state++)
        for (x = 0; x < charNumbers; x++)
            tf[state][x] = getNextState(pat, m, state, x);
}

void search(char *pat, char *txt)
{
    int m = strlen(pat);
    int n = strlen(txt);

    int tf[m + 1][charNumbers];

    computeTranstitonFunction(pat, m, tf);

    int i, state = 0;
    for (i = 0; i < n; i++)
    {
        state = tf[state][txt[i]];
        if (state == m)
            printf("\nPattern found at index: %d", i - m + 1);
    }
}

int main()
{
    char *txt = "ABABABACABA";
    char *pat = "ABABACA";
    search(pat, txt);
    return 0;
}