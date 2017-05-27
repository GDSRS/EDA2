#include <iostream>
#include <stdio.h>
#include <cstdlib>
#define SIZE 5
using namespace std;
//tempos podem variar de 1 a 7
//pesos podem variar de 1 a 5
typedef struct client{
	int time;
	int weight;
}Client;

void initializeArrayClients(Client *arrayClients){
	srand(time(NULL));
	for(int i =0; i < SIZE; i++){
		arrayClients[i].time = rand() % 7 + 1;
		arrayClients[i].weight = rand() % 5 + 1;
	}
}

void sortByWeight(Client *arrayClients,int endArray, int startArray){ //quickSort
	if(endArray <= startArray){return;}
	int begin = startArray;
	int end = endArray;
	int pivotIndex = (endArray + startArray)/2;
	int pivot = arrayClients[pivotIndex].weight/arrayClients[pivotIndex].time;

	while(begin <= end){
		while( (arrayClients[begin].weight/arrayClients[begin].time) > pivot){begin++;}
		while( (arrayClients[end].weight/arrayClients[end].time) < pivot){end--;} 
		if(begin <= end){
			Client aux = arrayClients[begin];
			arrayClients[begin] = arrayClients[end];
			arrayClients[end] = aux;
			begin++;
			end--;
		}
	}
	if(end > startArray){sortByWeight(arrayClients,end,startArray);}
	if(begin < endArray){sortByWeight(arrayClients,endArray,begin);}

}

void sigma(Client * arrayClients){
	int c = 0;
	int total = 0;
	for(int i = 0; i < SIZE;i++){
		c += arrayClients[i].time;
		total += arrayClients[i].weight * c;
	}
	cout << total << endl;
}

void printArray(Client *arrayClients){
	printf("Times: in (time,weight)\n");
	for(int i = 0; i < SIZE;i++){
		
		printf("T%d:( %d, %d ) ",i,arrayClients[i].time,arrayClients[i].weight);
	}
	putchar('\n');
}

int main(){
//	int sizeArray = rand() % 10 + 1;
	Client arrayClients[5];
	initializeArrayClients(arrayClients);
	printArray(arrayClients);
	sortByWeight(arrayClients,SIZE-1,0);
	printArray(arrayClients);
	sigma(arrayClients);

}
