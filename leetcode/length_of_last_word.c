#include <string.h>

int find_last_index(char* s, int length) {

    // we don't need to check the last char,
    // since it's always '/0'
    length--;

    while(s[length] == ' ') {

        length--;
        // the string contains only one word,
        // without spaces behind it. That's
        // an edge case.
        if(length < 0) return 0;
    }
    return length;
}

int lengthOfLastWord(char* s){
    int original_length = strlen(s);
    int last_index = find_last_index(s, original_length);
    int ans_length = 0;
    while(last_index > -1 && s[last_index] != ' ') {
        last_index--;
        ans_length++;
    }

    return ans_length;
}
