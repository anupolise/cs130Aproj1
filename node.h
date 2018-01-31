#ifndef NODE_H
#define NODE_H
using namespace std;

class node
{
	private:
		string data;
        int counter;
		node* left;
		node* right;
	public:
		//constructor
		node();
		node(string str);
		node(string str, node* ptrL, node* ptrR);


		void setLeft(node *ptr);
		void setRight(node *ptr);
		void setData(string str);
		string getData();
        int getCounter ();
        void incrementCounter ();
		node* getLeft();
		node* getRight();


};
#endif
