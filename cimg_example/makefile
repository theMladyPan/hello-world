CC=g++
CFLAGS=-Wall -std=c++11
TARGET=test

all:$(TARGET)

$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).o -O2 -L/usr/X11R6/lib -lm -lpthread -lX11 -ljpeg
	@echo Succesfully compiled.		

$(TARGET).o: $(TARGET).cpp
	$(CC) $(CFLAGS) -c $(TARGET).cpp -O2 -L/usr/X11R6/lib -lm -lpthread -lX11

clean: 
	$(RM) $(TARGET) *.o
