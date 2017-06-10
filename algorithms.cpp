/*
 * @ Author	:	Amsavarthini Easwaran
 * @Started	:	10-31-2016
 *
 * Class Name	:	algorithms.cpp
 */ 

//class algorithms: public datastructures {

class algorithms {
	public:
		algorithms(); 
		~algorithms();
		virtual void algoInfo();
};

algorithms::algorithms() {
}
algorithms::~algorithms() {
}

void algorithms::algoInfo() {
	cout<<"\n *************************************************************";
	cout<<"\n Algorithms Implemented are Bubble Sort, Sieve Of Eratosthenes, ";
	cout<<"\n Josephus Algorithm & Euclid Algorithm";
	cout<<"\n *************************************************************";
}

class sortAlgorithms : public algorithms{
	public:
		sortAlgorithms();
		~sortAlgorithms();
		void algoInfo();
};

void sortAlgorithms::algoInfo() {
	cout<<"\n *************************************************************";
	cout<<"\n Sorting Algorithms Implemented :";
	cout<<"\n BubbleSort Using Arrays .";
	cout<<"\n *************************************************************";
}

sortAlgorithms::sortAlgorithms() {
}
sortAlgorithms::~sortAlgorithms() {
}
