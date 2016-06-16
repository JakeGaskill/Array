/********************************************************************************************

Name: Jacob Gaskill                    Z#: 23236263
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date:  2/12/2016           Due Time: 11:00 PM
Total Points: 100
Assignment 3: Array program

Description: In this assignment, we:
(1) manage dynamic memory (allocate and de-allocate memory);
(2) implement a default, explicit-value, and copy constructor;
(3) implement a destructor;
(4) overload the assignment (=) and addition (+) as member functions, and the insertion (<<)  operators as friend functions.
(5) Sort a list of elements.
*********************************************************************************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class ARRAY
{
public:
	ARRAY();
	ARRAY(int );
	ARRAY(const ARRAY &);
	bool IsEmpty();
	bool IsFull();
	int Search(const string &);
	void Sort();
	ARRAY & operator+(const string );
	void Remove(const string);
	ARRAY & operator=(const ARRAY &);
	friend ostream & operator<<(ostream &, ARRAY &);
	void Size_Times_Two();
	void ReadFile( );
private:
	string *DB;
	int count;
	int capacity;
	//additonal state variables you may wish add
};