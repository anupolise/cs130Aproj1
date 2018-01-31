#ifndef NODE_H
#define NODE_H

class node
{
	private:
		int value;
		node* left;
		node* right;
	public:
		//constructor
		node();
		node(int val);
		node(int val, node* ptrL, node* ptrR);


		void setLeft(node *ptr);
		void setRight(node *ptr);
		void setValue(int val);
		int getValue();
		node* getLeft();
		node* getRight();


};
#endif