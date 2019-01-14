.PHONY: all_rebuild all clean

all_rebuild: clean all

.DEFAULT_GOAL := all_rebuild

CC = g++
CFLAGS = -w -std=c++11 -fpermissive -g

properties.o:
	g++ -c properties.cpp

properties_repo.o: properties.o
	g++ -c properties.o properties_repo.cpp

calculation.o:
	g++ -c calculation.cpp

requirement.o:
	g++ -c requirement.cpp

requirement_repo.o: requirement.o
	g++ -c requirement.o requirement_repo.cpp

OBJS := properties.o requirement.o properties_repo.o requirement_repo.o calculation.o

all: $(OBJS) main.cpp
	$(CC) $(CFLAGS) main.cpp $(OBJS)  -o output -v

clean:
	rm -vrf *.o output *.dSYM
