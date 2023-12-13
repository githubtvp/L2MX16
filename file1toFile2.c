#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>


int main()
{
    FILE *fp1, *fp2;
    char fname1[100] = "test.txt";
    char fname2[100] = "test2.txt";
    fp1 = fopen(fname1, "r");
    fp2 = fopen(fname2, "w");
    if(fp1 == NULL || fp2 == NULL)
    {
        return 1;
    }
    char c;
    while(fscanf(fp1, "%c", &c) != EOF)
    {
        c = toupper(c);
        fprintf(fp2, "%c", c);
    }

    fclose(fp1);
    fclose(fp2);
    printf("\nTest line ");
    return 0;
}