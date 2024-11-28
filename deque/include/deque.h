#ifndef DEQUE_H
#define DEQUE_H 
#include <stddef.h>

typedef struct node{
    struct node* next;
    void* data;
} node;

typedef struct deque{
    node* first;
    node* last;
    int qnt;
} deque;

deque* create_deque();
void delete_list(deque *);
void enqueue_begin(deque *, void*, size_t);
void enqueue_end(deque *, void*, size_t);
void dequeue_end(deque *);
void dequeue_begin(deque *);
void* peek_begin(deque *);
void* peek_end(deque *);
void print_deque_from_start(deque *, size_t);


#endif 