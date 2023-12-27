#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    FILE *fp1;
    char name[100] = "test1.txt";
    fp1 = fopen(name, "r");
    char searchStr[10] = "test";
    char *result;
    char *line;
    line = (char *)malloc(100 * sizeof(char));
    while (fgets(line, sizeof(line), fp1) != NULL)
    {
        //printf("\n%s", line);
        if(strstr(line, searchStr) != NULL)
        printf("\n%s", line);
    }

    printf("\nTest line");
    return 0;
}