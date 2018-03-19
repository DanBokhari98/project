/*
 * InsertionSort.cpp
 *
 *  Created on: Jan 15, 2018
 *      Author: Sapphire
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
using namespace std;

int randArray(int x[]){
	for(int i = 0; i < 100; i++){
		x[i] = rand() % 100 + 1;
	}
	return x[100];
}

void sort(int arr[], int n){
	int key, i;
		for(int j = 2; j < n; j++){
			key = arr[j];
			i = j - 1;
			while(i >= 0 && arr[i] > key){
				arr[i + 1] = arr[i];
				i = i - 1;
			}
		arr[i + 1] = key;
	}
}

void printArray(int arr[], int n){
	cout << "\nHere are the sorted random numbers! \n";
	for(int i = 0; i < 100; i++){
		cout << arr[i] << " ";
	}
}

int main(){
	srand(time(0));
	int arr[100];
	randArray(arr);
	int size = *(&arr + 1) - arr;
	cout << "\tINSERTION SORT\n******************************\n";
	cout << "Here are the elements of the random array! \n";
	for(int i = 0; i < 100; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	sort(arr, size);
	printArray(arr, size);
	return 0;
}



