/*
 * @Author	:	Amsavarthini Easwaran
 * @Started	:	11-02-2016
 *
 * Implemented using Data Structure : Circular Linked List
 */ 

class josephus : public algorithms{
	private:
	struct node {
		int key;
		struct node *next;
	};

	struct node *head,*last;
	
	int N,M,i;

	public:
		josephus();
		~josephus();
		void getInput();
		void eliminatePersons();
		void algoInfo();
};

josephus::josephus() {
	
	cout<<"\nConstructing Josephus";
	head=new node;
	head->key=1;
	last=head;
	
	M=N=i=0;
}

josephus::~josephus() {
	cout<<"\nDestructing Josephus";
}

void josephus::algoInfo() {
	josephus::getInput();
	josephus::eliminatePersons();
}

void josephus::getInput() {

	cout<<"\nEnter Total Number Of Persons:";
	cin>>N;
	cout<<"\nEnter The Order By Which Ppl Should Go Out:";
	cin>>M;
}

void josephus::eliminatePersons() {

	//	build the list
	for(i=2;i<=N;i++) {
		head->next=new node;
		head=head->next;
		head->key=i;
	}
	
	head->next=last;

	//	eliminate the persons
	while(head!=head->next) {
		for(i=1;i<M;i++) {
			head=head->next;
		}
		cout<<head->next->key<<"\t";
		last=head->next;
		head->next=last->next;
		delete last;
	}
	cout<<head->key;
}
