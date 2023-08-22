#include <stdio.h>
#include <stdlib.h>

#define THREE_LENGTH 5

int get_string_length(const char* string) {
    int length = 0;
    while(string[length++] != '\0');
    return length - 1;
}

int main(void) {
    int num_words = 0;
    scanf("%d", &num_words);

    while(num_words--) {
        char* word = malloc(THREE_LENGTH * sizeof(char));

        scanf("%s", word);

        int length = get_string_length(word);
        if(length == THREE_LENGTH) {
            printf("3\n");
            free(word);
            continue;
        }

        if (
            word[0] == 'o' && word[2] == 'e'||
            word[0] == 'o' && word[1] == 'n' ||
            word[1] == 'n' && word[2] == 'e'
           ) {
            printf("1\n");
        } else printf("2\n");

        free(word);
    }

    exit(0);
}
