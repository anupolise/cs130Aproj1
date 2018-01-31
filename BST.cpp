#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
	int arr[10]={6,8,4,3,9,7,10,2,11,1};
	BST binary;
	binary.readInTree(arr, 10);


	binary.printInOrder(binary.getHead());


	cout<<"header: "<<(binary.getHead())->getValue()<<endl;
	int countin= binary.countInTree(binary.getHead());
	cout<<"count:"<<countin<<endl;
	
	bool the = binary.findVal(9, binary.getHead());
	cout<<"facts 9 - "<<the<<std::flush;
}
BST::BST()
{
	head=NULL;
}


void BST::insertR(int num, node* headz)
{
	if(head==NULL)
	{
		cout<<"head inserted:"<<num<<endl;
		node* inte = new node(num);
		head=inte;
		cout<<"head init"<<endl;
	}
	else
	{
		if(num>headz->getValue())
		{
			if(headz->getRight()==NULL)
			{
				node* inte = new node(num);
				headz->setRight(inte);
				cout<<"num inserted:"<<num<<endl;
			}
			else
			{
				insertR(num, headz->getRight());
			}
			
		}
		if(num<headz->getValue())
		{
			if(headz->getLeft()==NULL)
			{
				node* inte = new node(num);
				headz->setLeft(inte);
				cout<<"num inserted:"<<num<<endl;
			}
			else
			{
				insertR(num, headz->getLeft());
			}
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
		cout<<headz->getValue()<< endl;
		printInOrder(headz->getRight());

	}
	
}
bool BST::findVal(int num, node* headz)
{
	if(headz==NULL)
	{
		return false;
	}
	else if(headz->getValue()==num)
	{
		return true;
	}
	else if(headz->getValue()>num)
	{
		return findVal(num, headz->getLeft());
	}
	else if(headz->getValue()<num)
	{
		return findVal(num, headz->getRight());
	}
	return false;
}
void BST::readInTree(int a[], int length)
{
	for(int i=0; i<length; i++)
	{
		insertR(a[i],head);
	
	}
}

node* BST::getHead()
{  return head;}