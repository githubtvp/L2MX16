#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include<stdio.h>
#include<string.h>

/*
The Knuth-Morris-Pratt (KMP) algorithm is used for pattern searching in a given text. 
It is an efficient string searching algorithm that works by preprocessing the pattern to
 identify any suffixes that are also prefixes. 
This information is then used to avoid unnecessary comparisons while searching. 
Below is the step-by-step algorithm for the KMP algorithm:

Preprocessing (Building the LPS Array):

Initialize two variables: len and i to 0.
Create an array lps[] of the same length as the pattern, where lps[i] will store the length of the
 longest proper prefix which is also a suffix in pat[0...i].
Set lps[0] to 0 as there are no proper prefixes or suffixes for a single-character string.
Iterate over the pattern pat from index 1 to the end:
If pat[i] matches pat[len], increment len and assign len to lps[i].
If there is a mismatch and len is not 0, update len using lps[len-1].
If there is a mismatch and len is 0, assign 0 to lps[i].
Increment i in each iteration.
String Matching:

Initialize variables N and M for the length of the text and the pattern, respectively.
Set two pointers i and j to 0.
While i is less than N:
If the characters at positions i and j match, increment both i and j.
If j equals M, it means a match is found. Print the current starting index (i - j) and update j using lps[j-1].
If there is a mismatch and j is not 0, update j using lps[j-1].
If there is a mismatch and j is 0, increment i.
Repeat the above steps until the end of the text is reached.
The main idea behind the KMP algorithm is to avoid unnecessary comparisons by utilizing 
the information stored in the LPS (Longest Proper Prefix which is also Suffix) array. 
This allows the algorithm to skip characters that are known to match. By doing this, 
the overall time complexity is reduced to O(N), where N is the length of the text.

*/

void computeLPSArray(char* pat, int M, int* lps);

void search(char* pat, char* txt) {
    int M = strlen(pat);
    int N = strlen(txt);

    // create lps[] that will hold the longest prefix suffix values for pattern
    int lps[M];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0;  // index for txt[]
    int j = 0;  // index for pat[]

    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("Pattern found at index %d \n", i - j);
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

// Compute the LPS (Longest Proper Prefix which is also Suffix) array
void computeLPSArray(char* pat, int M, int* lps) {
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Examples of using the search function
int main() {
    char txt1[] = "THIS IS A TEST TEXT";
    char pat1[] = "TEST";
    printf("For txt1: \n");
    search(pat1, txt1);

    printf("\n");

    char txt2[] = "AABAACAADAABAABA";
    char pat2[] = "AABA";
    printf("For txt2: \n");
    search(pat2, txt2);

    return 0;
}
