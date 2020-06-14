
test: test.c keygen.o
	gcc -ggdb -lm -o $@ $^ 

keygen.o: keygen.c keygen.h
	gcc -c $^

clean:
	rm test *.o *.gch
