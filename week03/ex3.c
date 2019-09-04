#include <stdio.h>
#include <stdlib.h>


struct Node{
    struct Node* next_node;
    int value;
};

void print_list(struct Node* root){
    root = root->next_node;
    while (root !=  NULL)
    {
        printf("%d ", root->value);
        root = root->next_node;
    }
}

void delete_node(struct Node* root, struct Node * del){
    int found = 0;
    while (root->next_node !=  del)
    {
        root = root->next_node;
        found = 1;
    }

    if (found){
        root->next_node = root->next_node->next_node;
    } else {
        printf("There is no such element.");
    }

}

void insert_node(struct Node * ex, struct Node * new_node){
    struct Node * temp = (struct Node*)malloc(sizeof(struct Node));
    new_node->next_node = NULL;
    
    if (ex->next_node != NULL){
        temp = ex->next_node;
        new_node->next_node = temp;   
        ex->next_node = new_node;
    } else {
        ex->next_node = new_node;
    }
}

int main(){
    struct Node * root = NULL;
    struct Node * one = NULL;
    struct Node * two = NULL;
    struct Node * three = NULL;
    struct Node * seven = NULL;


    root = (struct Node*)malloc(sizeof(struct Node));
    one = (struct Node*)malloc(sizeof(struct Node));
    one->value = 1;
    two = (struct Node*)malloc(sizeof(struct Node));
    two->value = 2;
    three = (struct Node*)malloc(sizeof(struct Node));
    three->value = 3;

    seven = (struct Node*)malloc(sizeof(struct Node));
    seven->value = 7;

    insert_node(root, one);
    insert_node(root, two);
    insert_node(root, three);
    insert_node(two, seven);
    delete_node(root, seven);

    print_list(root);

}