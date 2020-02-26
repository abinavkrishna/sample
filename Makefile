test: motorControl.o
	gcc motorControl.o -o test

motorControl.o: motorControl.c motorControl.h
	gcc -c motorControl.c  

clean: 
	-rm *.o

run: test
	./test


