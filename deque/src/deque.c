#include "deque.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

deque* create_deque() {
    deque *dq = (deque*)malloc(sizeof(deque));
    if(dq == NULL) {
        exit(1);
    }

    dq->first = NULL;
    dq->last = NULL;
    dq->qnt = 0;

    return dq;
}

void delete_list(deque *dq) {
    if(dq == NULL) {
        printf("already deleted\n");
        return;
    }

    for(node *p = dq->first; p != NULL;) {
        node *deleted = p;
        p = p->next;
        free(deleted->data);
        free(deleted);
    }

    free(dq);
}

void enqueue_begin(deque *dq, void *data_addr, size_t data_size) {
    if(dq == NULL) {
        printf("deque does not exist\n");
        return;
    }
    node *new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL) {
        printf("out of memory\n");
        return;
    }
    new_node->data = malloc(data_size);
    if(new_node->data == NULL) {
        printf("out of memory for data\n");
        free(new_node);
        return;
    }
    memcpy(new_node->data, data_addr, data_size);
    if(dq->first == NULL) {
        new_node->next = dq->first;
        dq->first = new_node;
        dq->last = new_node;
        dq->qnt++;
    } else {
        new_node->next = dq->first;
        dq->first = new_node;
        dq->qnt++;
    }

}

void enqueue_end(deque *dq, void *data_addr, size_t data_size) {
    if(dq == NULL) {
        printf("deque does not exist\nrun create_deque first\n");
        return;
    }
    node *new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL) {
        printf("out of memory\n");
        return;
    }
    new_node->data = malloc(data_size);
    if(new_node->data == NULL) {
        free(new_node);
        printf("out of memory\n");
        return;
    }
    memcpy(new_node->data, data_addr, data_size);

    if(dq->last == NULL) {
        new_node->next = dq->last;
        dq->last = new_node;
        dq->first = new_node;
        dq->qnt++;
    } else {
        dq->last->next = new_node;
        dq->last = new_node;
        new_node->next = NULL;
        dq->qnt++;
    }
}

void dequeue_end(deque *dq) {
    node *to_be_deleted = dq->last;
    node *p;
    for(p = dq->first; p->next != to_be_deleted; p = p->next) {
        // do nothing
    }
    p->next = NULL;
    dq->last = p;
    free(to_be_deleted->data);
    free(to_be_deleted);
}

void dequeue_begin(deque *dq) {
    node *to_be_deleted = dq->first;
    dq->first = to_be_deleted->next;
    free(to_be_deleted->data);
    free(to_be_deleted);
}

void* peek_begin(deque *dq) {
    if(dq->first == NULL) {
        printf("deque is empty\n");
        return NULL;
    }

    return dq->first->data;
}

void* peek_end(deque *dq) {
    if(dq->last == NULL) {
        printf("deque is empty\n");
        return NULL;
    }

    return dq->last->data;
}

void print_deque_from_start(deque *dq, size_t data_size) {
    for(node *p = dq->first; p != NULL; p = p->next) {
        const unsigned char *data_bytes = p->data;
        for(size_t i = 0; i < data_size; i++) {
            printf("%02x ", (data_bytes)[i]);
        }
        if(p->next != NULL) printf("| ");
    }
    printf("\n");
}