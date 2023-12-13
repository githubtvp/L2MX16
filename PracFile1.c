#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s
{
    int rollNo;
    char *name; 
};

typedef struct s student;

int main()
{
    FILE *fp;
    int n = 2; // Assuming you want to read up to 4 records
    student *s1 = malloc(n * sizeof(student));
    student *s2 = malloc(n * sizeof(student));
    for (int i = 0; i < n; i++)
    {
        s1[i].name = (char *)malloc(100 * sizeof(char));
    }

    for (int i = 0; i < n; i++)
    {
        s2[i].name = (char *)malloc(100 * sizeof(char));
    }
    // Open file for writing
    fp = fopen("test.txt", "w");

    if (fp == NULL)
    {
        printf("\nError opening file for write");
        return 1; // Exit the program if file opening fails
    }

    // Writing data to the file
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter stud Roll No: \n");
        scanf("%d", &s1[i].rollNo);
        getchar(); // Consume the newline character left in the input buffer
        printf("\nEnter stud Name: \n");
        fgets(s1[i].name, 100, stdin);
        s1[i].name[strlen(s1[i].name) - 1] = '\0';
        // gets(s1[i].name);
        fprintf(fp, "%d %s\n", s1[i].rollNo, s1[i].name);
    }

    // Close the file
    fclose(fp);
    printf("\n\nStud list in S1 : ");
    for (int i = 0; i < n; i++)
    {
        printf("\nRoll No : %d", s1[i].rollNo);
        printf("\nStud Name :%s\n", s1[i].name);
    }
    printf("\n");

    // Open file for reading and storing in s2
    fp = fopen("test.txt", "r");
    if (fp == NULL)
    {
        printf("\nError opening file for read");
        return 1; // Exit the program if file opening fails
    }
    printf("\nRead from file and store in s2: ");
    // use fscanf(fp, "%d", theVarname) like scanf
    int i = 0;
    while (fscanf(fp, "%d %[^\n]s", &s2[i].rollNo, s2[i].name) != EOF)
    {
        i++;
    }
    // Close the file
    fclose(fp);

    // try and read an entoire line from file
    //  Open file for reading and storing in s2
    char newLn[100];
    fp = fopen("test.txt", "r");
    if (fp == NULL)
    {
        printf("\nError opening file for read");
        return 1; // Exit the program if file opening fails
    }
    printf("\nReads a whole line from file : ");
    while (fgets(newLn, sizeof(newLn), fp) != NULL) {
        printf("\n%s", newLn);
    }

    printf("\nStud list in S2 after reading from file into s2 : ");
    for (int i = 0; i < n; i++)
    {
        printf("\nRoll No : %d", s2[i].rollNo);
        printf("\nStud Name :%s\n", s2[i].name);
    }

    // Free allocated memory
    free(s1);
    for (int i = 0; i < n; i++)
    {
        free(s1[i].name);
    }

    free(s2);
    for (int i = 0; i < n; i++)
    {
        free(s2[i].name);
    }
    return 0;
}
