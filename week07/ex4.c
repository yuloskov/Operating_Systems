#include <stdlib.h>
#include <stdio.h>

size_t getsize(void * p) {
    size_t * in = p;
    if (in) { --in; return *in; }
    return -1;
}

void * my_realloc(void *ptr, size_t size){
    if (size == 0){
        free(ptr);
        return NULL;
    }
    if (ptr == NULL){
        return malloc(size);
    }
    if (ptr != NULL && size != 0){
        size_t ptr_size = getsize(ptr);
        void * newptr;
        if (size <= ptr_size){
            return ptr;
        }
        newptr = malloc(size);
        memcpy(newptr, ptr, ptr_size);
        free(ptr);
        return newptr;
    }
}

int main(){
	//Allows you to generate random number
	srand(time(NULL));

	// Allows user to specify the original array size, stored in variable n1.
	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	//Create a new array of n1 ints
	int* a1 = malloc(n1*sizeof(int));
	int i;
	for(i=0; i<n1; i++){
		//Set each value in a1 to 100
		a1[i]=100;
		
		//Print each element out (to make sure things look right)
		printf("%d ",a1[i] );
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	//Dynamically change the array to size n2
	a1 = my_realloc(a1, n2*sizeof(int));

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

	if (n2 > n1){
        for (int i = n1; i < n2; i++){
            a1[i] = 0;
        }
    }
	

	for(i=0; i<n2;i++){
		//Print each element out (to make sure things look right)
		printf("%d ",a1[i]);
	}
	printf("\n");
	
	//Done with array now, done with program :D
	
	return 0;
}
