#ifndef BST_H
#define BST_H
#include "node.h"

class BST
{
	private:
		node* head;

	public:
		BST();
		void insertR(int num, node* head);
		void printInOrder(node* head);
		int countInTree(node* head);
		bool findVal(int num, node* head);
		void readInTree(int a[],int length);
		node* getHead();

};
#endif