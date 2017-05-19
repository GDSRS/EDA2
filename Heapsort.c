#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 10
void print_array(int *array, int tamanho_vetor){
	for (int i = 0; i < tamanho_vetor; ++i)
	{
		printf("%i ",array[i] );
	}
	putchar('\n');
}
void easy_swap(int *array,int a,int b){
	int aux = array[a];
	array[a] = array[b];
	array[b] = aux;
}

void heapfy(int *array,int first_father,int last_element){ //last_element its only needed to low the heap size
	int left_son = first_father*2 + 1;
	int right_son = first_father*2 + 2; //Find values between [0...SIZE]
	int bigger = first_father;
	if (right_son < last_element && array[right_son] > array[bigger]){
		bigger = right_son;	
	}
	if (left_son < last_element && array[left_son] > array[bigger]){
		bigger = left_son;
	}

	if (bigger != first_father){
		easy_swap(array,bigger,first_father);

		heapfy(array,bigger,last_element);
	}
}

void heapsort(int *array,int last_element){
	for (int i = (last_element /2) - 1; i >= 0; i--){
		heapfy(array,i,last_element);
	}

	for (int i = last_element - 1; i >= 0; i--){
		easy_swap(array,0,i);
		heapfy(array,0,i);// diminuindo o tamanho do vetor
	}
}
void populate_array(int* array, int array_size){
	srand(time(NULL));  
  	for (size_t i = 0; i < array_size; i++) {
		int r = rand() % 20; 
    	array[i] = r;
  	}
}
int main(int argc, char const *argv[]){
	int array[SIZE];
	populate_array(array,SIZE);
	print_array(array,SIZE);
	heapsort(array,SIZE);
	print_array(array,SIZE);
	return 0;
}