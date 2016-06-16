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
#include "array.h"

using namespace std;

/**********************************************************************************************
Name:	Array
Precondition: The state of the object (private data) has not been initialized
Postcondition: The state has been initialized to the default values described below
Description:  This is the default constructor which will be called automatically when 
an object is declared.  It will initialize the state of the class.
***********************************************************************************************/
ARRAY::ARRAY()
{
	count = 0; //declare variables
	capacity = 2;
	DB = new string[capacity]; //allocate space for dynamic DB with specified capacity

	cout << "Default constructor invoked" << endl; //invoke message
}

/**********************************************************************************************
Name:	Array
Precondition: The state of the object (private data) has not been initialized
Postcondition: The capacity has been initialized to the value of the actual argument
Description:  This is the explicit-value constructor which sets the capacity of the array to
the value specified by the actual argument.
***********************************************************************************************/
ARRAY::ARRAY(int x)
{
	count = 0; //declare variables
	capacity = x;
	DB = new string[capacity]; //allocate space for dynamic DB with specified capacity

	cout << "Explicit-value constructor invoked" << endl; //invoke message
}

/**********************************************************************************************
Name:	Array
Precondition: The state of the object (private data) has not been initialized
Postcondition: The capacity has been initialized to the values of another ARRAY
Description:  This is the copy constructor which sets the implicit ARRAY equal to the explicit
ARRAY.
***********************************************************************************************/
ARRAY::ARRAY(const ARRAY & org)
{
	DB = 0; //declare variables
	(*this) = org; //use operator= to set *this = to org

	cout << "Copy constructor invoked" << endl; //invoke message

}

/**********************************************************************************************
Name:	Array
Precondition: The state of the object (private data) has been initialized
Postcondition: Checks to see if count is = 0, returns true or false
Description:  IsEmpty checks to see if the ARRAY in question has a count = 0. If so,
it implies that the ARRAY is empty, then it would return true. If not, false.
***********************************************************************************************/
bool ARRAY::IsEmpty() 
{ 
	cout << "IsEmpty function invoked" << endl; //invoke message

	if (count == 0) //if count 0, true, else, false
	{
		return true; 
	}

	else
	{
		return false;
	}
	
}

/**********************************************************************************************
Name:	IsFull
Precondition: The state of the object (private data) has been initialized
Postcondition: Checks if the ARRAY is full, if so returns true
Description:  IsFull checks to see if the count is equivalent to the capacity, if so,
the function returns true. If not, it returns false.
***********************************************************************************************/
bool ARRAY::IsFull() 
{ 
	cout << "IsFull function invoked" << endl;

	if (count == capacity) //if count = capacity, true, else, false
	{
		return true;
	}

	else
	{
		return false;
	}
}

/**********************************************************************************************
Name:	Search
Precondition: The state of the object (private data) has been initialized
Postcondition: The capacity has been initialized to the values of another ARRAY
Description:  Search takes a key in its parameters, than goes throught each DB[i] to see
if there is a match. If there is, it returns the location i. If else, -1.
***********************************************************************************************/
int ARRAY::Search(const string & key)
{
	cout << "Search function invoked" << endl; //invoke message

	for (int i = 0; i < count; i++)
	{
		if (key == DB[i]) //if key = string at DB[i]
		{
			return i; //return position
		}
	}

	return -1; //else return -1
}

/**********************************************************************************************
Name:	Sort
Precondition: The state of the object (private data) has been initialized
Postcondition: The strings within the ARRAY are organized alphabetically
Description:  Sort is a complex function that uses bubble sorting to allow comparisons
between each string of the ARRAY. If it is the least (e.g. the letter a) it will be sorted to 
DB[0], the second least DB[1], etc.
***********************************************************************************************/
void ARRAY::Sort()
{
	cout << "Sort function invoked" << endl; //invoke message

	int place = 0;  //declare variables
	string temp;

	for (int i = 0; i < count; i++) //bubble sort
	{
		for (int j = 0; j < count; j++)
		{
			if (DB[i] <= DB[j]) 
			{ 
				temp = DB[i]; //the ol' switcheroo
				DB[i] = DB[j];
				DB[j] = temp;
			}
		}
	}
}

/**********************************************************************************************
Name:	Operator+
Precondition: The state of the object (private data) has been initialized as well as a string, s
Postcondition: The string s is added to the ARRAY
Description:  Operator+ first checks to see if the array is full, if so, it doubles its size.
Then, it adds the string, s, to the last space available, count, then increments count.
***********************************************************************************************/
ARRAY & ARRAY::operator+(const string s)
{
	cout << "Operator+ invoked" << endl; //invoke message

	if (IsFull()) //if full double size
	{ 
		Size_Times_Two(); 
	}

	DB[count] = s; //next available slot = s
	count++; //increment next available slot

	return *this;
}

/**********************************************************************************************
Name:	Remove
Precondition: The state of the object (private data) has been initialized and a key has been
passed
Postcondition: Removes a string equal to the key passed
Description:  Remove searches for the key and shifts each next value into the previous, thus
removing the string described by key.
***********************************************************************************************/
void ARRAY::Remove(const string key)
{
	if (IsEmpty() == true) //if empty leave function
	{
		return;
	}

	else if (Search(key) != -1) //if search finds location
	{
		for (int i = Search(key); i < count; i++)
		{
			DB[i] = DB[i + 1]; //shift right from position i
		}
	}
}

/**********************************************************************************************
Name:	Operator=
Precondition: The state of the two objects (private data) have been initialized
Postcondition: Sets the implicit ARRAY equal to the explicit ARRAY
Description:  This function is used within the copy constructor as well. Operator= sets the implicit
ARRAY equal to the explicit ARRAY. This is done by deleting the implicit DB and setting all other
values of the implicit ARRAY equal to the explicit.
***********************************************************************************************/
ARRAY &ARRAY::operator=(const ARRAY & org)
{
	delete [] DB; //delete implicit array
	count = org.count; //copy all values
	capacity = org.capacity;
	DB = new string[capacity]; //reallocate DB

	for (int i = 0; i < count; i++)
	{
		DB[i] = org.DB[i]; //copy all strings in explicit array to implicit array
	}

	return *this;
}

/**********************************************************************************************
Name:	Operator<<
Precondition: The state of the object (private data) has been initialized
Postcondition: The operator<< is overloaded to display the whole ARRAY
Description:  By overloading the operator<<, the whole ARRAY can be displayed, with chaining.
***********************************************************************************************/
ostream & operator<<(ostream &out, ARRAY & org)
{
	for (int i = 0; i < org.count; i++)
	{
		out << org.DB[i] << endl;
	}
	return out;
}

/**********************************************************************************************
Name:	Size_Times_Two
Precondition: The state of the object (private data) has been initialized
Postcondition: The capacity of the ARRAY is doubled
Description:  The Size_Times_Two function doubles the size of the capacity while maintaining
its values. This is done by creating a temporary ARRAY, storing the original values in it,
deleting the original array, and setting calling operator= to set the original array equal to
the temporary array.
***********************************************************************************************/
void ARRAY::Size_Times_Two()
{
	cout << "Size_Times_Two function invoked" << endl; //invoke message
	
	capacity = capacity * 2; //double value of capacity
	string *temp = new string[capacity]; //allocate space for temp array

	for (int i = 0; i < count; i++)
	{
		temp[i] = DB[i]; //set temp equal
	}

	delete[] DB; //delete DB
	DB = temp; //set DB equal
}

/**********************************************************************************************
Name:	ReadFile
Precondition: The state of the object (private data) has been initialized
Postcondition: The array now contains the strings within the text file specified
Description:  ReadFile stores text as strings within the ARRAY. This is done by reading it,
storing the lines as strings, and using operator+ to add the string to the ARRAY.
***********************************************************************************************/
void ARRAY::ReadFile()
{
	string s; //initialize string s

	ifstream file("array_strings.txt"); //get file

	if (file.is_open()) //if its open
	{
		while (getline(file, s)) //get line from file store in s
		{
			(*this) + s; //add to ARRAY through *this
		}
		
		file.close(); //close file
	}

	else
	{
		cout << "Error opening file."; //if file doesn't open, message displays
	}
}