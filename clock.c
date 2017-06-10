/*
 *	@Author		:	Amsavarthini Easwaran
 *	@Started	:	11-08-2016
 */
#include <time.h>
#include <stdio.h>

void fun() {
	printf("fun() starts:");
	printf("press enter to stop fun:");
	while(1) {
		if(getchar())	break;
	}
	printf("fun() ends:");
}

int main() {
//	clock_t start,end;
	int i=0;
	clock_t ticks;
	long count;
	time_t startTime, stopTime;
	double time_taken,s,e;

	time(&startTime);
	fun();
	while(i<500) {
		i++;
		ticks=clock();
	}
	time(&stopTime);

	//printf("Used %0.2f seconds of CPU Time",(double)ticks/CLOCKS_PER_SEC);
	printf("Finished in about %.0f seconds",difftime(stopTime,startTime));
	

	/*for(int i=0;i<5;i++) {
	int first_clock=clock();
	int first_time=time(NULL);
	
	while(time(NULL) <=first_time) { }

	int second_time=time(NULL);
	int second_clock=clock();

	cout<<"\nActual Clocks / Second:"<<(second_clock-first_clock)/(second_time-first_time);
	cout<<"\nCLOCKS_PER_SEC:"<<CLOCKS_PER_SEC<<"\n";
	}

	clock_t c_start=clock();
	time_t now=time(0);
	
	for(int i=0;i<115;i++) {
		cout<<"hello\t\n"<<i;
	}
	clock_t c_end=clock();
	time_t after=time(0);

	cout<<std::fixed<<"\n CPU Time Used:"
		<<(c_end-c_start)/(double)(CLOCKS_PER_SEC/1000);

	cout<<"\ntime:\t"<<after-now<<endl;
	

	start=clock();
	s=(double)start;
	fun();
	end=clock();
	e=(double)end;
	time_taken=((double)(end-start))/CLOCKS_PER_SEC;
	
	printf("execution begins @ :%lf\n",s);
	printf("execution ends @ :%lf\n",e);
	printf("fun() took %lf seconds to execute",time_taken);
	return 0;
	*/
}

