#include <stdio.h>

int main()
{
    FILE *fp;
    long int len;

    fp = fopen("file1.txt", "r");

    if (fp == NULL)
    {
        printf("Error in opening file\n");
    }
    else
    {
        fseek(fp, 0, SEEK_END);
        len = ftell(fp);
        fclose(fp);
        printf("The file contains %ld characters.\n", len);
    }

    getch();
    return 0;
}
