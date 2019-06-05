#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>

struct mthr{int a;
	          int b;
	          double result;};

void* MC_Pi(void* param){
	struct mthr* dat = (struct mthr*)param;
	int a = dat-> a;
	int b = dat-> b; // total number of inputs
	int R = 1; // radius of circle (square side = 2)
	double In = 0;

		for(int i=a; i<b; i++){
			unsigned int seed = time(NULL)*i;	// create on seed per thread
			                                  // can be also done with array of seeds
			double INX = (double)rand_r(&(seed))/(double)RAND_MAX;
			double INY = (double)rand_r(&(seed))/(double)RAND_MAX;

			if(INX*INX + INY*INY < R*R){ // input inside circle?
				In++;
			  // printf("%g %g", IN_X, IN_Y);
			  }
			else{
	 			continue;
			  // printf("%g %g", IN_X, IN_Y);
			  }
			}
		dat-> result = In;
	return 0;
	}

	int main(){
    int n = 1e7; // number of inputs for MC_Pi
		int h = n/2;
		struct mthr pA, pB;

		pA.a = 0;
		pA.b = h;
		pthread_t thread;
		pthread_create(&thread, NULL, MC_Pi, (void*)&pA); // Create 1sr thread (A)

		pB.a = h;
		pB.b = n;
		MC_Pi((void*)&pB); // 2nd thread (B) joins when 1st thread ends
		pthread_join(thread, NULL);

		double pi = 4*((double)pA.result + (double)pB.result)/n;
		printf("Total number of inputs used: %d \n", n);
		printf("Total number of inputs inside the circle: %f \n", (double)pA.result + (double)pB.result);
		printf("Pi with pthread is: %g \n", pi);


		return 0;
	}
