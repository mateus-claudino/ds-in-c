#ifndef DLL_H
#define DLL_H
#include <stddef.h>

#define is_null(X) (X == NULL)

typedef struct node{
    struct node* next;
    struct node* prev;
    void* p_data;
} node;

typedef struct {
    node *head;
    unsigned long long data_size;
} dll;

dll* create_list(size_t);
void delete_list(dll*);
void insert_element_at_beginning(dll*, void*);
void insert_element_at_ending(dll*, void*);
void insert_element_before_cursor(dll*, void*, node**);
void insert_element_after_cursor(dll*, void*, node**);
void remove_element_at_beginning(dll*);
void remove_element_at_ending(dll*);
void remove_element_at_cursor(dll*, node**);
void search_element_from_cursor(dll*, void*, node**);
void point_cursor_to(dll*, node***, )

void print_list(dll*, void (*print_element)(void*));


#endif