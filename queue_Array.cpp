/*
 * @Author 		:	Amsavarthini Easwaran
 * @Date Started	:	3/29/2017
 */

typedef int queueArr;

class Queue_Array : public datastructures {
	public:
		Queue_Array();
		~Queue_Array();
		void dsInfo();
		void getInput();
		void getSizeOfArray();
		void initializeArray();
		void enqueue(queueArr inpQue);
		queueArr dequeue();
		bool isQueueFull();
		void traverseQueue();
	private:
		queueArr *queue;
		char queCh;
		int sizeOfArray,queOpCh;
		int num,poppedValue;
		int head,tail;
		int head_position,tail_position;
		bool queueFull;
};

Queue_Array::Queue_Array() {
	num=sizeOfArray=queOpCh=poppedValue=0;
	queCh='y';
	head=0;
	tail=head+1;
}

Queue_Array::~Queue_Array() {
}

void Queue_Array::dsInfo(){
	Queue_Array::getSizeOfArray();
	Queue_Array::initializeArray();
	Queue_Array::getInput();
}

void Queue_Array::getSizeOfArray() {
	cout<<"\n Input Size Of Array:";
	cin>>sizeOfArray;
}

bool Queue_Array::isQueueFull() {
	if(tail==sizeOfArray)	{
		cout<<"\n QUEUE IS FULL:";
		queueFull=true;
		return true;
	}
	queueFull=false;
	return false;
}

void Queue_Array::initializeArray() {
	queue=new queueArr[sizeOfArray];
	head_position=queue[head];
	tail_position=queue[head+1];
	queueFull=false;
}

void Queue_Array::enqueue(queueArr inpQue) {
	if(tail!=sizeOfArray) {
		queue[tail]=inpQue;
		tail_position=queue[tail++];
	}
}

queueArr Queue_Array::dequeue() {
	if(head++!=tail) {
		poppedValue=queue[head];
		head_position=queue[head];
	}
	return poppedValue;
}

void Queue_Array::traverseQueue() {
	cout<<"\n Queue Elements Are:\t";
	for(int traQue=head+1;traQue<tail;traQue++) {
		cout<<queue[traQue]<<"\t";
	}
}

void Queue_Array::getInput() {

	while(queCh=='y') {

	cout<<"\n1.ENQUEUE - PUSH TO QUEUE";
	cout<<"\n2.DEQUEUE - POP FROM QUEUE";
	cout<<"\n3.TRAVERSE QUEUE";
	cout<<"\n Enter Choice:\t\t";
	cin>>queOpCh;
	
		switch(queOpCh) {
			case 1:
				if(!Queue_Array::isQueueFull()) {
				cout<<" Input # to enter in Queue:";
				cin>>num;
				Queue_Array::enqueue(num);
				}
				break;
			case 2:
				poppedValue=Queue_Array::dequeue();
				cout<<"\n Popped Value From Queue:"<<poppedValue;
				break;
			case 3:
				Queue_Array::traverseQueue();
				break;
			default:
				cerr<<"\n Wrong Choice:";
		}	//	switch loop ends here
		cout<<" Do You Want To Continue (y/n) ?\t";
		cin>>queCh;
		if(queCh=='n')	break;
	}
}
