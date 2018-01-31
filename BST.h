#ifndef BST_H
#define BST_H
#include "node.h"
#include <vector>

class BST
{
	private:
		node* head;
        void insert(string str, node* head);
        int search(string str, node* head);
        void rangeSearches (string a, string b, node* pointer, vector <string> * list);
	public:
		BST();
        ~BST();
		void insert(string str);
		void printInOrder(node* head);
		int countInTree(node* head);
		int search(string str);
		void readInTree(string a[],int length);
		node* getHead();
        vector <string>* rangeSearch (string a, string b);
};
#endif
