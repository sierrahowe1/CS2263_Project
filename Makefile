GCC = gcc
CFLAGS = -g -Wall -Wshadow
SRCS = csvStudent.c main.c 
OBJS = csvStudent.o main.o
TARGET = grade_management

all: $(TARGET)

$(TARGET): $(SRCS)
	$(GCC) $(CFLAGS) $(SRCS) -o $(TARGET)

.c.o:
	$(GCC) $(CFLAGS) -c $*.c

test: $(TARGET)
	./$(TARGET) --test

clean:
	rm -f $(OBJS) $(TARGET)

                  
