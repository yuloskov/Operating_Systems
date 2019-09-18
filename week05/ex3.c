#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  

int capuccino[10];
int last_cappuccino = 5;
long long int counter = 0;
int threads; 
int cnt = 0;

int sleep_1 = 0;
int sleep_2 = 0;

void * produce(){
    while (1)
    {
        if (last_cappuccino < 10){
            capuccino[last_cappuccino] = 1;

            if (counter == 100){
                printf("%d\n", last_cappuccino);
                counter = 0;
            } else {
                counter++;
            }
            //printf("%d\n", counter);

            last_cappuccino++;
            if (last_cappuccino > 0){
                sleep_2 = 0;
            }

        } else {
            sleep_1 = 1;
            while (sleep_1)
            {
                ;
            }
            
        }
    }
}

void * consume(){
    while (1){
        if (last_cappuccino > 0){
            capuccino[last_cappuccino] = 0;
            //printf("%d\n", last_cappuccino);
            last_cappuccino--;
            if (last_cappuccino < 10){
                sleep_1 = 0;
            }
        } else {
            sleep_2 = 1;
            while (sleep_2)
            {
                ;
            }
            
        }
    }
}

int main() 
{ 
	pthread_t* tid; 
	volatile int i = 0; 
	threads = 2; 
	tid = (pthread_t*)malloc(sizeof(pthread_t) * threads); 


	pthread_create(&tid[i], NULL, consume, NULL); 
    i++;
	pthread_create(&tid[i], NULL, produce, NULL); 

	

	for (i = 0; i < threads; i++) { 
		pthread_join(tid[i], NULL); 
	} 

	return 0; 
} 
