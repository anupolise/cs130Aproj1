#ifndef hashTable_H
#define hashTable_H
#include "nodeHT.h"

class hashTable
{
	private:
		nodeHT *hashTbl;
		int size;
        int indexOf(string str);
        int hashFunction(); 
	public:
		hashTable();
		hashTable(int size);
        int hash(string str);
		//void sortInOrder();
		int countInTable();
		void printTable();
		int search(string str);
        void insert(string str);
		void readInTable(string a[],int length);
		//void deleteInTable(string str);


};
#endif
