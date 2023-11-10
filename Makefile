all:
	cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=5 tests.c get_next_line.c get_next_line_utils.c -o test.out
	./test.out