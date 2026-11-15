1. `c = getchar() != EOF` assigns the result of the comparison (0 or 1) to `c`, because `!=` binds more tightly than assignment. Use `(c = getchar()) != EOF` to keep the character.
2. `getchar` returns an `unsigned char` value converted to `int`, or `EOF`; an `int` can represent both without confusing a valid byte with the sentinel.
3. Prefix increment yields the new value; postfix yields the old value. Both increment the operand.
4. `i = i++` has undefined behavior in C: the two modifications of `i` are unsequenced relative to each other. Do not infer a particular result.
5. A C string is a sequence of characters ending at its first `\0`, stored in an array large enough for the terminator.
6. The course's `getline` returns 3 and stores `abc\0`; a subsequent call returns EOF. This is reasonable: files can end without a final newline. The implementation used here is named `read_line` to avoid conflict with POSIX `getline`.
