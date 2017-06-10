/*
 * @Author 	:	Amsavarthini Easwaran
 * @Started	:	11-07-2016
 */

#include <unistd.h>

typedef int postfixItemType;

//	class Stack

class PostfixStack : public Stack{
	private:
		postfixItemType *stack1;
		int p,top,x, postfixStackSize;
		char c;
		bool postfixStackCreated;
	public:
		PostfixStack();
		~PostfixStack();
		void push(postfixItemType v);
		postfixItemType pop();
		void getInput();
		void printStackElements();
		void dsInfo();
};

//	default constructor
PostfixStack::PostfixStack() {
	postfixStackSize=50;
	postfixStackCreated=true;
	stack1=new postfixItemType[postfixStackSize];
	p=top=x=0;
	c=' ';
}

//	destructor
PostfixStack::~PostfixStack() {
	if(postfixStackCreated) delete[]stack1;
}

void PostfixStack::dsInfo() {
	cout<<"\n PostfixStack Operation Using Arrays:";
	PostfixStack::getInput();
}

//	push the elements in the stack1
void PostfixStack::push(postfixItemType v) {
	stack1[p]=v;
	top=p;
	p++;
}

//	pops the element out of the stack1
postfixItemType PostfixStack::pop() {
	--top;
	return stack1[--p];
}
//	gets the input for the push & pop operation
void PostfixStack::getInput() {
	
	cout<<"\n enter 'q' to quit"<<endl;
	while(c!='q') {
		cout<<"\n value of x\t\t : " <<x;
		cout<<"\n enter character\t : ";
		cin>>c;

		x=0;
	//	while(c==' ') cin.get(c);
		if(c=='q')	break;
		if(c=='*')	{
			x=PostfixStack::pop() * PostfixStack::pop();
			PostfixStack::push(x);
		}
		if(c=='+')	{
			x=PostfixStack::pop() + PostfixStack::pop();
			PostfixStack::push(x);
		}
		while(c>='0' && c<='9') {
			x=(10*x) + (c-'0');
			PostfixStack::push(x);
			cin.get(c);
		}
	}	
	cout<<"\nFinal Output Value:"<<PostfixStack::pop();
}
