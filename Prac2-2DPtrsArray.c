/*Array of Pointers of Strings
In C we can use an Array of pointers.
Instead of having a 2-Dimensional character array,
we can have a single-dimensional array of Pointers.
Here pointer to the first character of the
string literal is stored.

Syntax:

char *arr[] = { "Geek", "Geeks", "Geekfor" };
*/

// C Program to print Array
// of strings using Pointers
#include <stdio.h>

void PrintArray(char *arr[], int n);
void ReverseArray(char *arr[], int n);

int main()
{
    char *arr[] = {"Geek1", "Geeks2", "Geekfor3"};
    printf("String array Elements are:\n");

    for (int i = 0; i < 3; i++)
    {
        // printf("%s\n", arr[i]);
    }
    PrintArray(arr, 3);
    ReverseArray(arr, 3);
    PrintArray(arr, 3);
    return 0;
}

void PrintArray(char *arr[], int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s ", arr[i]);
    }
}
void ReverseArray(char *arr[], int n)
{
    char *temp;

    // Move from begin and end. Keep
    // swapping strings.
    int j = n - 1;
    for (int i = 0; i < j; i++)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--;
    }
}