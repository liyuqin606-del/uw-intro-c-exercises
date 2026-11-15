#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 2) { fprintf(stderr, "usage: week1 1..4\n"); return 1; }
    switch (atoi(argv[1])) {
    case 1: puts("Hello, world!"); break;
    case 2:
        for (int i = 0; i < 10; i += 2) printf("%d ", i); puts("");
        for (int i = 100; i >= 0; i -= 7) printf("%d ", i); puts("");
        for (int i = 1; i <= 10; i++) printf("%d ", i); puts("");
        for (int i = 2; i < 100; i *= 2) printf("%d ", i); puts("");
        break;
    case 3: for (int i = 1; i <= 10; i++) printf("%d\t%d\n", i, i * i); break;
    case 4:
        for (int i = 1; i <= 10; i++) { for (int j = 0; j < i; j++) putchar('*'); putchar('\n'); }
        break;
    default: return 1;
    }
    return 0;
}
