/*
 * @Author 	:	Amsavarthini Easwaran
 * @Started	:	11-03-2016
 */
#include <cstdio>
#include <ctime>
using namespace std;
	
typedef char itemType;

//	class Stack

class Stack : public datastructures {
	private:
		time_t start,stop;
		itemType *stack;
		int p,top,stOpChoice,stackSize;
		char stChoice, stValue;
		bool stackFull,stackCreated;
	public:
		Stack();
		~Stack();
		void dsInfo();
		void push(itemType v);
		itemType pop();
		void getInput();
		bool isStackFull();
		bool isStackEmpty();
		void printStackElements();
//		void howManyElementsInStack();
};

Stack::Stack() {
	p=stackSize=0;
	top=-1;
	stChoice='y';
	stackCreated=stackFull=false;
}
//	destructor
Stack::~Stack() {
	if(stackCreated) delete []stack;
}

void Stack::dsInfo() {
	cout<<"\n Stack Operations Push, Pop Using Arrays:";
	cout<<"\n Input A Number To Create Size Of The Stack:";
	cin>>stackSize;
	stack=new itemType[stackSize];
	stackCreated=true;
	Stack::getInput();
}

//	push the elements in the stack
void Stack::push(itemType v) {
	stack[p]=v;
	top=p;
	p++;
	if(p==stackSize) {
		stackFull=true;
	}
}

//	pop the elements out of the stack
itemType Stack:: pop() {
	p=top;
	if (p==0)	{
		stackFull=false;
		return stack[p];
	}
	else {
		return stack[p];
	}
}

bool Stack::isStackFull() {
	if(p==stackSize && stackFull==true) {
		cout<<"\n Stack Full:";
		stackFull=true;
		return true;
	}
	return false;
}

bool Stack::isStackEmpty() {
	if (top==-1) {
		cout<<"\n Stack Empty:"<<endl;
		stackFull=false;
		return true;
	}
	return false;
}

//	prints the stack elements
void Stack::printStackElements() {
	cout<<" Elements In Stack:";
	for(;top>=0;top--) {
		cout<<"\t\t"<<stack[top]<<"\t";
	}
	top=p-1;
	cout<<"\n";
}

//	gets the input for the push & pop operation
void Stack::getInput() {

	time(&start);
  	while(stChoice=='y') {
 
		cout<<"\n 1. PUSH";
		cout<<"\n 2. POP";
		cout<<"\n 3. TRAVERSE";
		cout<<"\n Enter Stack Operation Choice :\t\t";
		cin>>stOpChoice;

		switch(stOpChoice) {
 
		case 1: 
			if(!Stack::isStackFull()) {	
	 			cout<<" Enter Value To Be Pushed:\t\t";
				cin>>stValue;
				Stack::push(stValue);
			}
			break;
		case 2:
			if(!Stack::isStackEmpty()) {
	 			cout<<" Value deleted:\t\t"<<Stack::pop();
				top--;
				cout<<"\n";
			}
 			break;
 		case 3:
			if(!Stack::isStackEmpty()) {	
 				Stack::printStackElements();
			}
 			break;
 		default:
 			cerr<<"\nWrong Choice:";
 		}
 
 		cout<<" Do You Wish To Continue(y/n) ? \t";
 		cin>>stChoice;
		if(stChoice=='n') {
			time(&stop);
			cout<<"\nStack Algorithm Completed After :"<<difftime(stop,start)<<" seconds .";
			 break;
		}
 	}
}
