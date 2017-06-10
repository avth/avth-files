/*
 * @ Author	:	Amsavarthini Easwaran
 * @Started	:	11-11-2016
 *
 * Class Name	:	algorithms.cpp
 */ 

class datastructures {
	public:
		datastructures();
		~datastructures();
		virtual void dsInfo();
};

datastructures::datastructures() {
}
datastructures::~datastructures() {
}

void datastructures::dsInfo() {
	cout<<"\n Data Structures Implememted:";
	cout<<" Stacks Using Arrays.";
	cout<<" Postfix Operation On Stack Using Arrays.";
	cout<<endl;	
}

