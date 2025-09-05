
CC=g++
CCFLAGS= -Wall -std=c++17

SRCS = ./src/main.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = nn

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CCFLAGS) -o $@ $^ 

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm $(OBJS) $(TARGET)

.PHONY: all clean
