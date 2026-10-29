#include "repeated_subsequence.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_line(char text[], size_t size) {
    size_t length;

    if (size == 0 || fgets(text, size, stdin) == NULL) {
        return 0;
    }

    length = strcspn(text, "\n");
    if (text[length] == '\n') {
        text[length] = '\0';
    } else {
        int character;
        while ((character = getchar()) != '\n' && character != EOF) {
        }
    }

    return 1;
}

void to_lower_ascii(char text[]) {
    for (size_t i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (char)(text[i] - 'A' + 'a');
        }
    }
}

static size_t repeated_subsequence_count(
    const char subsequence[],
    const char text[]
) {
    size_t subsequence_length = strlen(subsequence);
    size_t subsequence_index = 0;
    size_t count = 0;

    if (subsequence_length == 0) {
        return 0;
    }

    for (size_t i = 0; text[i] != '\0'; i++) {
        if (subsequence[subsequence_index] == text[i]) {
            subsequence_index++;
            if (subsequence_index == subsequence_length) {
                count++;
                subsequence_index = 0;
            }
        }
    }

    return count;
}

void find_longest_repeated_subsequence(
    const char text[],
    size_t repetitions,
    char result[],
    size_t result_size
) {
    size_t max_length = 0;
    size_t text_length = strlen(text);
    char candidate[INPUT_SIZE];

    if (result_size == 0) {
        return;
    }
    result[0] = '\0';

    for (size_t start = 0; start < text_length; start++) {
        for (size_t end = start + 1; end <= text_length; end++) {
            size_t candidate_length = end - start;

            memcpy(candidate, &text[start], candidate_length);
            candidate[candidate_length] = '\0';

            if (repeated_subsequence_count(candidate, text) >= repetitions &&
                (candidate_length > max_length ||
                 (candidate_length == max_length &&
                  strcmp(candidate, result) > 0))) {
                if (candidate_length + 1 > result_size) {
                    return;
                }

                max_length = candidate_length;
                memcpy(result, candidate, candidate_length + 1);
            }
        }
    }
}

int read_repetitions(size_t *repetitions) {
    char input[32];
    char *end;
    unsigned long value;

    if (!read_line(input, sizeof(input))) {
        return 0;
    }

    errno = 0;
    value = strtoul(input, &end, 10);
    if (errno == ERANGE || end == input || *end != '\0' ||
        value == 0 || value > MAX_REPETITIONS) {
        return 0;
    }

    *repetitions = (size_t)value;
    return 1;
}
