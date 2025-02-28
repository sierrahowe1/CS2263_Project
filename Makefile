

GCC = gcc
CFLAGS = -g -Wall -Wshadow
SRCS = student.c main.c 
OBJS = student.o main.o
TARGET = grade_management

all: $(TARGET)

$(TARGET): $(OBJS)
           $(GCC) $(CFLAGS) $(OBJS) -o $(TARGET)

.c.o:
           $(GCC) $(CFLAGS) -c $*.c

test: $(TARGET)
      ./$(TARGET) --test


clean:
       rm -f $(OBJS) $(TARGET)

                  
