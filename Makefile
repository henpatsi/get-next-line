all:
	rm -f test_files/output
	cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=42 tests.c get_next_line.c get_next_line_utils.c -o test.out
	leaks --atExit -q -- ./test.out

sanitize:
	cc -Wall -Wextra -Werror -g -fsanitize=address,undefined,pointer-overflow -D BUFFER_SIZE=10 tests.c get_next_line.c get_next_line_utils.c -o test.out
	./test.out

compare:
	diff test_files/correct_output.txt test_files/output.txt

test_buffers:
	echo "----- TESTING BUFFER 1 -----"
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 tests.c get_next_line.c get_next_line_utils.c -o test.out
	./test.out
	echo "----- TESTING BUFFER 10 -----"
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=10 tests.c get_next_line.c get_next_line_utils.c -o test.out
	./test.out
	echo "----- TESTING BUFFER 41 -----"
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=41 tests.c get_next_line.c get_next_line_utils.c -o test.out
	./test.out
	echo "----- TESTING BUFFER 42 -----"
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 tests.c get_next_line.c get_next_line_utils.c -o test.out
	./test.out
	echo "----- TESTING BUFFER 43 -----"
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=43 tests.c get_next_line.c get_next_line_utils.c -o test.out
	./test.out
	echo "----- TESTING BUFFER 100 -----"
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=100 tests.c get_next_line.c get_next_line_utils.c -o test.out
	./test.out
	echo "----- TESTING BUFFER 1000 -----"
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=1000 tests.c get_next_line.c get_next_line_utils.c -o test.out
	./test.out
	echo "----- TESTING BUFFER 10000000 -----"
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=10000000 tests.c get_next_line.c get_next_line_utils.c -o test.out
	./test.out