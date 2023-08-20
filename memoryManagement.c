#include<stdio.h>
#include<stdlib.h>



void stacktest(int counter){
	if (counter == 5){
		return;
	}
	counter += 1;
	printf("address of counter : %lli\n", &counter);
	return stacktest(counter);
}

int gv1 = 33;
int gv2 = 12;
int gv3 = 6;

int main(){
	printf("HEAPTESTING\n");
	//heap test part
	int *ptr = (int *)malloc(1 * sizeof(int));
	long long int adrPtr = &ptr;
	printf("address of ptr : %lli\n", adrPtr);

	int *ptr2 = (int *)malloc(1 * sizeof(int));
	long long int adrPtr2 = &ptr2;
	printf("address of ptr2: %lli\n", adrPtr2);
	
	int *ptr3 = (int *)malloc(2 * sizeof(int));
	long long int adrPtr3 = &ptr3;
	printf("address of ptr3: %lli\n", adrPtr3);

	printf("size of all memory allocation : %lli\n", adrPtr3-adrPtr);
	printf("\n==================================\n\n");
	//stacktest part
	printf("STACKTESTING\n");
	stacktest(0);


	
	printf("\n==================================\n\n");
	printf("DATATESTING\n");
	printf("address of gv1: %lli\n", &gv1);
	printf("address of gv2: %lli\n", &gv2);
	printf("address of gv3: %lli\n", &gv3);

	printf("\n==================================\n\n");

	


}
//140737488346280
//140737488346288
