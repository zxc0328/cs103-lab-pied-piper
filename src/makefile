CC=g++
CFLAGS=-c -std=c++11

pipedpiper : main.o huffmanNode.o encoding.o utility.o
	$(CC) -std=c++11 -o pipedpiper main.o huffmanNode.o encoding.o utility.o

main.o : main.cpp encoding.h
	$(CC) $(CFLAGS) main.cpp

huffmanNode.o : HuffmanNode.cpp HuffmanNode.h
	$(CC) $(CFLAGS) HuffmanNode.cpp

encoding.o : encoding.cpp encoding.h
	$(CC) $(CFLAGS) encoding.cpp

utility.o : utility.cpp utility.h HuffmanNode.h
	$(CC) $(CFLAGS) utility.cpp

clean :
	rm pipedpiper huffmanNode.o encoding.o utility.o