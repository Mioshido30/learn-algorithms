#include<stdio.h>

int arr[] = {4,85,7,72,4,2,9,10,22,34};

// function to swap the array
void swap(int a, int b){
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

// Get the real position of the pivot
int pivot_index(int start, int end){
	int pivot = arr[end];
	
	int j = start;
	for(int i = start; i < end; i++){
		if(arr[i] > pivot){
			swap(j,i);
			j++;
		}	
	}
	swap(j,end);
	
	return j;
}

void quickSort(int left,int right){
	
	if(left <= right){
		int pivot = pivot_index(left,right);
		quickSort(left, pivot-1);
		quickSort(pivot+1, right);
	}
}

void display(){
	int len = sizeof(arr)/sizeof(arr[0]);
	for(int i=0; i<len; i++){
		printf("%d ", arr[i]);
	}
}

int main(){
	
	int left = 0;
	int right = (sizeof(arr)/sizeof(arr[0])) - 1; 
	
	quickSort(left,right);
	
	display();
	
	return 0;
}
