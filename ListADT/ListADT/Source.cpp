/*
	ENGR2400 Data Structures and Algorithms
	Fall 2019
	Ryley Danielson
	Programming Assignment 1 - List ADT
	The goal of this assignment is to create a List abstract data type class using an array as the base for the list implementation.
	The number of steps a method takes to complete is based on actions specifically involving the List where variable memory is accessed, a calculation is done, a comparison is done, or a value is returned 
*/

//Includes libraries needed for the program
#include<iostream>
#include<iomanip>
#include <fstream>

//This program uses the standard namespace
using namespace std;

//Global Variables used by the program
int allSteps = 0; //Counter for total number of steps the program performs on the list
int sizeList = 0; //Tracks the size of the list
int i = 0; //Integer fields used in class methods
int o = 0; //Integer fields used in class methods
int numEl = 1000; //Integer fields used in class methods
int list[1000]; //Array used to construct the ListADT
int choice; //Varable storing user menue input

ofstream myfile; //File stream for program 


/*
	Checks to see if the List is empty 
	Returns 1 if empty
	Returns 0 if not empty
*/
int isEmpty()
{

	int localSteps = 3;
	allSteps = allSteps + localSteps;
	
	if (sizeList > 0)
	{
		//Confirmation message
		cout << "The list is not empty. Return 0\n";
		cout << "Number of steps taken to complete action " << localSteps << endl;
		myfile << "The list is not empty. Return 0\n";
		myfile << "Number of steps taken to complete action " << localSteps << endl;
		return 0;
	}
	else
	{
		//Confirmation message
		cout << "The list is empty. Return 1\n";
		cout << "Number of steps taken to complete action " << localSteps << endl;
		myfile << "The list is empty. Return 1\n";
		myfile << "Number of steps taken to complete action " << localSteps << endl;
		return 1;
	}
}

/*
	Checks the size of the list using the counter variable sizeList
	Returns the integer size value stored in sizeList
*/
int size()
{
	int localSteps = 2;
	allSteps = allSteps + localSteps;

	//Confirmation message 
	cout << "The size of the list is " << sizeList << endl;
	cout << "Number of steps taken to complete action " << localSteps << endl;
	myfile << "The size of the list is " << sizeList << endl;
	myfile << "Number of steps taken to complete action " << localSteps << endl;

	return sizeList;
}


/*
	Returns the integer value at the user inputted index (i)
*/
int get(int i)
{
	int localSteps;

	//Checks the index to make sure it is a location currently supported by the array
	if ((i >= 0) && (i <= (numEl - 1)) && (i <= (sizeList - 1)))
	{
		localSteps = 14;
		allSteps = allSteps + localSteps;

		//Confirmation message 
		cout << "The element at index " << i << " is " << list[i] << endl;
		cout << "Number of steps taken to complete action " << localSteps << endl;
		myfile << "The element at index " << i << " is " << list[i] << endl;
		myfile << "Number of steps taken to complete action " << localSteps << endl;
		return list[i];
	}
	
	localSteps = 13;
	allSteps = allSteps + localSteps;

	//Error message
	cout << "Cannot complete action. Input not valid, or index is not being used. Return value -1\n";
	cout << "Number of steps taken to complete action " << localSteps << endl;
	myfile << "Cannot complete action. Input not valid, or index is not being used. Return value -1\n";
	myfile << "Number of steps taken to complete action " << localSteps << endl;
	return -1;
}

/*
	Sets and integer value of a particular index. Index and value are determined by the user input
	Returns the replaced value when successful
*/
int set(int i, int o)
{
	//Checks the index to make sure it is a location currently supported by the array
	if ((i >= 0) && (i <= (numEl - 1)) && (i <= (sizeList-1)) )
	{
		
		int localSteps = 19;
		allSteps = allSteps + localSteps;

		int tempArrayVal = list[i];
		list[i] = o;

		//Confirmation message
		cout << "The element is now " << o << " at index " << i << " the value replaced was " << tempArrayVal << endl;
		cout << "Number of steps taken to complete action " << localSteps << endl;
		myfile << "The element is now " << o << " at index " << i << " the value replaced was " << tempArrayVal << endl;
		myfile << "Number of steps taken to complete action " << localSteps << endl;

		return tempArrayVal;
	}
	else
	{
		int localSteps = 13;
		allSteps = allSteps + localSteps;

		//Error message
		cout << "Cannot complete action. Input not valid or elements must first be added.\n" << "Only indexes lest than " << sizeList << " can be set. Return value -1.\n";
		cout << "Number of steps taken to complete action " << localSteps << endl;
		myfile << "Cannot complete action. Input not valid or elements must first be added.\n" << "Only indexes lest than " << sizeList << " can be set. Return value -1.\n";
		myfile << "Number of steps taken to complete action " << localSteps << endl;
		return -1;
	}

}

/*
	Adds a value to the list at an index. Both the index and input values are determined by the user
	Value is added to the end of the list or moves every item down one to the right from the idexed location then adds new item at the indexed location.
	Increases the size of the list (sizeList)
	Returns the new list size when successful
*/
int add(int i, int o)
{
	int localSteps = 11;

	//Checks the index to make sure it is a location currently supported by the array
	if ((i < 0) || (i > (numEl - 1)) || (i > sizeList)) {
		
		allSteps = allSteps + localSteps;

		cout << "Cannot complete action. Input not valid, or index entered is greater than next availible index, " << sizeList << ".\n More elemebts must be added. Return value -1\n";
		cout << "Number of steps taken to complete action " << localSteps << endl;
		myfile << "Cannot complete action. Input not valid, next availible index for addition is " << sizeList << ".\n More elemebts must be added to use this index. Return value -1\n";
		myfile << "Number of steps taken to complete action " << localSteps << endl;
		return -1;
	}

	int tempInt = sizeList;
	//Moves every item down one to the right from the idexed location 
	for (int n = ++tempInt; n > i; n--)
	{
		list[n] = list[n - 1];
		localSteps = localSteps + 8;
	}
	
	//Adds new item at the indexed location then increases the size of the list
	list[i] = o;
	sizeList++;

	localSteps = localSteps + 6;
	allSteps = allSteps + localSteps;

	cout << "The new size of the list is " << sizeList << endl;
	cout << "Number of steps taken to complete action " << localSteps << endl;
	myfile << "The new size of the list is " << sizeList << endl;
	myfile << "Number of steps taken to complete action " << localSteps << endl;
	return sizeList;
}

/*
	Removes a value in the list at an index. Both the index and input values are determined by the user
	Value is removed at the end of the list or removes item from the indexed location and moves every item down one to the left from the idexed location.
	Increases the size of the list (sizeList)
	Returns the removed value when successful
*/
int remove(int i)
{
	int localSteps = 11;
	
	//Checks the index to make sure it is a location currently supported by the array
	if ((sizeList == 0) || (i < 0) || (i > (numEl - 1)) || (i > sizeList))
	{
		localSteps = localSteps + 1;
		allSteps = allSteps + localSteps;

		cout << "Can not complete action. Input not valid. Return value -1\n";
		cout << "Number of steps taken to complete action " << localSteps << endl;
		myfile << "Can not complete action. Input not valid. Return value -1\n";
		myfile << "Number of steps taken to complete action " << localSteps << endl;
		return -1;
	}
	
	//Removes item from the indexed location
	int temp = list[i];
	list[i] = list[i+1];
	localSteps = localSteps + 4;

	int tempInt = sizeList;
	//Moves every item down one to the left from the idexed location
	for (int n = i; n < sizeList; n++)
	{
			list[n - 1] = list[n];
			localSteps = localSteps + 8;
	}

	localSteps = localSteps + 3;
	allSteps = allSteps + localSteps;

	//Decreases list lize
	sizeList--;
	cout << "The element you removed is " << temp << " at index " << i << " The size of the list is now " << sizeList << endl;
	cout << "Number of steps taken to complete action " << localSteps << endl;
	myfile << "The element you removed is " << temp << " at index " << i << " The size of the list is now " << sizeList << endl;
	myfile << "Number of steps taken to complete action " << localSteps << endl;
	return  temp;
}


/*
	Runs the user interface which interacts with all ListADT methods.
	Outputs a text file of all program inputs and outputs when properly exitted
*/
int main()
{
	
	cout << "ENGR2400 Data Structures and Algorithms\nFall 2019\nRyley Danielson\nProgramming Assignment 1 - List ADT\nThe goal of this assignment is to create a List abstract data type class using an array as the base for the list implementation.\nThe number of steps a method takes to complete is based on actions specifically involving the List where variable memory is accessed, a calculation is done, a comparison is done, or a value is returned  \n\n";
	myfile << "ENGR2400 Data Structures and Algorithms\nFall 2019\nRyley Danielson\nProgramming Assignment 1 - List ADT\nThe goal of this assignment is to create a List abstract data type class using an array as the base for the list implementation.\nThe number of steps a method takes to complete is based on actions specifically involving the List where variable memory is accessed, a calculation is done, a comparison is done, or a value is returned \n\n";

	myfile.open("OutputLog.txt");//Open file steam for program

	bool exit = false; //Begining exit value

	cout << "Choose an action by pressing the number for the action (1,2,3...):\n(1)Check if List is Empty\n(2)Check List Size\n(3)Get an Element from the List\n(4)Set and ELement in the List\n(5)Add and Element to the List\n(6)Remove an Element from the List\n(7)Exit the Program\n\n";
	myfile << "Choose an action by pressing the number for the action (1,2,3...):\n(1)Check if List is Empty\n(2)Check List Size\n(3)Get an Element from the List\n(4)Set and ELement in the List\n(5)Add and Element to the List\n(6)Remove an Element from the List\n(7)Exit the Program\n\n";
	
	//User interface loop. Exits loop when the exit value is true (Option 7)
	do
	{
		cin >> choice;
		myfile << "Choice" << choice <<endl;
		
		switch (choice)
		{
		case 1:
			isEmpty();
			break;
		case 2:
			size();
			break;
		case 3:
			cout << "Get which index in the list? (0,1,2,3...)\n";
			cin >> i;
			get(i);

			myfile << "Get which index in the list? (0,1,2,3...)\n";
			myfile << i << endl;
			break;
		case 4:
			cout << "Set which index in the list? (0,1,2,3...)\n";
			cin >> i;
			cout << "Value for this index in the list? (0,1,2,3...)\n";
			cin >> o;
			set(i, o);

			myfile << "Set which index in the list? (0,1,2,3...)\n";
			myfile << i << endl;
			myfile << "Value for this index in the list? (0,1,2,3...)\n";
			myfile << o << endl;
			break;
		case 5:
			cout << "Add at which index in the list? (0,1,2,3...)\n";
			cin >> i;
			cout << "Value for this index in the list? (0,1,2,3...)\n";
			cin >> o;
			add(i, o);

			myfile << "Add at which index in the list? (0,1,2,3...)\n";
			myfile << i << endl;
			myfile << "Value for this index in the list? (0,1,2,3...)\n";
			myfile << o << endl;
			break;
		case 6:
			cout << "Remove at which index in the list? (0,1,2,3...)\n";
			cin >> i;
			remove(i);

			myfile << "Remove at which index in the list? (0,1,2,3...)\n";
			myfile << i << endl;
			break;
		case 7:
			exit = true;

			myfile << "Exiting program: " << exit <<endl;
			break;
		default:
			cout << "\nYou have input an improper selection, please choose again\n\"" ;
			myfile << "\nYou have input an improper selection, please choose again\n";
			break;
		}

		//Outputs the current List to the console
		cout << "Current List: ";
		myfile << "Current List: ";
		for (int i = 0; i < sizeList; i++)
		{
			cout << list[i] << "; ";
			myfile << list[i] << "; ";
		}
		cout << endl;
		myfile << endl;

	} while (exit == false);


	
	
	myfile << "The total amout of steps taken during this session was: " << allSteps << endl; //Outputs total number of steps taken in this session
	myfile.close(); //Close file stream

	return 0;
}

