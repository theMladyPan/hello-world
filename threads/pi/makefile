CC=g++
CFLAGS=-Wall -std=c++11
TARGET=pi
ARGS=-lpthread

all:$(TARGET)

$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).o $(ARGS)
	@echo Succesfully compiled.

$(TARGET).o: $(TARGET).cpp
	$(CC) $(CFLAGS) -c $(TARGET).cpp

clean:
	$(RM) $(TARGET) *.o
	$(RM) $(TARGET) *.out
