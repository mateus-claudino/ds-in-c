#include "dll.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_int(void *p_int) {
    printf("%d", *(int*)p_int);
}

void print_char(void *p_char) {
    printf("%c", *(char*)p_char);
}

void print_string(void *p_string) {
    printf("%s", *(char**)p_string);
}

int main() {
    dll *integer_list = create_list(sizeof(int));
    dll *char_list = create_list(sizeof(char));
    dll *string_list = create_list(sizeof(char *));

    for(int i = 1; i <= 5; i++) insert_element_at_beginning(integer_list, &i);
    for(char a = 'a'; a <= 'k'; a++) insert_element_at_beginning(char_list, &a);
    char* strings[] = {"finalmente", "funcionou", "este caralho"};
    for(int i = 0; i < 3; i++) insert_element_at_beginning(string_list, &strings[i]);

    print_list(integer_list, print_int);
    print_list(char_list, print_char);
    print_list(string_list, print_string);

    delete_list(integer_list);
    delete_list(char_list);
    delete_list(string_list);
    return 0;
}