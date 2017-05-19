#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
typedef struct NODE{
  int key;
  struct NODE *right;
  struct NODE *left;
}NODE;

NODE *add_node(NODE *root,int new_key){
  if (root == NULL) {
    NODE *new_node = (NODE *) malloc(sizeof(NODE));
    new_node->key = new_key;
    new_node->right = NULL;
    new_node->left = NULL;
    return new_node;
  }
  else if (new_key > root->key) {
    root->right = add_node(root->right,new_key);
  }
  else{
    root->left = add_node(root->left,new_key);
  }

}

NODE *delete_nodes(NODE *root){
  if (root != NULL){
    delete_nodes(root->left);
    delete_nodes(root->right);
    free(root);
  }
  else{
    return NULL;
  }
}

// void repopulate_array(int *array, NODE *root){
//   if (root != NULL){
//     repopulate_array(array,root->left,i--);
//     array[i] = root->key;
//     printf("I :%d\n",i);
//     i--;
//     repopulate_array(array,root->right,i--);
//   }
//   else{
//     return;
//   }
// }
int AddToArray(NODE *node, int *arr, int i)
{
     if(node == NULL)
          return i;


     arr[i] = node->key;
     i++;
     if(node->left != NULL)
          i = AddToArray(node->left, arr, i);
     if(node->right != NULL)
          i = AddToArray(node->right, arr, i);

     return i;
}
void populate_tree(int *array, NODE *root){
  for (int i = 0; i < SIZE; ++i){
    if (root == NULL){
      root = add_node(root,array[i]);
    }
    else{
      add_node(root,array[i]);
    }
  }
}
void print_array(int *array, int tamanho_vetor){
  for (int i = 0; i < tamanho_vetor; ++i)
  {
    printf("%i ",array[i] );
  }
  putchar('\n');
}
void populate_array(int* array, int array_size){
  srand(time(NULL));  
    for (size_t i = 0; i < array_size; i++) {
    int r = rand() % 20; 
      array[i] = r;
    }
}
void print_tree(NODE *root){
  if (root != NULL){
    print_tree(root->left);
    printf("%d ",root->key);
    print_tree(root->right);
  }
  else{
    return;
  }
}
int main(int argc, char const *argv[]) {
  NODE *root = NULL;
  int array[SIZE];
  populate_array(array,SIZE);
  print_array(array,SIZE);

  for (int i = 0; i < SIZE; ++i){
    if (root == NULL){
      root = add_node(root,array[i]);
    }
    else{
      add_node(root,array[i]);
    }
  }

  print_tree(root);
  putchar('\n');
  AddToArray(root,array,0);
  print_array(array,SIZE);
  delete_nodes(root);
  return 0;
}
