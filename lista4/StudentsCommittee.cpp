#include <iostream>
#include <stdio.h>
#include <cstdlib>
#define SIZE 5

using namespace std;
typedef struct student{
	int startTime;
	int endTime;
}Schedule;

void initialize(Schedule *students){
	srand(time(NULL));
	for(int i = 0; i < SIZE;i++){

		students[i].startTime = rand() % 12 + 1;
		int endTimeNumber = rand() % 12 + 1;
		while(endTimeNumber <= students[i].startTime){
			endTimeNumber = rand() % 12 + 1;
		}
		students[i].endTime = endTimeNumber;
	}
}

int printStudents(Schedule *students){
	printf("Student (StartTime,EndTime)");

	for(int i = 0; i < SIZE; i++){

		printf("Student %d ( %d , %d )",i,students[i].startTime,students[i].endTime);
	}
	putchar('\n');
}

void sortByEndTime(Schedule *students,int startArray, int endArray){//quicksort
	if(endArray <= startArray){return;}
	int begin = startArray;
	int end = endArray;
	int pivot = students[(begin + end)/2].endTime;

	while(begin <= end){
		while(students[begin].endTime < pivot){begin++;}
		while(students[end].endTime > pivot){end--;}
		if(begin <= end){
			Schedule aux = students[begin];
			students[begin] = students[end];
			students[end] = aux;
			end--;
			begin++;	
		}
	}
	if(end > startArray){sortByEndTime(students,startArray,end);}
	if(begin < endArray){sortByEndTime(students,begin,endArray);}

}

void checkShifts(Schedule *students){
	int indexLastJob = 0;
	for(int i = 1; i < SIZE; i++){
		if(students[i].startTime >= students[indexLastJob].endTime){
			indexLastJob = i;
		}
		else{
			printf("Student%d (%d,%d)\n",i,students[i].startTime,students[i].endTime);
		}
	}
}

int main(){
	Schedule students[SIZE];
	initialize(students);

	printStudents(students);
	sortByEndTime(students,0,SIZE-1);
	printStudents(students);
	printf("Participarão: \n");
	checkShifts(students);

}
