
// wordsearch.cpp
// 1/27/17
// Agrawal
//


#include "wordsearch.h"

using namespace std;

// Given a directory, return all the files in that directory
// if the directory does not exist -- report error.
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }
    
    while ((dirp = readdir(dp)) != NULL) {
        if (string(dirp->d_name) != "." && string(dirp->d_name) != "..") {
            getdir (dir+"/"+string(dirp->d_name), files);
            files.push_back(string(dir+"/"+dirp->d_name));
        }
    }
    closedir(dp);
    return 0;
}
bool checkAlphaNum(string str)
{
    for(int i=0; i< str.length(); i++)
    {
        if(!isalnum(str[i]))
        {
            return false;
        }
    }
    return true;
}
int main(int argc, char* argv[])
{
    string dir; //
    vector<string> files = vector<string>();
    hashTable wordIndex (77747);
    BST wordIndex2;
    
    if (argc < 2)
    {
        cout << "No Directory specified; Exiting ..." << endl;
        return(-1);
    }
    dir = string(argv[1]);
    if (getdir(dir,files)!=0)
    {
        cout << "Error opening " << dir << "; Exiting ..." << endl;
        return(-2);
    }
    
    // THIS PART OF THE CODE SETS UP THE INVERTED INDEX
    
    string slash("/");
    int count = 0;
    for (unsigned int i = 0; i < files.size(); i++) {
        if(files[i][0]=='.') continue; //skip hidden files
        cout << "OPEN " << files[i] << endl;
        ifstream fin((files[i]).c_str()); //open using absolute path
        // ...read the file..
        string word;
        while(!fin.eof()){
            count ++;
            fin>>word;
            cout<<"       " << files[i]<<"::"<<word<<endl;
            if(checkAlphaNum(word))
            {
                wordIndex.insert(word);
                wordIndex2.insert(word);
            }
           
            // Now the string "word" holds the keyword, and the string "files[i]" holds the document name.
            // Use these two strings to search/insert in your linked lists
        }
        cout << "EOF " << files[i] << endl;
        cout << count<<endl;
        fin.close();
    }
    
    cout << wordIndex2.countInTree(wordIndex2.getHead());
    
    //string word_to_be_found;
    int userInput = 0;
    while (true){
        cin>>userInput;
        if(userInput == 1)
        {
             search(wordIndex, wordIndex2);
        }
        else if(userInput == 2)
        {
            insert(wordIndex, wordIndex2);
        }
        else if(userInput == 3)
        {
            deletion(wordIndex, wordIndex2);
        }
        else if(userInput == 4)
        {
            sorted(wordIndex, wordIndex2);
        }
        else if(userInput ==5)
        {
            rangedSearch(wordIndex, wordIndex2);
        }


    }
    
    
    return 0;
}

void search (hashTable &wordIndex, BST &wordIndex2) {
    //cout << endl;
    string word_to_be_found;
    cout << "> ";
    cin >> word_to_be_found;
    struct timeb timer_msec;
    long long int timestamp_msec_before, timestamp_msec_after;
    if (!ftime(&timer_msec)) {
        timestamp_msec_before = ((long long int) timer_msec.time) *100011 + (long long int)timer_msec.millitm;
    }

    int n = wordIndex2.search (word_to_be_found); // BST
    if (!ftime(&timer_msec)) {
        timestamp_msec_after = ((long long int) timer_msec.time) *100011 + (long long int)timer_msec.millitm;
    }
    if (n > 0) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    cout << "BST: " << timestamp_msec_after - timestamp_msec_before << " milliseconds." << endl;
        if (!ftime(&timer_msec)) {
        timestamp_msec_before = ((long long int) timer_msec.time) *100011 + (long long int)timer_msec.millitm;
    }

    n = wordIndex.search (word_to_be_found); // HT
    if (!ftime(&timer_msec)) {
        timestamp_msec_after = ((long long int) timer_msec.time) *100011 + (long long int)timer_msec.millitm;
    }
    cout << "Hash: " << timestamp_msec_after - timestamp_msec_before<< " milliseconds." << endl;
}

void insert (hashTable &wordIndex, BST &wordIndex2) {
    string word_to_insert;
    cout << "> ";
    cin >> word_to_insert;
    
    struct timeb timer_msec;
    long long int timestamp_msec_before, timestamp_msec_after;
    if (!ftime(&timer_msec)) {
        timestamp_msec_before = ((long long int) timer_msec.time) *100011 + (long long int)timer_msec.millitm;
    }
    
    wordIndex2.insert (word_to_insert); // BST
    if (!ftime(&timer_msec)) {
        timestamp_msec_after = ((long long int) timer_msec.time) *100011 + (long long int)timer_msec.millitm;
    }
    cout << "BST: " << timestamp_msec_after - timestamp_msec_before << " milliseconds." << endl;
    if (!ftime(&timer_msec)) {
        timestamp_msec_before = ((long long int) timer_msec.time) *100011 + (long long int)timer_msec.millitm;
    }
    
    wordIndex.insert (word_to_insert); // HT
    if (!ftime(&timer_msec)) {
        timestamp_msec_after = ((long long int) timer_msec.time) *100011 + (long long int)timer_msec.millitm;
    }
    cout << "Hash: " << timestamp_msec_after - timestamp_msec_before<< " milliseconds." << endl;
}


void deletion (hashTable &wordIndex, BST &wordIndex2) {
    string word_to_delete;
    cout << "> ";
    cin >> word_to_delete;
    
    struct timeb timer_msec;
    long long int timestamp_msec_before, timestamp_msec_after;
    if (!ftime(&timer_msec)) {
        timestamp_msec_before = ((long long int) timer_msec.time) *100011 + (long long int)timer_msec.millitm;
    }
    
    wordIndex2.deleteNode(word_to_delete); // BST
    if (!ftime(&timer_msec)) {
        timestamp_msec_after = ((long long int) timer_msec.time) *100011 + (long long int)timer_msec.millitm;
    }
    cout << "BST: " << timestamp_msec_after - timestamp_msec_before << " milliseconds." << endl;
    if (!ftime(&timer_msec)) {
        timestamp_msec_before = ((long long int) timer_msec.time) *100011 + (long long int)timer_msec.millitm;
    }
    
    wordIndex.deleteValue (word_to_delete); // HT
    if (!ftime(&timer_msec)) {
        timestamp_msec_after = ((long long int) timer_msec.time) *100011 + (long long int)timer_msec.millitm;
    }
    cout << "Hash: " << timestamp_msec_after - timestamp_msec_before<< " milliseconds." << endl;
}


void sorted (hashTable &wordIndex, BST &wordIndex2) {

    
    struct timeb timer_msec;
    long long int timestamp_msec_before, timestamp_msec_after;
    if (!ftime(&timer_msec)) {
        timestamp_msec_before = ((long long int) timer_msec.time) *100011 + (long long int)timer_msec.millitm;
    }
    vector <string> s1;
    wordIndex2.sorted(wordIndex2.getHead(), s1); // BST
    if (!ftime(&timer_msec)) {
        timestamp_msec_after = ((long long int) timer_msec.time) *100011 + (long long int)timer_msec.millitm;
    }
    cout << "BST: " << timestamp_msec_after - timestamp_msec_before << " milliseconds." << endl;
    if (!ftime(&timer_msec)) {
        timestamp_msec_before = ((long long int) timer_msec.time) *100011 + (long long int)timer_msec.millitm;
    }
    
    vector <string> s2 = wordIndex.sort(); // HT
    if (!ftime(&timer_msec)) {
        timestamp_msec_after = ((long long int) timer_msec.time) *100011 + (long long int)timer_msec.millitm;
    }
    cout << "Hash: " << timestamp_msec_after - timestamp_msec_before<< " milliseconds." << endl;
}


void rangedSearch (hashTable &wordIndex, BST &wordIndex2) {
    string lower, higher;
    cout << "> ";
    cin >> lower;
    cout << "> ";
    cin >> higher;
    struct timeb timer_msec;
    long long int timestamp_msec_before, timestamp_msec_after;
    if (!ftime(&timer_msec)) {
        timestamp_msec_before = ((long long int) timer_msec.time) *100011 + (long long int)timer_msec.millitm;
    }
    
    vector <string> s1 = wordIndex2.rangeSearch(lower, higher); // BST
    if (!ftime(&timer_msec)) {
        timestamp_msec_after = ((long long int) timer_msec.time) *100011 + (long long int)timer_msec.millitm;
    }
    
    for (int i = 0; i < s1.size(); i++) {
        cout <<s1[i]<<endl;
    }
    cout << "BST: " << timestamp_msec_after - timestamp_msec_before << " milliseconds." << endl;
    if (!ftime(&timer_msec)) {
        timestamp_msec_before = ((long long int) timer_msec.time) *100011 + (long long int)timer_msec.millitm;
    }
    
    vector <string> s2 = wordIndex.rangeSearch (lower, higher); // HT
    if (!ftime(&timer_msec)) {
        timestamp_msec_after = ((long long int) timer_msec.time) *100011 + (long long int)timer_msec.millitm;
    }
    cout << "Hash: " << timestamp_msec_after - timestamp_msec_before<< " milliseconds." << endl;
}

