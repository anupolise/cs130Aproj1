WordSearch: wordsearch.cpp BST.cpp Node.cpp hashTable.cpp nodeHT.cpp
	g++ BST.cpp Node.cpp hashTable.cpp nodeHT.cpp wordsearch.cpp -c
	g++ BST.o Node.o hashTable.o nodeHT.o wordsearch.o -o main
BST: BST.cpp Node.cpp
	g++ BST.cpp Node.cpp BSTTester.cpp -c
	g++ BST.o Node.o BSTTester.o -o BSTmain
HT: hashTable.cpp nodeHT.cpp
	g++ hashTable.cpp nodeHT.cpp hashTableTester.cpp -c
	g++ hashTable.o nodeHT.o hashTableTester.cpp -o HTmain

	
clean:
	rm *.o
	rm BSTmain
	rm HTmain
