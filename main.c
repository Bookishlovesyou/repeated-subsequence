#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "repeated_subsequence.h"

int main(void) {
    char text[INPUT_SIZE];
    char result[INPUT_SIZE];
    size_t repetitions;

    printf("Input the words: ");
    while (!read_line(text, sizeof(text)) || strlen(text) <= 2) {
        if (feof(stdin)) {
            fprintf(stderr, "\nUnable to read input.\n");
            return EXIT_FAILURE;
        }
        printf("The length of the string must be greater than 2. Input another string: ");
    }
    to_lower_ascii(text);

    printf("Input the number of subsequences: ");
    while (!read_repetitions(&repetitions)) {
        if (feof(stdin)) {
            fprintf(stderr, "\nUnable to read the number of repetitions.\n");
            return EXIT_FAILURE;
        }
        printf("The number of subsequences must be between 1 and %d. Input another value: ",
               MAX_REPETITIONS);
    }

    find_longest_repeated_subsequence(text, repetitions, result, sizeof(result));
    printf("Longest subsequence repeated %zu times: %s\n", repetitions, result);

    return EXIT_SUCCESS;
}
