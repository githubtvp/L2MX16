#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//We will define a function beautySum that calculates the sum of beauty of all substrings of the given string.
/*This code defines the beautySum function that calculates the sum of beauty for all substrings of the input string s. 
The function utilizes a nested loop structure to iterate through all substrings and compute their beauty values. 
The main function provides an example usage of the beautySum function for the string "aabcb".
*/
int beautySum(char *s) {
    int len = strlen(s);
    int res = 0;

    for (int i = 0; i < len; i++) {
        int charCount[26] = {0};
        for (int j = i; j < len; j++) {
            charCount[s[j] - 'a']++;
            int maxFreq = 0, minFreq = len;
            for (int k = 0; k < 26; k++) {
                if (charCount[k] > 0) {
                    maxFreq = charCount[k] > maxFreq ? charCount[k] : maxFreq;
                    minFreq = charCount[k] < minFreq ? charCount[k] : minFreq;
                }
            }
            res += maxFreq - minFreq;
        }
    }

    return res;
}

int main() {
    char s[] = "aabcb";
    printf("Output: %d\n", beautySum(s));
    return 0;
}
