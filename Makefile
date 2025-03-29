GCC = gcc
CFLAGS = -g -Wall -Wshadow
SRCS = csvStudent.c main.c 
OBJS = csvStudent.o main.o
TARGET = grade_management
TEST_FILE = csvStudent.c test.c
TEST_OBJS = csvStudent.o test.o
TEST_TARGET = test_management


all: $(TARGET)


$(TARGET): $(SRCS)
	$(GCC) $(CFLAGS) $(SRCS) -o $(TARGET) -lm


.c.o:
	$(GCC) $(CFLAGS) -c $*.c


test: $(TEST_TARGET)
	./$(TEST_TARGET)


$(TEST_TARGET): $(TEST_FILE)
	$(GCC) $(CFLAGS) $(TEST_FILE) -o $(TEST_TARGET) -lm


clean:
	rm -f $(OBJS) $(TARGET) $(TEST_OBJS) $(TEST_TARGET)

                  
