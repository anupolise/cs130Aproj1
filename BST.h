#ifndef BST_H
#define BST_H
#include "node.h"

class BST
{
	private:
		node* head;
        void insert(string str, node* head);
        int search(string str, node* head);
	public:
		BST();
		void insert(string str);
		void printInOrder(node* head);
		int countInTree(node* head);
		int search(string str);
		void readInTree(string a[],int length);
		node* getHead();

};
#endif
