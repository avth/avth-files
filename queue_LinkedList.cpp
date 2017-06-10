/*
 * @Author 		:	Amsavarthini Easwaran
 * @Date Started	:	3/29/2017
 */

typedef int queueKey;

class Queue_LinkedList : public datastructures {
	public:
		Queue_LinkedList();
		~Queue_LinkedList();
		void dsInfo();
		void getInput();
		void enqueue(queueKey inpQue);
		queueKey dequeue();
		void traverseQueue();
	private:
		queueKey *queue;
		char queCh;
		int queOpCh,num,poppedValue;
		bool queueLLEmpty;
		struct node {
			queueKey data;
			struct node *next;	//	points to the next node
			struct node *prev;	//	points to the prev node
		};
		struct node *head,*last,*traQueList,*exitNode;	//	head,last are pointers of type node
};

Queue_LinkedList::Queue_LinkedList() {
	num=queOpCh=poppedValue=0;
	queCh='y';
	head=new node;
	last=new node;
	head->next=last;
	last->next=last;
	last->prev=head;
	queueLLEmpty=true;
}

Queue_LinkedList::~Queue_LinkedList() {
}

void Queue_LinkedList::dsInfo(){
	cout<<"\n Implementing Queue Linked List:";
	Queue_LinkedList::getInput();
}

void Queue_LinkedList::enqueue(queueKey inpQue) {
	struct node *firstNode=new node;

	firstNode->data=inpQue;
	firstNode->next=head->next;
	head->next=firstNode;
	if (firstNode->next!=last) {
		firstNode->next->prev=firstNode;
	}
	else {
		last->prev=firstNode;
	}
	firstNode->prev=head;
	queueLLEmpty=false;
}

queueKey Queue_LinkedList::dequeue() {
	exitNode=last->prev;
	poppedValue=exitNode->data;
	last->prev=exitNode->prev;
	exitNode->prev->next=last;
	delete exitNode;
	return poppedValue;
}

void Queue_LinkedList::traverseQueue() {
	cout<<"\n Queue Elements In LinkedList Are from forward to backward:\t";
	traQueList=head;
	cout<<"\n Queue Entry-->";
	while(traQueList->next!=last) {
		traQueList=traQueList->next;
		cout<<traQueList->data<<"-->";
	}
	cout<<"Queue Exit\n";
}

void Queue_LinkedList::getInput() {

	while(queCh=='y') {

	cout<<"\n1.ENQUEUE - PUSH TO QUEUE";
	cout<<"\n2.DEQUEUE - POP FROM QUEUE";
	cout<<"\n3.TRAVERSE QUEUE";
	cout<<"\n Enter Choice:\t\t";
	cin>>queOpCh;
	
		switch(queOpCh) {
			case 1:
				cout<<" Input # to enter in Queue:";
				cin>>num;
				Queue_LinkedList::enqueue(num);
				break;
			case 2:
				poppedValue=Queue_LinkedList::dequeue();
				cout<<"\n Popped Value From Queue:"<<poppedValue;
				break;
			case 3:
				Queue_LinkedList::traverseQueue();
				break;
			default:
				cerr<<"\n Wrong Choice:";
		}	//	switch loop ends here
		cout<<" Do You Want To Continue (y/n) ?\t";
		cin>>queCh;
		if(queCh=='n')	break;
	}
}
