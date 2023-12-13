#include <stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("file1.txt", "w");

    if (fp == NULL)
    {
        printf("Error in opening file\n");
    }
    else
    {
        fputs("I am supporter of France.", fp);
        fseek(fp, 18, SEEK_SET);
        fputs("Brazil", fp);
        fseek(fp, 0, SEEK_CUR);
        fputs(" and Portugal", fp);
        fclose(fp);
    }

    return 0;
}
