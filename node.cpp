#include <iostream>
#include "node.h"
using namespace std;

	node::node()
	{
		value=0;
		left=NULL;
		right=NULL;
		
	}

	node::node(int val)
	{
		value=val;
		left=NULL;
		right=NULL;
		
	}

	node::node(int val, node* ptrL, node* ptrR)
	{
		value=val;
		left=ptrL;
		right=ptrR;
	}
	
		void node::setLeft(node *ptr){left=ptr;}
		void node::setRight(node *ptr){ right=ptr;}
		void node::setValue(int val){ value=val;}
		int node::getValue(){ return value;}
		node* node::getLeft(){ return left;}
		node* node::getRight(){ return right;}
