#include<iostream>
using namespace std;
#include <stdlib.h>

#define MAX 50

class BubbleSort : public sortAlgorithms{

private:
	int temp;
	int countInLoop,count;
	bool swapped;
	int inputArr[MAX];

public:
	BubbleSort();
	void printOriginalArr(int originalArr[],int max);
	void bubbleSortArr(int arrToSort[],int max);
	void printSortedArr(int sortedArr[],int max);
	void algoInfo();
	int enterCountAndNumbersInArray(int[]);
	~BubbleSort();

};

BubbleSort::BubbleSort() {
	temp=0;
	countInLoop=0;
	count=0;
	swapped=true;
	for(int i=0;i<MAX;i++) {
		inputArr[i]=0;
	}
}

BubbleSort::~BubbleSort() {
}

void BubbleSort::algoInfo() {
	cout<<"\n In Bubble Sort:";
	BubbleSort::enterCountAndNumbersInArray(inputArr);
}

int BubbleSort::enterCountAndNumbersInArray(int inputArr[]) {

	cout<<"\n enter the count of #s to sort : "<<"\t";
	cin>>count;
	cout<<"\n enter number in the array:"<<"\t";
	for(int j=0;j<count;j++) {
		cin>>inputArr[j];
	}
	
	BubbleSort::printOriginalArr(inputArr,count);
}

void BubbleSort::printOriginalArr(int originalArr[],int max) {
	cout<<endl;
	cout<<"Original Array:"<<endl;
	for(int i=0;i<max;i++) {
		cout<<originalArr[i]<<"\t";
	}
	cout<<endl;
	BubbleSort::bubbleSortArr(inputArr,max);
}

void BubbleSort::bubbleSortArr(int arrToSort[],int max) {
	
	for(int j=0;j<max;) {
		if(swapped==true && countInLoop==max-1)	break;
		for(int k=j+1;k<max;) {
			if(arrToSort[j]<=arrToSort[k]) {
				countInLoop++;
				j++;k++;
				if(countInLoop==max-1) {
					swapped=true;
					break;
				}
				if(k==max) {
					countInLoop=0;
					j=0;
					break;
				}
			}
			else {
				swapped=false;
				countInLoop=0;
				temp=arrToSort[k];
				arrToSort[k]=arrToSort[j];
				arrToSort[j]=temp;
				j++; k++;
				if(k==max) {
					j=0;		
					break;		
				}
			}
		}	//	for loop 'k' ends here
	}	//	for loop 'j' ends here
	BubbleSort::printSortedArr(arrToSort,max);
}	//	method 'bubbleSortArr' ends here

void BubbleSort::printSortedArr(int sortedArr[],int max) {
	cout<<"Sorted Array:"<<endl;
	for(int l=0;l<max;l++) {
		cout<<sortedArr[l]<<"\t";
	}
	cout<<endl;
}	//	method printSortedArr ends here
