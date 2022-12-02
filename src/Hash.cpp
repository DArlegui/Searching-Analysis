//Hash.cpp
#include <iostream>
#include <iomanip>
#include "Hash.h"
using namespace std;

Hash::Hash (int a)
{
  buckets = a;
  hashtable = new list<int>[buckets];
  sizeofHash = 0;
}

//setRandomKey(): returns a true value from hash table
//Arguments: N/A | Returns: *viter
int Hash::setRandomKey(){
	vector<int>::iterator viter = values.begin();
	for(int i = 0, vSize = values.size(); i < rand() % vSize; i++)
		viter++;
	return *viter;
}

//insert_element(): pushes an element into the hash table and vector. Increments hSize
//Arguments: int key | Returns: void
void Hash::insert_element (int key)
{
    //to get the hash index of key
    int indexkey = hashFunction(key);
    hashtable[indexkey].push_back(key);
    sizeofHash++;
    values.push_back(key);
}

//search_element(): Recieves a key and returns how much iterations it took to find it
//Arguments: int key | Returns: return counter or -1
int Hash::search_element (int key)
{
    // add code for your count of key comparisons
    int indexkey = hashFunction(key);
    int counter = 0;
    bool found = false;
    list<int>::iterator i = hashtable[indexkey].begin();
    for (; i != hashtable[indexkey].end(); i++)
    {
        counter++;
    	if (*i == key){
    		found = true;
    		break;
    	}

    }
    if(found)
    	return counter;
    else
    	return -1;
 }

//displayHash(): Prints out the hash table. For testing purposes
//Arguments: N/A | Returns: void
void Hash::displayHash(){
	if(!(sizeofHash <= 0)){
		for(int i = 0; i < buckets; i++){
			cout << i;
			for(auto it : hashtable[i])
				cout << " --> " << it;
			cout << endl;
		}
	}
	else
		cout << "Hash table it currently Empty!" << endl;
}
