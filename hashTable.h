#ifndef hashTable_H
#define hashTable_H
#include "nodeHT.h"

class hashTable
{
	private:
		int *hashTbl[];
		int size;
        void insert(string str);
        int search(string str);
        int hashFunction(); 
	public:
		hashTable();
		hashTable(int size);
		void insert(string str);
		int hash()
		void sortInOrder();
		int countInTable(node* head);
		int search(string str);
		void readInTable(string a[],int length);
		void deleteInTable(string str);


};
#endif
