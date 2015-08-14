CC = g++
FLAGS = -std=c++11

ans : ans.o
	$(CC) -o $@ $^

ans.o : ans.cpp
	$(CC) -c $(FLAGS) $^

.PHONY : clean
clean:
	rm -rf ans *.o

