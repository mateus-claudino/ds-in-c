#ifndef TREE_H
#define TREE_H

typedef struct Node {
	struct Node* left;
	struct Node* right;
	void* data;
} Node;

typedef struct Tree {
	Node* root;
	unsigned long long data_size;
	void (*print)(void*);
	void (*delete_data)(void*);
	int (*compare)(void*, void*);
} Tree;

// creation-related functions
void create_tree(Tree**, unsigned long long);
void delete_tree(Tree*);
Node* create_node(void*, unsigned long long);

// basic operations
void insert(Tree*, void*);
void delete(Tree*, void*);
int search(Tree*, void*, int (*)(void*, void*));
void successor(Tree*, void*);
void predecessor(Tree*, void*);

// traversal
void in_order(Tree*);
void pre_order(Tree*);
void post_order(Tree*);

#endif
