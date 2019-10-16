#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_PAGES_TO_READ 1000
#define VIRTUAL_MEMORY_SIZE 100
#define BITS_FOR_COUNTER 8

struct Page{
    unsigned int page_number;
    unsigned int counter;
    unsigned int R;
};

struct Page * virtual_memory[VIRTUAL_MEMORY_SIZE];
int hit = 0;
int miss = 0;

int pages_in_buffer = 0;
int proceed_with_aging = 0;

void add_page(struct Page * new_page){
    int hit_happened = 0;
    new_page->R = 1;
    new_page->counter = 0;
    int smallest_counter = 1 << 31;
    int page_number_with_smallest_counter = 0;

    for (int i = 0; i < pages_in_buffer; i++){
        if (virtual_memory[i] != NULL){
            if (virtual_memory[i]->page_number == new_page->page_number){
                //hit
                hit_happened = 1;
            } else {
                //miss
                virtual_memory[i]->R = 0;
            }

            virtual_memory[i]->counter = (virtual_memory[i]->counter >> 1) | (virtual_memory[i]->R << BITS_FOR_COUNTER-1);

            if (virtual_memory[i]->counter < smallest_counter){
                smallest_counter = virtual_memory[i]->counter;
                page_number_with_smallest_counter = i;
            }
        }
    }
    if (pages_in_buffer <= VIRTUAL_MEMORY_SIZE && proceed_with_aging == 0) {
        virtual_memory[pages_in_buffer-1] = new_page;
        virtual_memory[pages_in_buffer-1]->counter = (virtual_memory[pages_in_buffer-1]->counter >> 1) |
                                                                     (virtual_memory[pages_in_buffer-1]->R << BITS_FOR_COUNTER-1);
        miss++;
        if (pages_in_buffer == VIRTUAL_MEMORY_SIZE)
            proceed_with_aging = 1;
    } else if (hit_happened){
        hit++;
    } else {
        miss++;
        virtual_memory[page_number_with_smallest_counter] = new_page;
        virtual_memory[page_number_with_smallest_counter]->counter = (virtual_memory[page_number_with_smallest_counter]->counter >> 1) |
                (virtual_memory[page_number_with_smallest_counter]->R << BITS_FOR_COUNTER-1);
    }
}

int main(){
    FILE *fp;
    fp = fopen("input.txt", "r");

    for (int i = 0; i < NUMBER_OF_PAGES_TO_READ; i++){
        struct Page *new_page = malloc(sizeof(struct Page));
        fscanf(fp, "%d", &(new_page->page_number));

        pages_in_buffer = (pages_in_buffer < VIRTUAL_MEMORY_SIZE) ? pages_in_buffer+1 : pages_in_buffer;

        add_page(new_page);

    }
    double ratio = (double) hit/ (double) miss;
    printf("Hit/miss ratio = %f, hits = %d, misses = %d\n", ratio, hit, miss);

    return 0;
}
/* The numbers I got are:
10 frames: Hit/miss ratio = 0.009082, hits = 9, misses = 991
50 frames: Hit/miss ratio = 0.053741, hits = 51, misses = 949
100 frames: Hit/miss ratio = 0.094092, hits = 86, misses = 914
*/