BST: BST.cpp Node.cpp
	g++ BST.cpp Node.cpp -c
	g++ BST.o Node.o -o BSTmain
HT: hashTable.cpp nodeHT.cpp
	g++ hashTable.cpp nodeHT.cpp -c
	g++ hashTable.o nodeHT.o -o HTmain	
clean:
	rm *.o
	rm BSTmain
	rm Human
