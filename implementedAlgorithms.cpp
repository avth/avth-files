/*
 *      
 *   /\    |             .  |  |
 *  /- \   | --- ---  |- | - - |    |\  /|  ---
 *	/    \  |( _||   | |  |  |  | -| | \/ |  |__
 *	          _ | ---  |  |  |  |  | |    |   __|
 *
 *
 */

#include<iostream>
using namespace std;
#include <stdlib.h>
#include "dataStructures.cpp"
#include "algorithms.cpp"
#include "stack.cpp"
#include "postfixStack.cpp"
#include "bubbleSort.cpp"
#include "euclid.cpp"
#include "sieveOfEratosthenes.cpp"
#include "josephus.cpp"
#include "conversion.cpp"
#include "deciToBinary.cpp"
#include "stacks_linkedList.cpp"
#include "queue_Array.cpp"
#include "queue_LinkedList.cpp"
#include "LinkedList.cpp"
#include "factorial.cpp"

class MainDisplay {
	
	public:
	MainDisplay();
	~MainDisplay();
	void displayOptions();
	void dataStructures();
	void sortingAlgorithms();
	int enterCountAndNumbersInArray(int[]);
	void euclidAlgorithm();
	void josephusAlgorithm();
	void sievePrimeNos();
	void conversion();
	void recursionAlgorithms();

	private:
	char algoChoice,userChoice;
	int convChoice,dsChoice,sortChoice,count;
};

MainDisplay::MainDisplay() {
	cout<<"\nConstructing MainDisplay:";
	userChoice='y';
	algoChoice=' ';
	dsChoice=sortChoice=count=0;
}

MainDisplay::~MainDisplay() {
	cout<<"Destructing MainDisplay:";
}

void MainDisplay::displayOptions() {

	while(userChoice=='y') {

	cout<<"\nData Structures & Algorithms Implemented In C++\n";
	cout<<"--------------------"<<endl;
	cout<<"A.Data Structures"<<endl;
	cout<<"B.Sorting Algorithms"<<endl;
	cout<<"C.Euclid Algorithm"<<endl;
	cout<<"D.Sieve Of Eratosthenes"<<endl;
	cout<<"E.Josephus Problem"<<endl;
	cout<<"F.Number Conversion"<<endl;
	cout<<"G.Recursion Algorithms"<<endl;
	cout<<"Q.Quit"<<endl;
	cout<<"Enter Algorithm Choice:";
	cin>>algoChoice;


		switch(algoChoice) {

		case 'A':
		case 'a':
			MainDisplay::dataStructures();
			break;
		case 'B':
		case 'b':
			MainDisplay::sortingAlgorithms();
			break;
		case 'C':
		case 'c':
			MainDisplay::euclidAlgorithm();
			break;
		case 'D':
		case 'd':
			MainDisplay::sievePrimeNos();
			break;
		case 'E':
		case 'e':
			MainDisplay::josephusAlgorithm();
			break;
		case 'F':
		case 'f':
			MainDisplay::conversion();
			break;
		case 'G':
		case 'g':
			MainDisplay::recursionAlgorithms();
			break;
		case 'Q':
		case 'q':
			cout<<"\n Quitting Application";
			break;
		default:
			cerr<<"\nWrong Choice .";
		}	
		if(algoChoice=='q' | algoChoice=='Q')	exit(0);
		cout<<"\n Do You Want To Do Another Operation. Continue (y/n) ? ";
		cin>>userChoice;
		if(userChoice=='n')	{
			exit(0);
		}
	}
}

void MainDisplay::recursionAlgorithms() {
	char userChoice='y';
	int recursionChoice;

	factorial fact;
	
	cout<<"\n1.Factorial Algorithm:";
	cin>>recursionChoice;
	while (userChoice=='y') {
		switch(recursionChoice) {
			case 1:
				fact.getUserInput();
				break;
			default:
				cerr<<"\n wrong choice:";
				break;
		}	
		cout<<"\n do you want to continue recursion algorithms (y/n) ?";
		cin>>userChoice;
		if(userChoice=='n')	break;
		else continue;
	}
}

void MainDisplay::conversion() {
	Conversion convObj,*convPtr;
	BinaryNumber binNumObj;

	convPtr=&convObj;
	convPtr->conversionInfo();

	while(userChoice=='y') {

	cout<<"\n 1. Decimal To Binary Conversion";
	cout<<"\n Enter Conversion Choice:\t";
	cin>>convChoice;

	switch(convChoice) {
		case 1:
			convPtr=&binNumObj;
			convPtr->conversionInfo();	
			break;
		default:
			userChoice='n';
			cerr<<"\nWrong Choice";
		}	//	switch case ends here	
		cout<<"\n Do you want to Continue Conversion (y/n) ?";
		cin>>userChoice;
		if(userChoice=='n') {
			userChoice='y';
			MainDisplay::displayOptions();
		}
	}	//	while loop ends here
}

void MainDisplay::dataStructures() {
	datastructures dsObj, *dsPtr;
	Stack stObj;	//	implementing stack using array
	PostfixStack pfsObj;
	Stack_LinkedList stLlObj;
	Queue_Array queArrObj;
	Queue_LinkedList queLlObj;
	LinkedList llObj;

	dsPtr=&dsObj;
	dsPtr->dsInfo();

	while(userChoice=='y') {

	cout<<"\n 1. Stacks - Implemented By Arrays";
	cout<<"\n 2. Postfix Stack Operation";
	cout<<"\n 3. Stacks - Implemented By LinkedList";
	cout<<"\n 4. Queues - Implemented By Arrays";
	cout<<"\n 5. Queues - Implemented By Linked Lists";
	cout<<"\n 6. Linked list";
	cout<<"\n Enter Data Structure Choice:\t";
	cin>>dsChoice;
	
	switch(dsChoice) {
		case 1:
			dsPtr=&stObj;
			dsPtr->dsInfo();
			break;
		case 2:
			dsPtr=&pfsObj;
			dsPtr->dsInfo();
			break;
		case 3:
			dsPtr=&stLlObj;
			dsPtr->dsInfo();	
			break;
		case 4:
			dsPtr=&queArrObj;
			dsPtr->dsInfo();
			break;
		case 5:
			dsPtr=&queLlObj;
			dsPtr->dsInfo();
			break;
		case 6:
			dsPtr=&llObj;
			dsPtr->dsInfo();
			break;
		default:
			userChoice='n';
			cerr<<"\nWrong Choice.\n";
		}	
		cout<<"\n Do You Want To Do Another Data Structure Operation. Continue (y/n) ? ";
		cin>>userChoice;
		if(userChoice=='n') {
			userChoice='y';
			MainDisplay::displayOptions();
		}
	}		
}

void MainDisplay::sortingAlgorithms() {
	
	algorithms alObj,*alPtr;
	sortAlgorithms sortObj,*sortPtr; 
	BubbleSort bsort;

	alPtr=&alObj;
	alPtr->algoInfo();
	sortPtr=&sortObj;
	sortPtr->algoInfo();

	cout<<"\n1.\tBubble Sort"<<endl;
	cout<<"\n2.\tInsertion Sort"<<endl;
	cout<<"\nSelect Sorting Algorithm:\t";
	cin>>sortChoice;

	switch(sortChoice) {
	
	case 1:
		alPtr=&bsort;
		alPtr->algoInfo();
		break;
	case 2:
		break;
	default:
		cout<<"\n Incorrect Choice. Exiting."<<endl;
		exit(0);
	}
}

void MainDisplay::euclidAlgorithm() {
	algorithms alObj, *alPtr;
	euclid egcd;	//	'egcd' is the object of type euclid

	alPtr=&alObj;
	alPtr->algoInfo();
	alPtr=&egcd;
	alPtr->algoInfo();
}

void MainDisplay::sievePrimeNos() {
	
	algorithms alObj,*alPtr;
	primeNos pn; //	primeNos is the class ; 'pn' is the type of class primeNos

	alPtr=&alObj;
	alPtr->algoInfo();
	alPtr=&pn;
	alPtr->algoInfo();
}

void MainDisplay::josephusAlgorithm() {
	algorithms alObj,*alPtr;
	josephus joe; 	//	joe is the type of class josephus

	alPtr=&alObj;
	alPtr->algoInfo();
	alPtr=&joe;
	alPtr->algoInfo();

//	joe.getInput();
//	joe.eliminatePersons();
}

int MainDisplay::enterCountAndNumbersInArray(int inputArr[]) {
	int count,i;
	
	cout<<"\nenter the count of #s to Sort:"<<"\t";
	cin>>count;

	cout<<"\nenter #s in the array:"<<"\t";
	for(i=0;i<count;i++) {
		cin>>inputArr[i];
	}
}

int main() {
	
	system("clear");

	MainDisplay mdObj, *mdPtr;
	mdPtr=&mdObj;
	mdPtr->displayOptions();
}
