#ifndef REPEATED_SUBSEQUENCE_H
#define REPEATED_SUBSEQUENCE_H

#include <stddef.h>

#define INPUT_SIZE 100
#define MAX_REPETITIONS 2000

int read_line(char text[], size_t size);
void to_lower_ascii(char text[]);
int read_repetitions(size_t *repetitions);

/*
 * Finds the longest contiguous candidate that can be matched repetitions
 * times as non-overlapping subsequences of text.
 */
void find_longest_repeated_subsequence(
    const char text[],
    size_t repetitions,
    char result[],
    size_t result_size
);

#endif
