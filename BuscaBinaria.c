#include <stdio.h>
#include <time.h>
// #include <windows.h>
#define SIZE 10000

void populate_array(int* array, int array_size){
  for (size_t i = 0; i < array_size; i++) {
    array[i] = i  * 4;
  }
}
int binary_search(int *array, int max, int min, int key){
	// if (max < min)
	// {
	// 	return -1;
	// }

    int middle =  0 ;
    // middle = (max + min)/2;
    double division = (double )(key - array[min])/(array[max] - array[min]);
    middle = min + ( (max - min) * division);
    if (middle == (min - 1) ) 
    {
      return -1;
    }
    if (array[middle] == key) {
      return middle;
    }
    else if (array[middle] > key){
      printf("Max: %i Min: %i Middle: %i\n",max,min,middle );
      return binary_search(array,middle-1,min,key);
    } else {
    	printf("Max: %i Min: %i Middle: %i\n",max,min,middle ); 
      return binary_search(array,max,middle+1,key);
    }
}

void print_array(int *array, int tamanho_vetor){
	for (int i = 0; i < tamanho_vetor; ++i)
	{
		printf("%i ",array[i] );
	}
	putchar('\n');
}

int main(int argc, char const *argv[]) {
  int searched_array[SIZE];
  populate_array(searched_array,SIZE);
  print_array(searched_array,SIZE);
  printf("Insert a key to look for\n" );
  int key = -1;
  scanf("%i",&key );
  clock_t begin = clock();
  printf("%i\n",binary_search(searched_array,SIZE -1,0,key) );
  clock_t end = clock();
  double time_passed = ((double) (end - begin))/CLOCKS_PER_SEC;
  printf("Time for %d elements :%lf\n",SIZE,time_passed );
  return 0;
}
