#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void create_tree(Tree** p_tree, unsigned long long data_size) {
	(*p_tree) = (Tree*)malloc(sizeof(**p_tree));
	if( *p_tree == NULL) {
		printf("cannot alloc tree\n");
	}
	(*p_tree)->data_size = data_size;
	(*p_tree)->root = NULL;
}

static void node_delete(Node* node, void(*destroy_node)(void*)) {
	if(node == NULL) return;

	Node* left_child = node->left;
	Node* right_child = node->right;
	
	if(left_child != NULL) {
		node_delete(left_child, destroy_node);
	}
	if(right_child != NULL) {
		node_delete(right_child, destroy_node);
	}

	destroy_node(node->data);
	free(node);
	
}

void delete_tree(Tree* tree) {
	if(tree == NULL || tree->root == NULL || tree->delete_data == NULL) return;

	node_delete(tree->root, tree->delete_data);
	free(tree);

}

Node* create_node(void* p_data, unsigned long long data_size) {
	Node* new_node = (Node*)malloc(sizeof(*new_node));
	if(new_node == NULL) {
		printf("cannot alloc new node\n");
		return NULL;
	}
	new_node->data = malloc(sizeof(data_size));
	if(new_node->data == NULL) {
		printf("cannot alloc new node data\n");
		free(new_node);
		return NULL;
	}
	memcpy(new_node->data, p_data, data_size);
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

void insert(Tree* tree, void* p_data) {
	if(tree == NULL) {
		printf("tree does not exist\n");
		return;
	}
	if(tree->compare == NULL) {
		printf("provide a compare function to insert a new node\n");
		return;
	}

	Node* new_node = create_node(p_data, tree->data_size);
	if(new_node == NULL) {
		printf("cannot allocate new node\n");
		return;
	}

	if(tree->root == NULL) {
		tree->root = new_node;
		return;
	}

	for(Node* curr = tree->root; curr != NULL; ) {
		if(tree->compare(new_node->data, curr->data)) {
			if(curr->left == NULL) {
				curr->left = new_node;
				break;
			} else {
				curr = curr->left;
			}
		} else {
			if(curr->right == NULL) {
				curr->right = new_node;
				break;
			} else {
				curr = curr->right;
			}
		}
	}
}

int search(Tree* tree, void* data, int (*pointer_comp)(void*, void*)) {
	if(tree == NULL || tree->compare == NULL || tree->root == NULL){
		return 0;
	}

	for(Node* curr = tree->root; curr != NULL;) {
		if(pointer_comp(data, curr->data)) {
			return 1;
		}

		if(tree->compare(data, curr->data)) {
			if(curr->left == NULL) return 0;
			curr = curr->left;
		}
		else {
			if(curr->right == NULL) return 0;
			curr = curr->right;
		}
	}

	return 0;
}

static void node_pre_order(Node* node, void (*print)(void*)) {
	if(node == NULL) return;

	Node* left_child = node->left;
	Node* right_child = node->right;

	print(node->data);
	printf("\n");
		
	if(left_child != NULL) {
		node_pre_order(left_child, print);
	}
	if(right_child != NULL) {
		node_pre_order(right_child, print);
	}

}

static void node_in_order(Node* node, void (*print)(void*)) {
	if(node == NULL) return;

	Node* left_child = node->left;
	Node* right_child = node->right;
		
	if(left_child != NULL) {
		node_in_order(left_child, print);
	}

	print(node->data);
	printf("\n");

	if(right_child != NULL) {
		node_in_order(right_child, print);
	}

	
}

static void node_post_order(Node* node, void (*print)(void*)) {
	if(node == NULL) return;

	Node* left_child = node->left;
	Node* right_child = node->right;
	
	if(left_child != NULL) {
		node_post_order(left_child, print);
	}
	if(right_child != NULL) {
		node_post_order(right_child, print);
	}

	print(node->data);
	printf("\n");
}

void pre_order(Tree* tree) {
	if(tree == NULL) {
		printf("tree does not exist\n");
		return;
	}
	if(tree->print == NULL) {
		printf("provide a print function for the tree\n");
		return;
	}

	node_pre_order(tree->root, tree->print);
}

void in_order(Tree* tree) {
	if(tree == NULL) {
		printf("tree does not exist\n");
		return;
	}
	if(tree->print == NULL) {
		printf("provide a print function for the tree\n");
		return;
	}

	node_in_order(tree->root, tree->print);
}

void post_order(Tree* tree) {
	if(tree == NULL) {
		printf("tree does not exist\n");
		return;
	}
	if(tree->print == NULL) {
		printf("provide a print function for the tree\n");
		return;
	}

	node_post_order(tree->root, tree->print);
}
