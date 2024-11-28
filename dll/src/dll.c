#include "dll.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


dll* create_list(size_t data_size) {
    dll *list = (dll*)malloc(sizeof(*list));
    if(list == NULL) {
        printf("memory error\n");
        return NULL;
    }

    list->head = NULL;
    list->data_size = data_size;
    return list;
}

void delete_list(dll *list) {
    if(list->head == NULL) {
        free(list);
        return;
    }

    node *curr_node = list->head;
    while(1) {
        if(curr_node->next == NULL) {
            free(curr_node->p_data);
            free(curr_node);
            break;
        }
        curr_node = curr_node->next;
        free(curr_node->prev->p_data);
        free(curr_node->prev);
    }

    free(list);
}

void insert_element_at_beginning(dll *list, void *data_addr) {
    if(is_null(list)) {
        printf("List does not exist\n");
        return;
    }

    node *new_node = (node*)malloc(sizeof(*new_node));
    if(is_null(new_node)) {
        printf("out of memory for new node\n");
        return;
    }

    new_node->p_data = malloc(sizeof(list->data_size));
    if(is_null(new_node->p_data)) {
        free(new_node);
        printf("out of memory for data\n");
        return;
    }

    memcpy(new_node->p_data, data_addr, list->data_size);
    new_node->prev = NULL;
    new_node->next = list->head;

    if(is_null(list->head)) {
        list->head = new_node;
        return;    
    }

    
    list->head->prev = new_node;
    list->head = new_node;
}

void print_list(dll *list, void (*print_element)(void*)) {
    if(is_null(list)) {
        printf("list does not exist\n");
        return;
    }

    if(is_null(list->head)) {
        printf("{}\n");
        return;
    }

    printf("{");
    for(node *curr_node = list->head; curr_node != NULL; curr_node = curr_node->next) {
        print_element(curr_node->p_data);
        if(curr_node->next == NULL) break;
        printf(", ");
    }
    printf("}\n");
}


