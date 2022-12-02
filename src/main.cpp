//*****************
//Program Name: Program 14
//Author: Daniel Arlegui
//IDE Used: Eclipse
//Program description: Searching Analysis
//*****************

//Libraries
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm> //for sort algorithm for binary function(s)
#include <math.h> 	 //for pow function
#include "Hash.h"
using namespace std;

//Function(s)
void Search(int nS, int F);
void searchHashtable(int s);
int linearSearch(vector<int> vec, int v, int S);
int binarySearch(vector<int> vec, int v, int S);
int recursiveLinearSearch(vector<int> vec, int v, int S, int &c);
int recursiveBinarySearch(vector<int> vec, int f, int l, int v, int &c);

int main()
{
	//Housekeeping
	srand(time(0));
	int SIZE;

	for(int i = 1; i <= 5; i++){ //Looping 5 times for each unique search functions
		for(int p = 1; p <= 13; p++){ //For manipulating n size
			switch(i){
				case 1:	if(p == 1) {cout << "Procedural Sequential Search" << endl;}
						SIZE = pow(2, p); // Size = 2 ^ L (up to 13 times)
						Search(SIZE, i);
					break;
				case 2:	if(p == 1) {cout << "\nProcedural Binary Search" << endl;}
						SIZE = pow(2, p);
						Search(SIZE, i);
					break;
				case 3: if(p == 1) {cout << "\nRecursive Sequential Search" << endl;}
						SIZE = pow(2, p);  //Using this is WAYYY TO SLOW when SIZE becomes > 4000
						Search(SIZE, i);
					break;
				case 4: if(p == 1) {cout << "\nRecursive Binary Search" << endl;}
						SIZE = pow(2, p);
						Search(SIZE, i);
					break;
				case 5: if(p == 1) {cout << "\nHashing" << endl;}
						SIZE = pow(2, p);
						searchHashtable(SIZE); //Uses it's own function
					break;
			}
		}
	}

    cout << "\nThis is my original work; apart from standard tutoring or class collaboration, "
    	"\nI neither received help nor copied this code from another source."  << endl;

    return 0;
}

//Search(): retrieves a size and chooses which search function to go with
//Arguments: int SIZE, int Function | Returns: N/A
void Search(int nSize, int Function){

	//Variables
	vector<int> iterContainer;
	int sum_of_elements = 0, maxLoop = 1000, counter = 0;
	double avg = 0;

	//1000 Simulation
	for(int i = 0; i < maxLoop; i++){

		vector<int> keyComparison;

		for(int j = 0; j < nSize; j++)
			keyComparison.push_back(rand() % 10000 + 1); //1 - 10000

		vector<int>::iterator viter = keyComparison.begin();
		for(int k = 0, kSize = keyComparison.size(); k < rand() % kSize; k++)
			viter++; //Search Term

		switch(Function){
			case 1: iterContainer.push_back(linearSearch(keyComparison, *viter, nSize));
				break;

			case 2:	sort(keyComparison.begin(), keyComparison.end()); //Sorting
					iterContainer.push_back(binarySearch(keyComparison, *viter, nSize));
				break;

			case 3: recursiveLinearSearch(keyComparison, *viter, nSize, counter); //So SLOW
					iterContainer.push_back(counter);
					counter = 0;
				break;

			case 4: sort(keyComparison.begin(), keyComparison.end()); //Sorting
					recursiveBinarySearch(keyComparison, 0, keyComparison.size() - 1, *viter, counter);
					iterContainer.push_back(counter);
					counter = 0;
				break;
			default: cerr << "Error with \"Function\" variable. Terminating program...";
					 exit(EXIT_FAILURE); //Guarding purposes
		}
		keyComparison.empty();
	}

	//Calculating Results
	for(vector<int>::iterator it = iterContainer.begin(); it != iterContainer.end(); ++it)
		sum_of_elements += *it;

	avg = sum_of_elements / (double)maxLoop;

	//Results
	cout << "n = " <<  setw(4) << nSize   << " | "  << "pct = " <<  setw(11) <<  avg / (double)nSize
		<< " | " << "Sum = " << setw(7) << sum_of_elements << " | " << "avg = " << setw(4) << avg << endl;

	iterContainer.empty();
}

//searchHashtable(): Uses Hash Table and prints out results
//Arguments: int nSize | Returns: N/A
void searchHashtable(int nSize){

	//Variables
	int key, sum_of_elements = 0, maxLoop = 1000;
	double avg = 0;
	vector<int> iterContainer;

	//1000 Simulation
	for(int i = 0; i < maxLoop; i++){
		Hash h(20);
		for(int j = 0; j < nSize; j++)
			h.insert_element(rand() % 10000 + 1);
		key = h.setRandomKey();
		iterContainer.push_back(h.search_element(key)); //Returns counter to keyContainer
	}

	//Calculating Results
	for(vector<int>::iterator it = iterContainer.begin(); it != iterContainer.end(); ++it)
		sum_of_elements += *it;

	avg = sum_of_elements / (double)maxLoop;

	//Results
	cout << "n = " <<  setw(4) << nSize << " | "  << "pct = " <<  setw(11) <<  avg / (double)nSize
		<< " | " << "Sum = " << setw(7) << sum_of_elements << " | " << "avg = " << setw(4) << avg << endl;
}

//linearSearch(): Sequential Search Function
//Arguments: vector<int> vector, int value, int SIZE | Returns: counter or -1
int linearSearch(vector<int> vector, int value, int SIZE){
    int index = 0, counter = 0;
    bool found = false;

    while (index < SIZE and !found){
    	counter++;
        if (vector[index] == value)
        	found = true;
        index++;
    }

    if(found)
    	return counter;
    else
    	return -1;
}

//binarySearch(): Binary Search Function
//Arguments: vector<int> vector, int value, int SIZE | Returns: counter or -1
int binarySearch(vector<int> vector, int value, int SIZE){
	int counter = 0, first = 0, last = SIZE - 1, middle;
    bool found = false;

    while (first <= last and !found)
    {
    	counter++;
        middle = (first + last) / 2;
        if (vector[middle] == value)
            found = true;
        else if (vector[middle] > value)
            last = middle - 1;
        else
            first = middle + 1;
    }

    if(found)
    	return counter;
    else
    	return -1;
}

//recursiveLinearSearch(): Recursive Linear Search Function
//Arguments: vector<int> vector, int value, int SIZE, int &counter | Returns: counter or -1
int recursiveLinearSearch(vector<int> vector, int value, int SIZE, int &counter){

  counter++;
  SIZE = SIZE - 1;

  if(SIZE < 0)
	  return -1;

  else if(vector[SIZE] == value)
	  return counter; //Returns counter instead of 1 (true)

  else
	  return recursiveLinearSearch(vector, value, SIZE,counter);
}

//recursiveBinarySearch(): Recursive Binary Search Function
//Arguments: vector<int> vector, int first, int last, int value, int &counter | Returns: counter or -1
int recursiveBinarySearch(vector<int> vector, int first, int last, int value, int &counter){

	counter++;
    int mid = (last + first) / 2;

    if(first <= last)
    {
        if (vector[mid] == value)
        	return counter;
        else if (vector[mid] > value)
            return recursiveBinarySearch(vector, first, mid - 1, value, counter);
        else
            return recursiveBinarySearch(vector, mid + 1, last, value, counter);
    }
    else
    	return -1;
}
