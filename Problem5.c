#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>

#define M 400
#define N 400
#define P 400

int A[M][N], B[N][P], C[M][P];

void* computation(void* row_num) {

	int row = *(int*)row_num;

    	free(row_num);  // clean the storage 

    	for (int j = 0; j < P; j++) {
        	C[row][j] = 0;
        	for (int k = 0; k < N; k++) {
            	C[row][j] += A[row][k] * B[k][j];
        	}
    	}
    return NULL;
}

void parallel_computing(){
	pthread_t threads[M];
	for (int i = 0; i < M; i++) {

        int* arg = malloc(sizeof(int));  // make storage for each thread

        *arg = i;                        // store in each thread
        pthread_create(&threads[i], NULL, computation, arg);
    	}

	for(int i = 0; i < M; i++){
		pthread_join(threads[i], NULL);
	}

}
void sequential_computing(){
	for (int i = 0; i < M; i++) {
        	for (int j = 0; j < P; j++) {
            		C[i][j] = 0;
            		for (int k = 0; k < N; k++) {
                		C[i][j] += A[i][k] * B[k][j];
            		}
        	}
	}
}

int main() {

    	for (int i = 0; i < M; i++) {
        	for (int j = 0; j < N; j++) {
            	A[i][j] = rand() % 10;
        	}
    	}
    	for (int i = 0; i < N; i++) {
        	for (int j = 0; j < P; j++) {
            	B[i][j] = rand() % 10;
        	}
    	}


	struct timeval start1, end1, start2, end2;
    
   	gettimeofday(&start1, NULL);  // start
    	sequential_computing();
    	gettimeofday(&end1, NULL);    // end

    	long seconds1 = end1.tv_sec - start1.tv_sec;
    	long microseconds1 = end1.tv_usec - start1.tv_usec;
    	double elapsed1 = seconds1 + microseconds1 * 1e-6;  // turn into seconds

    	printf("Execution time(sequential): %.6f seconds\n", elapsed1);

	gettimeofday(&start2, NULL);
	parallel_computing();
	gettimeofday(&end2, NULL);

	long seconds2 = end2.tv_sec - start2.tv_sec;
	long microseconds2 = end2.tv_usec - start2.tv_usec;
	double elapsed2 = seconds2 + microseconds2 * 1e-6;

	printf("Execution time(parallel): %.6f seconds\n", elapsed2);


	return 0;
}
