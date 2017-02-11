# You need to write this file so that
#
# "make" will create an executable called pa05
# 
# "make test" will run the three input files 
# 
# input: inputs/testinput1; output: id1, first1, last1
# input: inputs/testinput2; output: id2, first2, last2
# input: inputs/testinput3; output: id3, first3, last3
# 
# compare your program's output with the expected ouputs by
# using the "diff" command in Linux
#
# "make memory" calls valgrind to check memory errors
#
# "make clean" remove .o and all output files

CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
COVFLAGS = -fprofile-arcs -ftest-coverage
GCC = gcc $(CFLAGS) $(COVFLAGS) 
OBJ = student.o pa05.o

all: $(OBJ) student.h constant.h
		$(GCC) $(OBJ)

pa05: $(OBJ) student.h constant.h
		$(GCC) $(OBJ) -o pa05

student.o: student.c constant.h student.h
		$(GCC) -c student.c -o student.o -DTEST_WRITE -DTEST_READ -DTEST_SORTED -DTEST_SORTLASTNAME -DTEST_SORTFIRSTNAME

test: pa05
		./pa05 inputs/testinput1 id1 first1 last1
		./pa05 inputs/testinput2 id2 first2 last2
		./pa05 inputs/testinput3 id3 first3 last3
		diff ./expected/id1 id1 
		diff ./expected/first1 first1 
		diff ./expected/last1 last1 
		diff ./expected/id2 id2 
		diff ./expected/first2 first2 
		diff ./expected/last2 last2 
		diff ./expected/id3 id3 
		diff ./expected/first3 first3 
		diff ./expected/last3 last3 

memory: pa05
		valgrind --leak-check=full -v ./pa05 inputs/testinput1 id1 first1 last1
		valgrind --leak-check=full -v ./pa05 inputs/testinput2 id2 first2 last2
		valgrind --leak-check=full -v ./pa05 inputs/testinput3 id3 first3 last3


clean:
		rm -f *.o
		rm -f student.gcno
		rm -f student.gcda
		rm -f id1 first1 last1
		rm -f first1
		rm -f last1
		rm -f pa05.gcno
		rm -f pa05.gcda
		rm -f id2 first2 last2
		rm -f id3 first3 last3
		rm -f pa05
		rm -f valgrind
