#include<stdio.h>
#include<omp.h>

#define NUM_THREADS 4 //define number of threads to use



int main(){
	
	int n_input;  //number of input
	int sum[NUM_THREADS]; // array of sum, each index for 1 thread
		
	scanf("%d", &n_input); // get input
	int buffer[n_input]; // array of input
	
	for (int i=0; i<n_input; i++){
		scanf("%d", &buffer[i]); // get input
	}


	

	omp_set_num_threads(NUM_THREADS); // set number of threads, which is 4
	
	#pragma omp parallel // under pragma omp parallel environment
	{
			
		int id, threads; 
		id = omp_get_thread_num();   // omp_get_thread_num() return the id of threads start with 0 to number of threads which is 4
		threads = omp_get_num_threads(); // omp_get_num_threads() return number of all threads
	
		sum[id] = 0; // initialize a start value for each thread

		for (int i=id; i<n_input; i+=threads){ // this block will be explained in report
			sum[id] += buffer[i];
			
		}

	}

	int summation = 0; // initialize sum value of array sum
	for (int i=0; i<4; i++){ // find summation of array sum
		summation += sum[i];  

	}
	int result = summation/n_input; // find average by summation/n_input
	printf("%d", result); // result

}






