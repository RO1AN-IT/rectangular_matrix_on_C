CC=gcc
FLAGS=-Wno-error=incompatible-function-pointer-types -Wno-incompatible-function-pointer-types -Wno-visibility -Wno-incompatible-pointer-types -g -O0

program.out: new_laba1.o COMPLEX_INTEGER/complex_integer.c COMPLEX_DOUBLE/complex_double.c new_matrix_func.o INT/INT_func.o FLOAT/FLOAT_func.o DOUBLE/DOUBLE_func.o
	$(CC) -g -Wall new_laba1.o COMPLEX_INTEGER/complex_integer.c COMPLEX_DOUBLE/complex_double.c new_matrix_func.o INT/INT_func.o FLOAT/FLOAT_func.o DOUBLE/DOUBLE_func.o -o program.out

new_laba1.o: new_laba1.c
	$(CC) -c new_laba1.c $(FLAGS) -o new_laba1.o

complex_double.o: COMPLEX_DOUBLE/complex_double.c
	$(CC) -c COMPLEX_DOUBLE/complex_double.c $(FLAGS) -o COMPLEX_DOUBLE/complex_double.c

complex_integer.o: COMPLEX_INTEGER/complex_integer.c
	$(CC) -c COMPLEX_INTEGER/complex_integer.c $(FLAGS) -o COMPLEX_INTEGER/complex_integer.c

new_matrix_func.o: new_matrix_func.c
	$(CC) -c new_matrix_func.c $(FLAGS) -o new_matrix_func.o

INT_func.o: INT/INT_func.c
	$(CC) -c INT/INT_func.c $(FLAGS) -o INT/INT_func.o

FLOAT_func.o: FLOAT/FLOAT_func.c
	$(CC) -c FLOAT/FLOAT_func.c $(FLAGS) -o FLOAT/FLOAT_func.o

DOUBLE_func.o: DOUBLE/DOUBLE_func.c
	$(CC) -c DOUBLE/DOUBLE_func.c $(FLAGS) -o DOUBLE/DOUBLE_func.o

.PHONY: clean

clean:
	rm -f *.o
	rm -f COMPLEX/*.o
	rm -f INT/*.o
	rm -f FLOAT/*.o
	rm -f DOUBLE/*.o

fullclean: clean
	rm -f *.out