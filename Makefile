CC = cc
CFLAGS = -std=c11 -Wall -Wextra -Werror -pedantic
BINS = build/week1 build/week2 build/week3 build/week4

.PHONY: all test clean
all: $(BINS)

build/week%: week%/exercises.c
	@mkdir -p build
	$(CC) $(CFLAGS) $< -lm -o $@

test: all
	python3 tests/check.py

clean:
	rm -rf build
