#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
	string arr[10] = {"aa","gs","gb","bb","be","hs","ja","ss","sd","as"};
	BST binary;
	binary.readInTree(arr, 10);


	binary.printInOrder(binary.getHead());


	cout<<"header: "<<(binary.getHead())->getData()<<endl;
	int countin= binary.countInTree(binary.getHead());
	cout<<"count:"<<countin<<endl;
	
    int the = binary.search("hs");
	cout<<"facts hs - "<<the<<std::flush;
}


BST::BST()
{
	head = NULL;
}

void BST::insert (string str) { insert(str, head); }

void BST::insert (string str, node* pointer)
{
	if(pointer == NULL)
	{
		//cout<<"head inserted:"<<str<<endl;
		node* tmp = new node(str);
		head=tmp;
		//cout<<"head init"<<endl;
	}
	else
	{
		if(str > pointer->getData())
		{
			if(pointer->getRight() == NULL)
			{
				node* tmp = new node(str);
				pointer->setRight(tmp);
                //cout<<"str inserted:"<<str<<endl;
			}
			else
			{
				insert(str, pointer->getRight());
			}
			
		}
		else if(str < pointer->getData())
		{
			if(pointer->getLeft() == NULL)
			{
				node* tmp = new node(str);
				pointer->setLeft(tmp);
				//cout<<"str inserted:"<<str<<endl;
			}
			else
			{
				insert(str, pointer->getLeft());
			}
		}
        else {
            pointer->incrementCounter ();
        }
	}
}


int BST::countInTree(node* headz)
{
	if(headz==NULL)
	{
		return 0;
	}
	else
	{
		return 1+countInTree(headz->getLeft())+countInTree(headz->getRight());
	}

}

void BST::printInOrder(node* headz)
{
	if(headz!=NULL)
	{
		printInOrder(headz->getLeft());
		cout<<headz->getData()<< endl;
		printInOrder(headz->getRight());
	}
}

int BST::search(string str) { return search (str, head); }

int BST::search(string str, node* pointer)
{
	if(pointer==NULL)
	{
		return 0;
	}
	else if(pointer->getData()==str)
	{
		return pointer->getCounter();
	}
	else if(pointer->getData()>str)
	{
		return search(str, pointer->getLeft());
	}
	else if(pointer->getData()<str)
	{
		return search(str, pointer->getRight());
	}
	return false;
}


void BST::readInTree(string a[], int length)
{
	for(int i=0; i<length; i++)
	{
		insert(a[i]);
	}
}

node* BST::getHead()
{  return head; }
