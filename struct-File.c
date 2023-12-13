#include <stdio.h>
#include <conio.h>

struct s
{
    char name[50];
    int height;
};

int main()
{
    int n;
    n = 2;
    struct s a[n], b[n];
    FILE *fptr;
    int i;

    //clrscr();

    fptr = fopen("file.txt", "w");

    for (i = 0; i < n; ++i)
    {
        printf("Enter name: ");
        gets(a[i].name);
        printf("Enter height: ");
        scanf("%d", &a[i].height);
    }

    fwrite(a, sizeof(a), 1, fptr);
    fclose(fptr);

    fptr = fopen("file.txt", "r");
    fread(b, sizeof(b), 1, fptr);

    for (i = 0; i < n; ++i)
    {
        printf("Name: %s\nHeight: %d\n", b[i].name, b[i].height);
    }
    fclose(fptr);
    getch();
    return 0;
}
