CC = clang
TARGET = program

$(TARGET): X.o main.o list.o sort.o X.o
	$(CC) $^ -o $(TARGET)

main.o: main.c
	$(CC) -c -Wall -Wextra -o $@ $^

list.o: list.c 
	$(CC) -c -Wall -Wextra -o $@ $^

X.o: X.c
	$(CC) -c -Wall -Wextra -o $@ $^

sort.o: sort.c 
	$(CC) -c -Wall -Wextra -o $@ $^

.PHONY: clean cleanall

clean:
	rm -rf *.o

cleanall: clean
	rm -rf $(TARGET)