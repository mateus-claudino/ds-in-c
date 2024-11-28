#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

void delete_int(void* ptr) {
	free(ptr);
}

void print_int(void* ptr) {
	printf("%d", *(int*)ptr);
}

int compare_int(void* int_a, void* int_b) {
	return (*(int*)int_a < *(int*)int_b);
}

int int_equal(void* x, void* y) {
	return (*(int*)x == *(int*)y);
}

int main() {
	Tree* tree = NULL;
	create_tree(&tree, sizeof(int));
	tree->print = print_int;
	tree->compare = compare_int;
	tree->delete_data = delete_int;

	int v[] = {6, 23, 1, 8, 3, 0, 9, 21};

	for(int i = 0; i < (int)(sizeof(v)/sizeof(v[0])); i++) {
		insert(tree, &v[i]);
	}	

	delete_tree(tree);

	return 0;
}
