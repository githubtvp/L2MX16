#include <stdio.h>
#include <stdlib.h>

// Function to count the number of words in a line
int countWords(char *line) {
    int count = 0;
    int inWord = 0;  // Flag to track if we are inside a word

    while (*line) {
        if (*line == ' ' || *line == '\t' || *line == '\n') {
            // If current character is space, tab, or newline
            if (inWord) {
                // If we were inside a word, increment word count
                count++;
                inWord = 0;  // Set the flag to indicate we are outside a word now
            }
        } else {
            // If current character is not space, tab, or newline
            inWord = 1;  // Set the flag to indicate we are inside a word
        }

        line++;  // Move to the next character in the line
    }

    // If the last word is not followed by a space, tab, or newline
    if (inWord) {
        count++;
    }

    return count;
}

int main() {
    char inputLine[100];

    printf("Enter a line of text: ");
    fgets(inputLine, sizeof(inputLine), stdin);

    // Count the number of words in the input line
    int wordCount = countWords(inputLine);

    printf("Number of words in the line: %d\n", wordCount);

    return 0;
}

