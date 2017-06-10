/*
 * @Author	:	Amsavarthini Easwaran
 * @Started	:	10-31-2016
 * 
 * Class Name	:	euclid
 */ 

class euclid : public algorithms {
	
	private:
		int numerator, denominator;
		int temp,gcd;

	public :
		euclid();
		void algoInfo();
		void enterNumDen();
		int computeGCD();
		void printGCD(int);
		~euclid(); 
};

euclid::euclid() {
	numerator=denominator=0;
	temp=gcd=0;
	cout<<"\nConstructing euclid:\n";
}

void euclid::algoInfo() {
	euclid::enterNumDen();
	gcd=euclid::computeGCD();
	euclid::printGCD(gcd);
}

void euclid::enterNumDen() {

	cout<<"\nEnter Numerator:";
	cin>>numerator;
	cout<<"\nEnter Denominator:";
	cin>>denominator;
}

/*
 *	Computes the GCD
 */
int euclid::computeGCD() {
	while(numerator > 0) {
		if(numerator < denominator) {
			temp=numerator;
			numerator=denominator;
			denominator=temp;
		}
	//	numerator=numerator-denominator;
		numerator=numerator%denominator;
	}
	return denominator;
}

/*
 *	Prints the GCD
 */ 
void euclid::printGCD(int gcd) {
	cout<<"\nGCD is :"<<gcd<<endl;
}

euclid::~euclid() {
	cout<<"\nDestructing euclid";
}
