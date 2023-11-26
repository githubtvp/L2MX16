#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void getInput(char *arr);
int getLength(char *arr);
int main()
{
    char lStr[MAX];
    char sStr[MAX];
    char wordsLs[MAX][MAX];
    printf("\nEnter the long string : ");
    getInput(lStr);
    int loLen = strlen(lStr) - 1;
    int stI = 0;
    int wCol = 0;
    int wRow = 0;
    for (int i = 0; i < loLen; i++)
    {
        if (lStr[i] == ' ' || (i == loLen - 1))
        {
            if (i == loLen - 1)
                i++;
            // printf("%d ,  (i -stI) : %d", i, (i-stI));
            for (int j = stI; j < i; j++)
            {
                wordsLs[wRow][wCol] = lStr[j];
                wCol++;
                //  printf("%c", lStr[j]);
            }
            wordsLs[wRow][wCol] = '\0';
            for (int i = 0; i < wCol; i++)
            {
                printf("%c", wordsLs[wRow][i]);
            }
            printf("\n");
            wCol = 0;
            wRow++;
            // printf(" ");
            stI = i + 1;
            //   printf("\n After   %d", stI);
        }
    }

    printf("\n1. After  ...\n");
    for (int i = 0; i < wRow; i++)
    {

        int wdLen = strlen(wordsLs[wRow][0]);
        printf("\n2. After  ... %d\n", wdLen);
        for (int i = 0; i < wdLen; i++)
        {
            printf("%c", wordsLs[wRow][i]);
        }
        printf("\n");
    }
    //  printf("\nEnter the short string : ");
    //  getInput(sStr);
    // int len1 = strlen(lStr);

    //  int shLen = strlen(sStr) - 1;
    //    printf("\n Length long string : %d", loLen);
    //    printf("\n Length Short string : %d", shLen);
    char *loc;
    //   loc = strstr(lStr, sStr); // !=null )
    //   printf("\nLoc : %s", loc);
    //    printf("\nTest line PS8 Qsn 4");
}

int getLength(char *arr)
{
    int count = 0;
    while (arr[count] != '\0' && arr[count] != '\n')
    {
        count++;
    }
    return count;
}

void getInput(char *arr)
{
    fgets(arr, MAX, stdin);
}

/*

int countOccurrences(char *sentence, char *word) {
    int count = 0;
    int word_length = strlen(word);

    while ((sentence = strstr(sentence, word)) != NULL) {
        count++;
        sentence += word_length;
    }

    return count;
}

int main() {
    char sentence[1000];
    char word[100];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    printf("Enter the word to find: ");
    scanf("%s", word);

    int occurrences = countOccurrences(sentence, word);
    printf("The word '%s' occurs %d times in the sentence.\n", word, occurrences);

    return 0;
}
In this program:

The countOccurrences function takes two string inputs, sentence and word, and returns an integer that represents the number of occurrences of the word in the sentence.
We use the strstr function to find occurrences of the word in the sentence. It returns a pointer to the first occurrence of the word in the sentence, and we keep searching for subsequent occurrences until the end of the sentence is reached.
In the main function, we prompt the user to input the sentence and the word to find, and then we call the countOccurrences function to get the count of occurrences of the word in the sentence.
Finally, we print the count of occurrences to the console.




*/