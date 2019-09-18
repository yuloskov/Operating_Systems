#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; 
pthread_cond_t* cond = NULL; 

int threads; 
int cnt = 0; 

void* my_thread(void* arg) 
{ 
	int turn = *(int*)arg; 
	
    pthread_mutex_lock(&mutex); 
 
    if (turn != cnt) { 
        pthread_cond_wait(&cond[turn], &mutex); 
    }

    printf("Hello, I am thread %d \n", turn);

    cnt++; 
       
    pthread_cond_signal(&cond[cnt]); 
    pthread_mutex_unlock(&mutex); 


	return NULL; 
} 

int main() 
{ 
	pthread_t* tid; 
	volatile int i; 
	int* arr; 

	printf("\nEnter number of threads: "); 
	scanf("%d", &threads); 

	cond = (pthread_cond_t*)malloc(sizeof(pthread_cond_t) * threads); 
	tid = (pthread_t*)malloc(sizeof(pthread_t) * threads); 
	arr = (int*)malloc(sizeof(int) * threads); 
 
	for (i = 0; i < threads; i++) { 
		arr[i] = i; 
		pthread_create(&tid[i], NULL, my_thread, (void*)&arr[i]); 
	} 

	for (i = 0; i < threads; i++) { 
		pthread_join(tid[i], NULL); 
	} 

	return 0; 
} 
