//Hash.h
#ifndef HASH_H_
#define HASH_H_
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Hash
{
    private:
        list<int> *hashtable;  // container
        vector<int> values;    //(Used for getting a random key)
        int buckets;           // # buckets
        int sizeofHash;  	   //Size of the Hash Table

    public:
        //Constructor
        Hash (int a);

        //Setters & Getters
        void setBuckets(int s)	{buckets = s;}
        int returnSize()		{return sizeofHash;}
        int returnBuckets() 	{return buckets;}

        //Methods
        int setRandomKey();
        void insert_element (int key);
        int hashFunction (int a) {return (a % buckets);} // maps values to key
        int search_element (int key);
        void displayHash();

        ~Hash()//destructor
         {  delete [] hashtable;  }
};
#endif
