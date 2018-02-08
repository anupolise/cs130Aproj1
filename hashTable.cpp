#include <iostream>
#include "hashTable.h"

using namespace std;

int main()
{
    string arr[13] = {"aa","gs","gb","bb","be","hs","ja","ss","sd","as","hs","aa","aa"};
    hashTable ht;
    ht.readInTable(arr, 11);
    
    
    //ht.printInOrder(ht.getHead());
    
    
    //cout<<"header: "<<(ht.getHead()).getData()<<endl;
    //int countin = ht.countInTree(ht.getHead());
    //cout<<"count:"<<countin<<endl;
    
    /*
    //string* v = ht.rangeSearch ("bd", "zz");
    vector <string> v = ht.rangeSearch ("bd", "zz");
    
    cout << "Range Search ";
    for (int i = 0; i < v.size(); i++) {
        cout << (v)[i] << " ";
    }
     */
    
    cout << endl;
    cout << endl;
    int the = ht.search("hs");
    cout<<"search hs - "<<the<<endl<<std::flush;
    
    int ben = ht.search("jj");
    cout<<"search jj - "<<ben<<endl<<std::flush;
    
}

hashTable::hashTable() {
    size = 101;
	hashTbl =  new nodeHT[size];
	for(int i=0; i<size; i++) {
		hashTbl[i] =  nodeHT();
	}
}

hashTable::hashTable(int s) {
	hashTbl = new nodeHT[s];
	for(int i=0; i<s; i++) {
		hashTbl[i] = nodeHT();
	}
	size = s;
}

void hashTable::insert(string str) {
    int index = indexOf(str);
    if (index != -1) {
        hashTbl[index].incrementCounter ();
    }
    else {
        int startingIndex = hash (str)%size;
        int i = startingIndex;
        if(hashTbl[i].getCounter()<=0) {
            nodeHT tmp = hashTbl [index];
            //cout << "11"<<endl;
            tmp.incrementCounter();
            //cout << "22"<<endl;
            tmp.setData (str);
        }
        i = (i+1)%size;
        while (i != startingIndex && hashTbl[i].getCounter() > 0) {
            i = (i+1)%size;
        }
        
        if(i != startingIndex) {
            nodeHT tmp = hashTbl [index];
            tmp.incrementCounter();
            tmp.setData (str);
        }
    }
}

//void hashTable::sortInOrder();
//int hashTable::countInTable(nodeHT* head);


int hashTable::search(string str) {
    int index = indexOf (str);
    if (index == -1) {
        return 0;
    }
    else {
        return hashTbl[index].getCounter();
    }
}

int hashTable::indexOf (string str) {
    int startingIndex = hash (str)%size;
    int i = startingIndex;
    //cout << "3";
    if(hashTbl[i].getData()==str) {
        return i;
    }
    i = (i+1)%size;
    //cout << "4";
    while (i != startingIndex && hashTbl[i].getData()!="") {
        //cout << "5";
        if(hashTbl[i].getData()==str) {
            return i;
        }
        i = (i+1)%size;
    }
    return -1;
}

void hashTable::readInTable(string a[],int length) {
    for(int i=0; i<length; i++)
    {
        //cout << i << endl;
        insert(a[i]);
        //cout << i << endl;
    }
}

int hashTable::hash (string str){
    int a = 409;
    int b = 551;
    int c = 257;
    int d = 613;
    //cout << str.length() << endl;
    if (str.length() >= 1) {
        //cout << str [0] << endl;
        a = a * int(str [0]);
    }
    if (str.length() >= 2) {
        //cout << str [1] << endl;
        b = b * int(str [1]);
    }
    if (str.length() >= 3) {
        //cout << str [2] << endl;
        c = c * int(str [2]);
    }
    if (str.length() >= 4) {
        //cout << str [3] << endl;
        d = d * int(str [3]);
    }
    return a + b + c + d;
}


//void hashTable::deleteInTable(string str);
