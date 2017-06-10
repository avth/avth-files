
class sortAlgorithms : public algorithms {
	public:
		sortAlgorithms();
		~sortAlgorithms();
		void algoInfo();
};

void sortAlgorithms::algoInfo() {
	cout<<"\n Sorting Algorithms Implemented :";
	cout<<"\n BubbleSort Using Arrays .";
}

sortAlgorithms::sortAlgorithms() {
	cout<<"\nConstructing sortAlgorithms";
}
sortAlgorithms::~sortAlgorithms() {
	cout<<"\nDestructing sortAlgorithms";
}
