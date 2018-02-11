// Lawrence Lim
// Anu Polisetty

// wordsearch.h
//


#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "hashTable.h"
#include "BST.h"
#include <algorithm>

//#include "document.h"

int getdir (string dir, vector<string> &files);
bool makeAlphaNum(string str);



int main(int argc, char* argv[]);
