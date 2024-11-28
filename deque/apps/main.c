#include "deque.h"
#include <stdio.h>

int main(int argc, char **argv) {
    //creating a deque and printing its contents
    deque *deque_start = create_deque();
    for(char i = 'a'; i < 'f'; i++) {
        enqueue_begin(deque_start, &i, sizeof(i));
    }
    printf("first = %c\n", *(char *)peek_begin(deque_start));
    printf("last = %c\n", *(char *)peek_end(deque_start));
    dequeue_begin(deque_start);
    printf("first = %c\n", *(char *)peek_begin(deque_start));
    printf("last = %c\n", *(char *)peek_end(deque_start));
    delete_list(deque_start);
    return 0;
}