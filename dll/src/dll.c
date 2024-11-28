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
    list->tail = NULL;
    list->data_size = data_size;
    list->list_size = 0;
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

node* insert_element_at_beginning(dll *list, void *data_addr) {
    if(is_null(list)) {
        printf("List does not exist\n");
        return NULL;
    }

    node *new_node = (node*)malloc(sizeof(*new_node));
    if(is_null(new_node)) {
        printf("out of memory for new node\n");
        return NULL;
    }

    new_node->p_data = malloc(sizeof(list->data_size));
    if(is_null(new_node->p_data)) {
        free(new_node);
        printf("out of memory for data\n");
        return NULL;
    }

    memcpy(new_node->p_data, data_addr, list->data_size);
    new_node->prev = NULL;
    new_node->next = list->head;
    list->list_size++;

    if(is_null(list->head)) {
        list->head = new_node;
        list->tail = new_node;
        return new_node;    
    }

    
    list->head->prev = new_node;
    list->head = new_node;

    return new_node;
}

node* insert_element_at_ending(dll* list, void* data_addr) {
    if(is_null(list)) {
        printf("List does not exist\n");
        return NULL;
    }

    node *new_node = (node*)malloc(sizeof(*new_node));
    if(is_null(new_node)) {
        printf("out of memory for new node\n");
        return NULL;
    }

    new_node->p_data = malloc(sizeof(list->data_size));
    if(is_null(new_node->p_data)) {
        free(new_node);
        printf("out of memory for data\n");
        return NULL;
    }

    memcpy(new_node->p_data, data_addr, list->data_size);
    new_node->next = NULL;
    new_node->prev = list->tail;
    list->list_size++;

    if(is_null(list->tail)) {
        list->tail = new_node;
        list->head = new_node;
        return new_node;
    }

    list->tail->next = new_node;
    list->tail = new_node;

    return new_node;
    
}

node* insert_element_at_position(dll* list, void* data_addr, int pos) {
    if(is_null(list)) {
        printf("list does not exist\n");
        return NULL;
    }

    if(pos >= list->list_size) {
        node* inserted_addr = insert_element_at_ending(list, data_addr);
        return inserted_addr;
    }
    if(pos == 0) {
        node* inserted_addr_2 = insert_element_at_beginning(list, data_addr);
        return inserted_addr_2;
    }

    int i = 0;
    for(node* p_node = list->head; p_node != NULL; p_node = p_node->next) {
        if(i == pos) {
            node* new_node = (node*)malloc(sizeof(*new_node));
            if(is_null(new_node)) {
                printf("cant create new node\n");
                return NULL;
            }
            new_node->p_data = malloc(sizeof(list->data_size));
            if(is_null(new_node->p_data)) {
                free(new_node);
                return NULL;
            }
            memcpy(new_node->p_data, data_addr, list->data_size);
            new_node->prev = p_node->prev;
            new_node->next = p_node;
            p_node->prev->next = new_node;
            p_node->prev = new_node;
            return new_node;
            
        } else {
            i++;
        }
    }

    return NULL;
}

void remove_element_at_beginning(dll* list) {
    IF_NULL(list)
    IF_NULL(list->head)

    node* to_remove = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;

    free(to_remove);
    list->list_size--;
}
void remove_element_at_ending(dll* list) {
    IF_NULL(list)
    IF_NULL(list->tail)

    node* to_remove = list->tail;
    list->tail = list->tail->prev;
    list->tail->next = NULL;

    free(to_remove);
    list->list_size--;
}

void remove_element_at_position(dll* list, int pos) {
    IF_NULL(list)
    IF_NULL(list->head)
    if(list->list_size < pos) {
        printf("invalid position\n");
        return;
    }

    if(pos == 0) {
        remove_element_at_beginning(list);
        return;
    }
    else if(pos == list->list_size - 1) {
        remove_element_at_ending(list);
        return;
    }

    node *to_be_deleted = list->head;
    for(int i = 0; i < pos; i++) {
        to_be_deleted = to_be_deleted->next;
    }

    to_be_deleted->prev->next = to_be_deleted->next;
    to_be_deleted->next->prev = to_be_deleted->prev;

    free(to_be_deleted);
    list->list_size--;

}
node* search_element_from_position(dll* list, void* data_addr, int pos, int (*compare_element)(void*, void*)) {
    if(is_null(list)) {
        printf("list does not exist\n");
        return NULL;
    }

    if(is_null(list->head)) {
        return NULL;
    }

    if(pos > list->list_size) {
        printf("invalid position\n");
        return NULL;
    }

    node *starting_node = list->head;

    for(int i = 0; i < pos; i++) {
        starting_node = starting_node->next;
    }

    for(; starting_node != NULL; starting_node = starting_node->next) {
        if(compare_element(data_addr, starting_node->p_data)) { // it is a match
            return starting_node;
        }
    }

    return NULL;
}

void print_list(dll *list, void (*print_element)(void*)) {
    if(is_null(list)) {
        printf("list does not exist\n");
        return;
    }

    if(is_null(list->head)) {
        printf("\n");
        return;
    }

    //printf("{");
    for(node *curr_node = list->head; curr_node != NULL; curr_node = curr_node->next) {
        print_element(curr_node->p_data);
        if(curr_node->next == NULL) break;
        printf(" ");
    }
    printf("\n");
}



