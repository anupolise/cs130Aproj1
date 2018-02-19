WordSearch: wordsearch.cpp BST.cpp node.cpp hashTable.cpp nodeHT.cpp
	g++ BST.cpp node.cpp hashTable.cpp nodeHT.cpp wordsearch.cpp -c
	g++ BST.o node.o hashTable.o nodeHT.o wordsearch.o -o main
TimeTable: timeTable.cpp BST.cpp node.cpp hashTable.cpp nodeHT.cpp
	g++ BST.cpp node.cpp hashTable.cpp nodeHT.cpp timeTable.cpp -c
	g++ BST.o node.o hashTable.o nodeHT.o timeTable.o -o TTmain

BST: BST.cpp node.cpp
	g++ BST.cpp node.cpp BSTTester.cpp -c
	g++ BST.o node.o BSTTester.o -o BSTmain
HT: hashTable.cpp nodeHT.cpp
	g++ hashTable.cpp nodeHT.cpp hashTableTester.cpp -c
	g++ hashTable.o nodeHT.o hashTableTester.cpp -o HTmain

	
clean:
	rm *.o
	rm BSTmain
	rm HTmain
	rm TTmain
