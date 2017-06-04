#include <iostream>
#include <stdio.h>
#define SIZE 5
#include <cstdlib>

using namespace std;

void initializeNumbers(int *numbers){
	srand(time(NULL));
	for(int i = 0; i < SIZE; i++){
		numbers[i] = rand() % 10 +1;
	}
}
int merge(int *numbers,int startA,int endB){
	if(startA == endB){return 0;}
	int middle = (startA+endB)/2;
	int inversionsCount = 0;
	int *subArray = (int*) malloc(sizeof(int)*((endB - startA)+1) );
	int beginA = startA;
	int beginB = middle+1;
	int subArrayIndex = 0;

	while(beginA <= middle && beginB <= endB){
		if(numbers[beginA] > 2* numbers[beginB]){
			subArray[subArrayIndex] = numbers[beginB];
			inversionsCount += middle - beginA +1; 
			cout << "Invertion for "<< numbers[beginB] << " to "<< numbers[beginA] << endl;
			subArrayIndex++;
			beginB++;

		}
		else{
			subArray[subArrayIndex] = numbers[beginA];
			subArrayIndex++;
			cout << "No invertions" << endl;
			beginA++;
		}
	}


	// copy the rest of the right numbers
	if(beginB <= endB){
		while(beginB <= endB){
			subArray[subArrayIndex] = numbers[beginB];
			beginB++;
			subArrayIndex++;
		}
	}

	// copy the rest of the left numbers
	if(beginA <= middle){
		while(beginA <= middle){
			subArray[subArrayIndex] = numbers[beginA];
			beginA++;
			subArrayIndex++;
		}
	}
	
	// copy elements from sorted array to original array
	for(int i = startA; i <= endB;i++){
		numbers[i] = subArray[i - startA];
	}

	return inversionsCount;
	
}

int countInversions(int *numbers,int startArray, int endArray){
	int a = 0,b = 0,c =0;
	if(startArray >= endArray){return 0;}
		int middle = (startArray + endArray)/2;
	
		a = countInversions(numbers,startArray, middle);// part A
		b = countInversions(numbers,middle+1,endArray);// part B
		c = merge(numbers,startArray,endArray);
	return (a+b+c);
	
}
	
int printArray(int * numbers){
	for(int i = 0; i < SIZE;i++){
		cout <<"Number"<< i << " " << numbers[i] << endl;
	}
	putchar('\n');
}

int main(){
	int numbers[SIZE];
	initializeNumbers(numbers);
	printArray(numbers);
	cout <<"Inversions: " <<  countInversions(numbers,0,SIZE-1) <<endl;
	printArray(numbers);

	return 0;
}
