#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include <stdio.h>
#include <string.h>

/*
This code takes the input string, iterates through it, 
and checks if each character is the same as the corresponding 
character in the "SOS" pattern. If it is not, 
it increments the count. 
Finally, it returns the count, which represents the number of altered characters.
*/
int marsExploration(char* s) {
    int i, count = 0;
    char *pattern = "SOS";
    int len = strlen(s);
    for (i = 0; i < len; i++) {
        if (s[i] != pattern[i % 3])
            count++;
    }
    return count;
}

int main() {
    char s[100];
    printf("Enter the received signal: ");
    scanf("%s", s);
    int result = marsExploration(s);
    printf("Number of altered letters: %d\n", result);
    return 0;
}
