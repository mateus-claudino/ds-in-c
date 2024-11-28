#ifndef DLL_H
#define DLL_H
#include <stddef.h>

#define IF_NULL(X) if(X == NULL) { printf("NULL pointer\n"); return; }
#define is_null(X) X == NULL

typedef struct node{
    struct node* next;
    struct node* prev;
    void* p_data;
} node;

typedef struct {
    node *head;
    node *tail;
    unsigned long long data_size;
    int list_size;
} dll;

dll* create_list(size_t);
void delete_list(dll*);
node* insert_element_at_beginning(dll*, void*);
node* insert_element_at_ending(dll*, void*);
node* insert_element_at_position(dll*, void*, int);
void remove_element_at_beginning(dll*);
void remove_element_at_ending(dll*);
void remove_element_at_position(dll*, int);
node* search_element_from_position(dll*, void*, int, int (*)(void*, void*));

void print_list(dll*, void (*)(void*));


#endif
