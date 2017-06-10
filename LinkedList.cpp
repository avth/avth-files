//	LINKED LIST IMPLEMENTATION
/*	AUTHOR	:	AMSAVARTHINI EASWARAN
 *	DATE		:	05/10/2017
 */

typedef int itemIntType;

class LinkedList:public datastructures {
	private:
		struct node {
			int key;
			struct node *next;
		};
		struct node *head,*last,*traLL,*searchNodes,*currentNode,*previousNode;
		bool llistEmpty,searchResult,delNodeResult;
		char llChoice;
		int llOpChoice;
		itemIntType llValue,positionOfNode,seaNum,delNode;
	public:
		LinkedList();
		~LinkedList();
		void getInput();
		void insertToLL(itemIntType v);
		void traverseLL();
		bool deleteFromLL(itemIntType);
		bool searchLL(itemIntType v);
		void dsInfo();
		itemIntType getSearchInput();
		itemIntType getDelNumInput();
		bool checkLLEmpty();
		void printSearchResult(bool,itemIntType,itemIntType);
		void printDeleteResult(bool,itemIntType);
};

LinkedList::LinkedList() {
	llChoice='y';
	llOpChoice=llValue=positionOfNode=seaNum=0;
	head=new node;
	last=new node;
	head->next=last;
	last->next=last;
	llistEmpty=true;
	searchResult=false;
}

LinkedList::~LinkedList() {
}

void LinkedList::dsInfo() {
	cout<<"\n IMPLEMENTING LINKED LIST:";
	LinkedList::getInput();
}

void LinkedList::insertToLL(itemIntType v) {
	struct node *pushNode;
	pushNode=new node;
	pushNode->key=v;
	pushNode->next=head->next;
	head->next=pushNode;
	llistEmpty=false;
}

bool LinkedList::searchLL(itemIntType v) {
	searchNodes=head;
	while(searchNodes->next!=last) {
		searchNodes=searchNodes->next;
		positionOfNode++;
		if (v==searchNodes->key) {
			searchResult=true;
			return searchResult;
		}
		else continue;
	}	//WHILE LOOP ENDS HERE
	return false;
}	//	METHOD searchLL ENDS HERE

bool LinkedList::deleteFromLL(itemIntType v)
{
	currentNode=previousNode=head;
	while(currentNode->next!=last) {
		currentNode=currentNode->next;
		if(currentNode->key==v) {
			previousNode->next=currentNode->next;
			delete currentNode;
			return true;
		}
		else {
			previousNode=previousNode->next;
		}
	}
}

void LinkedList::traverseLL() {
	traLL=head;
	cout<<" "<<"Head-->";
	while(traLL->next!=last) {
		traLL=traLL->next;
		cout<<traLL->key<<"-->";
	}
	cout<<"Last\n";
}

bool LinkedList::checkLLEmpty(){
	if (llistEmpty==true) {
		cout<<" linked list is empty\n";
	}
	return llistEmpty;
}

itemIntType LinkedList::getSearchInput() {
	cout<<" enter # to search:\t";
	cin>>seaNum;
	return seaNum;
}

void LinkedList::printSearchResult(bool searchR,itemIntType seaNum,itemIntType position) {
	if (searchR) {
		cout<<" "<<seaNum<<" is found at position :"<<position<<"\n";
	}
	else {
		cout<<" "<<seaNum<<" is not present in the linked list"<<"\n";
	}
}

itemIntType LinkedList::getDelNumInput() {
	cout<<" enter # to delete :";
	cin>>delNode;
	return delNode;
}

void LinkedList::printDeleteResult(bool delNodeResult,itemIntType delNode) {
	if (delNodeResult) {
		cout<<" "<<delNode<<" is deleted from linked list";
	}
}

void LinkedList::getInput() {
	while (llChoice=='y') {
		cout<<"\n 1.INSERT NODE ";
		cout<<"\n 2.TRAVERSE LINKED LIST"; 
		cout<<"\n 3.SEARCH NODE";
		cout<<"\n 4.DELETE NODE";
		cout<<"\n Enter linked list operation choice:\t";
		cin>>llOpChoice;

		switch(llOpChoice) {
		case 1:
			cout<<" Enter value to insert into linked list:\t";
			cin>>llValue;
			LinkedList::insertToLL(llValue);
			break;
		case 2:
			cout<<" Values in linked list:\t";
			LinkedList::traverseLL();
			break;
		case 3:
			llistEmpty=checkLLEmpty();
			if(!llistEmpty) {
				LinkedList::traverseLL();
				seaNum=LinkedList::getSearchInput();
				searchResult=LinkedList::searchLL(seaNum);
				LinkedList::printSearchResult(searchResult,seaNum,positionOfNode);
				positionOfNode=0;
				searchResult=false;
			}
			break;
		case 4:
			llistEmpty==checkLLEmpty();
			if(!llistEmpty) {
				LinkedList::traverseLL();
				delNode=LinkedList::getDelNumInput();
				searchResult=LinkedList::searchLL(delNode);
				LinkedList::printSearchResult(searchResult,delNode,positionOfNode);
				if (searchResult) {
					delNodeResult=LinkedList::deleteFromLL(delNode);
					LinkedList::printDeleteResult(delNodeResult,delNode);
					LinkedList::traverseLL();
					positionOfNode=0;
					searchResult=false;
				}
			}
			break;
		default:
			cerr<<" wrong choice";
		}//	SWITCH CASE LOOP ENDS HERE
		cout<<" continue another operation (y/n) ?\t";
		cin>>llChoice;
		if (llChoice=='n')	break;
	}	//	WHILE LOOP ENDS HERE
}	//	METHOD ENDS HERE
