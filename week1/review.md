1. `#include <stdio.h>` provides declarations for standard I/O functions, including `printf`.
2. Comments explain purpose, assumptions, or non-obvious decisions; the compiler ignores them after preprocessing.
3. Indentation helps people see structure. C treats whitespace as a separator, not as block structure; braces determine blocks.
4. The implementation's limits are `INT_MIN` and `INT_MAX` from `<limits.h>`. Standard C requires `int` to cover at least −32767 through 32767; do not assume a specific bit width.
5. `7` is an integer constant; `'7'` is an integer character constant representing the character's code; `"7"` is an array of two characters, `'7'` and the null terminator.
6. `123` is an integer constant; `"123"` is a character array containing three digits and `\0`.
7. A semicolon terminates an expression statement or declaration; its role varies in other syntax, such as separating the clauses of a `for` loop.
