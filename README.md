# Repeated Subsequence Finder

> This is a program I first made during my first year of study. I improved it
> later by making the code safer, separating the functions into different
> files, and adding tests and documentation.

This program reads a string and a number `k`. It finds the longest contiguous
piece of the string that can be matched `k` non-overlapping times while
scanning the whole string from left to right.

Uppercase ASCII letters are converted to lowercase. If several answers have
the same length, the lexicographically larger answer is selected.

## Build and run

Compile the program:

```text
gcc -std=c11 -Wall -Wextra -Wpedantic main.c repeated_subsequence.c -o main
```

Run it:

```text
.\main.exe
```

## Example test cases

| Input string | `k` | Expected result |
|---|---:|---|
| `banana` | 2 | `na` |
| `BaNaNa` | 2 | `na` |
| `aaaaaa` | 3 | `aa` |
| `abcabcabc` | 3 | `abc` |
| `abcdef` | 2 | no result (empty output) |

## Run the automated tests

Compile the tests:

```text
gcc -std=c11 -Wall -Wextra -Wpedantic tests.c repeated_subsequence.c -o tests
```

Run them:

```text
.\tests.exe
```

The test program uses assertions and produces no output when all tests pass.
