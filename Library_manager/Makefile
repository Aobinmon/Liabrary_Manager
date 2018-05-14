CC = g++
CFLAGS = -std=c++11 -g
UH = Administrator.h Guest.h
RH = Record.h
BH = Book.h Reference.h
FC = Record_func.o Record_func.o Password_func.o

.PHONY : clean

all: main

main: main.o $(FC)
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.exe $(UH) $(RH) 
	$(CC) $(CFLAGS) -c $< -o $@

Record_func.o: Record_func.cpp $(UH) $(RH) 
	$(CC) $(CFLAGS) -c $< -o $@

Book_func.o: Book_func.cpp $(UH) $(BH)
	$(CC) $(CFLAGS) -c $< -o $@

Password_func.o: Password_func.cpp $(UH)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o main
