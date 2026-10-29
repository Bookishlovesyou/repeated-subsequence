#include <assert.h>
#include <string.h>

#include "repeated_subsequence.h"

static void test_longest_result(
    const char text[],
    size_t repetitions,
    const char expected[]
) {
    char result[INPUT_SIZE];

    find_longest_repeated_subsequence(
        text,
        repetitions,
        result,
        sizeof(result)
    );
    assert(strcmp(result, expected) == 0);
}

int main(void) {
    char text[] = "BaNaNa";

    to_lower_ascii(text);
    assert(strcmp(text, "banana") == 0);

    test_longest_result("banana", 2, "na");
    test_longest_result("aaaaaa", 3, "aa");
    test_longest_result("abcdef", 2, "");
    test_longest_result("abcabcabc", 3, "abc");

    return 0;
}
