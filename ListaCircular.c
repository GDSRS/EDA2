#include <stdio.h>
#include <stdlib.h>

typedef struct NO
{
	int value;
	struct NO *next;
}NO;

NO *addNode(NO *root, int value){

	NO *new_Node = (NO*) malloc(sizeof(NO));
	new_Node->value = value;

	if (root == NULL)
	{
		root = new_Node;
		new_Node->next = root;
	} else {
		new_Node->next = root;
		NO *aux = root;
		while(aux->next != root)
			aux = aux->next;
		aux->next = new_Node;
	}
	return root;
}

void printCircularList(NO *root){
	NO *aux = root;
	printf("Root: ");
	if (root != NULL){
		
		if (aux->next == root){
			printf("%d\n",aux->value);
		} else {
			while(aux->next != root){
				printf("%d\n",aux->value);
				aux = aux->next;
			}
			printf("%d\n",aux->value);
		}
	}
}

NO *deleteNode(NO *root){
	if (root != NULL)
	{
		NO *last_node = root;
		while(last_node->next != root)
			last_node = last_node->next;

		if (last_node == root)
		{
			free(root);
			root = NULL;
		}else{
			root = root->next;
			free(last_node->next);
			last_node->next = root;
		}
		return root;
	}else{
		printf("\nEmptyList\n");
	}
}

int main(int argc, char const *argv[]){	
	NO *root = NULL;
	root = addNode(root,6);
	addNode(root,9);
	addNode(root,10);
	addNode(root,11);
	addNode(root,23);
	addNode(root,34);
	printCircularList(root);
	root = deleteNode(root);
	printCircularList(root);
	root = deleteNode(root);
	printCircularList(root);
	root = deleteNode(root);
	printCircularList(root);
	root = deleteNode(root);
	printCircularList(root);
	root = deleteNode(root);
	printCircularList(root);
	root = deleteNode(root);
	printCircularList(root);
	root = deleteNode(root);
	printCircularList(root);
	return 0;
}