#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define MAXSZ 100

int main()
{
    char str[MAXSZ], pat[MAXSZ];
    printf("\nEnter the input string :  \n");
    fgets(str, MAXSZ, stdin);
    // puts(str);
    int theLen = strlen(str);
    printf("\nThe str length : %d\n", theLen);
    printf("\nEnter the pattern string :  \n");
    scanf("%s", pat);
    int patSz = strlen(pat);
    int matchArr[theLen - strlen(pat)];
    bool match = true;
    // printf("\nLen of matchArr : %d", sizeof(matchArr)/sizeof(int));
    for (int i = 0; i < (theLen - patSz); i++)
    {
        if (pat[i] == str[i])
        {
            printf("\nMatch found at : %d", i);
            for (int j = i + 1; j <= patSz - 1; j++)
            {

                if (pat[j] == str[j])
                {
                }
                else
                {
                    printf("\nAll Char don't match ");
                    match = false;
                    i = j;
                    break; // inner for loop
                }

                // printf("%c", str[j]);
            }
            //  printf("\n");
        }
    }

    return 0;
}
