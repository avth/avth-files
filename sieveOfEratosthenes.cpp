/*
 * @Author	:	Amsavarthini Easwaran
 * @Started	:	11-01-2016
 */

class primeNos: public algorithms {
	private:
		int i,j,countOfPrime,*primeNosArr;
	public:
		primeNos();
		~primeNos();
		void getInput();
		void sieveOfEratosthenes();
		void printPrimeNos();
		void algoInfo();
};

primeNos::primeNos() {
	cout<<"\nConstructing PrimeNos:";
	i=j=countOfPrime=0;
	
}

primeNos::~primeNos() {
	cout<<"\nDestructing PrimeNos:";
}

void primeNos::algoInfo() {
	primeNos::getInput();
	primeNos::sieveOfEratosthenes();
	primeNos::printPrimeNos();
}

void primeNos::getInput() {
	cout<<"\nEnter Count Of Prime Nos To Be Displayed:";
	cin>>countOfPrime;
	primeNosArr = new int[countOfPrime];
	for(primeNosArr[1]=0,i=2;i<countOfPrime;i++){
		primeNosArr[i]=1;
	}
}
	
void primeNos::sieveOfEratosthenes() {
	for(i=2;i<=countOfPrime/2;i++) {
		for(j=2;j<=countOfPrime/i;j++) {
			primeNosArr[i*j]=0;
		}
	}
}

void primeNos::printPrimeNos() {
	cout<<"\nPrime Nos Below : "<<countOfPrime<<endl;
	for(i=1;i<=countOfPrime;i++) {
		if(primeNosArr[i]) cout <<i<<"\t";
	}
}
