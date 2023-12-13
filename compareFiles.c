#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// comparing 2 files - size of bytes else char by char
int main()
{
    FILE *fp1;
    FILE *fp2;
    char *fname1 = "test1.txt";
    char *fname2 = "test2.txt";
    int sz1, sz2;
    fp1 = fopen(fname1, "r");
    fp2 = fopen(fname2, "r");
    fseek(fp1, 0, SEEK_END);
    sz1 = ftell(fp1);
    printf("\n%d Length : ", sz1);
    fseek(fp2, 0, SEEK_END);
    sz2 = ftell(fp2);
    printf("\n%d Length : ", sz2);
    bool matched = true;
    if (sz1 != sz2)
    {
        printf("\nSize are not same!");
    }
    else
    {
        printf("\nSize is same");
        fseek(fp1, 0, SEEK_SET);
        fseek(fp2, 0, SEEK_SET);
        while (!feof(fp1))
        {
            if(fgetc(fp1) != fgetc(fp2))
            {
                matched = false;
                break;
            }
        }
        if(!matched)
        {
            printf("\nFiles are NOT same!");
        }
        else{
            printf("\nFiles are same!!");
        }
    }

    fclose(fp1);
    fclose(fp2);
    printf("\nTest line ");
    return 0;
}
