#ifndef NODEHT_H
#define NODEHT_H
using namespace std;

class nodeHT
{
	private:
		string data;
        int counter;
	
	public:
		//constructor
		nodeHT();
		nodeHT(string str);

		void setData(string str);
		string getData();
        int getCounter ();
        void incrementCounter ();
};
#endif
