#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool substring_exists(char* str, char* target, int index, int str_length, int target_length) {
    int i = index;
    int j = 0;
    for(; j < target_length; i++, j++) {
        if(str[i] != target[j]) return false;
    }
    return i = j + index ? true : false;
}

int strStr(char * haystack, char * needle){
    const int str_length = strlen(haystack);
    const int target_length = strlen(needle);
    char first_char_needle = needle[0];
    for(int i = 0; i < str_length; i++) {
        if(first_char_needle == haystack[i]) {
            if(substring_exists(haystack, needle, i, str_length, target_length)) {
                return i;
            }
        }
    }
    return -1;
}
