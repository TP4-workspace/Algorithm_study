#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _tree {
	int num;
	struct _tree* left;
	struct _tree* right;
} tree;

tree* makeTree(int target, int buf_num, int* pre_buf, int* inorder_buf);
void printTree(tree* t);
void freeTree(tree* t);

int main(void) {
	// read the data
	int* pre_buf;
	int* inorder_buf;
	
	int test_num;
	int node_num;
	
	scanf("%d", &test_num);

	for (int i = 0; i < test_num; ++i) {
		scanf("%d", &node_num);
		pre_buf = (int*)malloc(sizeof(int)*node_num);
		inorder_buf = (int*)malloc(sizeof(int)*node_num);
		
		for (int j = 0; j < node_num; ++j) {
			scanf("%d", &(pre_buf[j]));
		}
		
		for (int j = 0; j < node_num; ++j) {
			scanf("%d", &(inorder_buf[j]));
		}
		
		tree* root = makeTree(pre_buf[0], node_num, pre_buf, inorder_buf);
	
		// print out
		printTree(root);
		freeTree(root);
		printf("\n");
		
		free(pre_buf);
		free(inorder_buf);
	}
	
	return 0;
}


tree* makeTree(int target, int buf_num, int* pre_buf, int* inorder_buf) {
	int pivot = 0;
	tree* node = (tree*)malloc(sizeof(tree));
	node->left = NULL;
	node->right = NULL;
	node->num = target;
	
	for (int i = 0; i < buf_num; ++i) {
		if (inorder_buf[i] == target) {
			pivot = i;
			break;
		}
	}
	
	if (pivot > 0) 
		node->left = makeTree(pre_buf[1], pivot, &(pre_buf[1]), inorder_buf);
	if (pivot < buf_num -1 ) 
		node->right = makeTree(pre_buf[pivot+1], buf_num-(pivot+1), &(pre_buf[pivot+1]), &(inorder_buf[pivot+1]));
	
	return node;
}

void printTree(tree* t) {
	if (t->left != NULL)	
		printTree(t->left);
	if (t->right != NULL)
		printTree(t->right);
	printf("%d ", t->num);
}

void freeTree(tree* t) {
	if (t->left != NULL)
		freeTree(t->left);
	if (t->right != NULL)
		freeTree(t->right);
	free(t);
}
