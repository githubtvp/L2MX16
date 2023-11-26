#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include <stdio.h>
#include <stdbool.h>
#define SIZE 256

/*
This code initializes two arrays s_map and t_map to keep track of the character mapping. 
It then iterates through the strings s and t, checking if the mapping is valid. 
If it finds any inconsistency, it returns false. Otherwise, 
if the entire strings are traversed successfully, it returns true.
*/
bool areIsomorphic(char* s, char* t) {
    int s_len = 0, t_len = 0;
    int s_map[SIZE] = {0};
    int t_map[SIZE] = {0};

    while (s[s_len] && t[t_len]) {
        if (s_map[s[s_len]] != t_map[t[t_len]]) {
            return false;
        }
        s_map[s[s_len]] = t_map[t[t_len]] = s_len + 1;
        s_len++;
        t_len++;
    }

    if (s[s_len] || t[t_len]) {
        return false;
    }

    return true;
}

int main() {
    char *s1 = "egg";
    char *t1 = "add";
    char *s2 = "foo";
    char *t2 = "bar";

    printf("Example 1: %s\n", areIsomorphic(s1, t1) ? "true" : "false");
    printf("Example 2: %s\n", areIsomorphic(s2, t2) ? "true" : "false");

    return 0;
}
