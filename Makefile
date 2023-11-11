all:
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=10 tests.c get_next_line.c get_next_line_utils.c -o test.out
	leaks --atExit -q -- ./test.out