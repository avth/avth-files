/*
 *@Author	:	Amsavarthini Easwaran
* @Date Started	:	03-23-2017
 */
typedef char itemCharType;

class Stack_LinkedList : public datastructures {
	public:
		Stack_LinkedList();
		~Stack_LinkedList();
		void dsInfo();
		void getInput();
		void push(itemCharType v);
		itemCharType pop();
		void traverse();
		bool isEmpty();
	private:
		char stChoice,stValue;
		itemCharType poppedValue;
		int stOpChoice;
		bool stackLLEmpty;
		struct node {
			itemCharType key;
			struct node *next;
		};
		struct node *head,*last,*traList,*popNode;
};

Stack_LinkedList::Stack_LinkedList(){
	stChoice='y';
	stValue=' ';
	stOpChoice=0;

	head=new node;
	last=new node;
	head->next=last;
	bool stackLLEmpty=true;
	last->next=last;
}

Stack_LinkedList::~Stack_LinkedList() {
}

bool Stack_LinkedList::isEmpty() {
	if(head->next==last) 
		stackLLEmpty=true;
	else
		stackLLEmpty=false;
	
	return stackLLEmpty;
}

void Stack_LinkedList::dsInfo() {
	cout<<"\n Implementing Stack Linked List:";
	Stack_LinkedList::getInput();
}

void Stack_LinkedList::traverse() {
	traList=head;
	cout<<"head-->";
	while (traList->next!=last) {
		traList=traList->next;
		cout<<traList->key<<"-->";
	}
	cout<<"last";
}

void Stack_LinkedList::push(itemCharType v) {
	cout<<"\n Inside the push operation of stack:";
	struct node *push=new node;
	push->key=v;
	push->next=head->next;
	head->next=push;
	stackLLEmpty=false;
}

itemCharType Stack_LinkedList::pop(){
	cout<<"\n Inside the Pop operation of stack:";
	popNode=head->next;
	poppedValue=popNode->key;
	head->next=popNode->next;
	delete popNode;
	return poppedValue;
}

void Stack_LinkedList::getInput() {
	while (stChoice=='y') {
		cout<<"\n1. PUSH";
		cout<<"\n2. POP";
		cout<<"\n3. TRAVERSE";
		cout<<"\n Enter Stack Operation Choice:\t\t";
		cin>>stOpChoice;

		switch(stOpChoice) {
			
		case 1:
			cout<<" Enter Value To Be Pushed:\t\t";
			cin>>stValue;
			Stack_LinkedList::push(stValue);
			break;
		case 2:
			if(Stack_LinkedList::isEmpty()==true) {
				cout<<"\n Stack Is Empty. No values to pop:";
				break;
			}
			else {
				poppedValue=Stack_LinkedList::pop();
				cout<<" Value Popped Is:"<<poppedValue;
				break;
			}
		case 3:
			if(Stack_LinkedList::isEmpty()==true) {
				cout<<"\n Stack Is Empty. No values to Traverse:";
				break;
			}
			else {
				cout<<" Values in Stack Using Linked List:\t\t";
				Stack_LinkedList::traverse();
				break;
			}
		default:
			cerr<<"\n Wrong Choice";

		}	//	switch case ends here
		cout<<"\n Continue Another Operation (y/n)?\t";
		cin>>stChoice;
		if(stChoice=='n')	break;
	}	//	while loop ends here
}
