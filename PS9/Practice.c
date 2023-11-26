#include <stdio.h>
#include <string.h>
int main()
{

    char c = 'A';      // Single character
    printf("%c\n", c); // Prints the single character

    char c1[4] = {'A', 'B', 'C', '\0'}; // array of characters
    printf("%s\n", c1);                 // Prints elements of array as a string

    char c2[2][7] = {"Merlin", "Maha"};       // 2d array of characters
    char *ptr[2] = {"Merlin", "Mahalakshmi"}; // Pointer to a array of 2 characters //Size of each string can be anything(it is not limited)
    for (int i = 0; i < 2; i++)
    {
        printf("%s ", c2[i]); // Prints 2d array elements as string
    }
    printf("\n");
    for (int i = 0; i < 2; i++)
    {
        printf("%s ", ptr[i]); // Another way to print elements as string using pointer
    }
    printf("\n");

    char str[9] = "practice"; // string //null will be automatically included //Still limited by size
    char *ptr1 = str;         // assigning array name as a pointer
    for (int i = 0; i < 8; i++)
    {
        printf("%c", *(ptr1 + i)); // Printing array elements as string using pointer
    }
    printf("\n");
    int j = 0;
    while (*(ptr1 + j) != '\0')
    {
        printf("%c", *(ptr1 + j));
        j++;
    }
    printf("\n");
    char *str1 = "Hello World"; // String literal in pointers
    printf("%s\n", str1);       // prints the value in string literal as a string

    char arr[] = "Welcome"; // storing using an array
    printf("%s\n", arr);

    char *str2 = "SampleString\0"; // storing using a pointer
    printf("%s\n", str2);

    char *c3[4] = {"Apple", "Orange", "Banana", "Kiwi"}; // Array of 4 pointers of string of variable length
    for (int j = 0; j < 4; j++)
    { // To access each elements of the character pointer
        int i = 0;
        while (*(c3[j] + i) != '\0')
        { // To access each character of each element in the character pointer
            printf("%c", *(c3[j] + i));
            i++;
        }
        printf("\n");
    }

    // Get user input
    /*char d;
    printf("Enter a single character:");
    scanf("%c",&d);
    printf("%c\n",d);
    getchar(); //ignore in c

    char *d1;
    printf("Enter character(pointer) : ");
    scanf("%c",&d1);
    printf("%c\n",d1);
    getchar();

    int size;
    printf("Enter size of word : ");
    scanf("%d",&size);
    getchar(); //To ignore enter
    char d2[size];
    printf("Enter the word : ");
    gets(d2); //fgets(d2,size+1,stdin) can be used
    printf("String is : %s",d2);*/

    char *d3;
    d3 = (char *)malloc(5 * sizeof(char));
    printf("Enter a string literal to a pointer :");
    scanf("%s", d3);
    printf("%s", d3);

    return 0;
}
