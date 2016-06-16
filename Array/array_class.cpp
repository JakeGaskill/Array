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

#include "iostream"
#include "array.h"

using namespace std;

int main()
{
	ARRAY Array1; //initialize ARRAYS
	ARRAY Array2;
	ARRAY Array3(7);

	Array1.ReadFile(); //reads file and stores strings in Array1
	Array3 = Array2; //
	Array2 + "i" + "love" + "programming"; //+operator implementation w/ chaining
	Array3 + "z" + "y" + "x"; //output .exe explains the steps as they are called

	cout << endl << "This is Array3 before being sorted:" << endl << Array3 << endl;
	Array3.Sort();
	cout << endl << "This is Array3 after being sorted:" << endl << Array3 << endl;

	cout << endl << "Time to use the operator<< with chaining (displaying arrays 3-1):" << endl 
		<< Array3 << Array2 << Array1 << endl;

	cout << endl << "Searching for ""love"" in Array2 and displaying it's location Array2 (i)..."
		<< endl << Array2.Search("love") << endl;
	
	cout << endl << "About to use the remove function to remove ""love""..." << endl;
	Array2.Remove("love");

	cout << endl << "And print the modified Array 2:" << endl << Array2 << endl;
	return 0;
}