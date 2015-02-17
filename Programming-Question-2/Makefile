# This is a comment line
# Sample makefile for compile c or c++ file

CC          = gcc
CX          = g++
CFLAGS      = -g -Wall
CXXFLAGS    = -g -Wall -ansi
CPPFLAGS    = -Wall -ansi -g
SRCS        = main.cpp
OBJS        = $(SRCS:.cpp=.o)
EXECUTABLE  = HW2

all: $(OBJS)
	$(CX) $(CFLAGS) -o $(EXECUTABLE) $(OBJS)

$(OBJS): $(SRCS)
	$(CX) $(CXXFLAGS) -c $(SRCS)

clean:
	rm *.o *~ $(EXECUTABLE)
