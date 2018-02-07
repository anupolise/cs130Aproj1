BST: BST.cpp Node.cpp
	g++ BST.cpp Node.cpp -c
	g++ BST.o Node.o -o BSTmain
clean:
	rm *.o
	rm BSTmain
