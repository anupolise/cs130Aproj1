#include <iostream>
#include "hashTable.h"

using namespace std;

hashTable::hashTable()
{
	hashTbl =  new nodeHT[100];
	for(int i=0; i<100; i++)
	{
		hashTbl[i] = new nodeHT();
	}
	size = 100;
}

hashTable::hashTable(int s)
{
	hashTbl = new nodeHT[s];
	for(int i=0; i<s; i++)
	{
		hashTbl[i] = new nodeHT();
	}
	size = s;
}

void hashTable::insert(string str)
{	
	int index = hash(str);

	//if the initial hash position is empty
	if(hashTbl[index].getData() = "")
	{
		hashTbl[index].setData(str);
		hashTbl[index].setCount(1);
	}

	//if the hash hashes exactly to the same value, add 1 to counter
	else if(hashTbl[index].getData().compare(str) == 0)
	{
		hashTbl[index].setCount(++hashTbl[index].getCount());
	}

	//if the initial has position isn't empty, and it's not the same val > linear probe
	else
	{
		for(int i=(++index); i<size+index; i++)
		{
			//if the next position is empty, then put the value in it
			if(hashTbl[i%size].getData()=="")
			{
				hashTbl[i%size].setData(str);
				hashTbl[i%size].setCount(1);

			}
		}
	}

}

void hashTable::sortInOrder()
{

}
int hashTable::countInTable(node* head);
int hashTable::search(string str);
void hashTable::readInTable(string a[],int length);
void hashTable::deleteInTable(string str);
