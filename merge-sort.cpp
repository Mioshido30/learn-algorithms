#include<stdio.h>

int arr[] = {4,85,7,72,4,2,9,10,22,34};

void merge(int left, int mid, int right){
	
	int LEFT_SIZE = mid - left + 1;
	int RIGHT_SIZE = right - mid;
	
	int left_arr[LEFT_SIZE + 1];
	int right_arr[RIGHT_SIZE + 1];
	
	for(int i = 0; i < LEFT_SIZE; i++){
		left_arr[i] = arr[left + i];
	}
	
	for(int i=0; i < RIGHT_SIZE; i++){
		right_arr[i] = arr[mid + 1 + i];
	}
	
	int i, j, k;
	i = j = 0;
	k = left;
	
	while(i < LEFT_SIZE && j < RIGHT_SIZE){
		if(left_arr[i] < right_arr[j]){
			arr[k] = left_arr[i];
			i++;
		} else{
			arr[k] = right_arr[j];
			j++;
		}
		k++;
	}
	
	while(i < LEFT_SIZE){
		arr[k] = left_arr[i];
		i++;
		k++;
	}
	
	while(j < RIGHT_SIZE){
		arr[k] = right_arr[j];
		j++;
		k++;
	}
}


void mergeSort(int left, int right){
	// Divide	
	if(left < right){
		int mid = (left + right)/2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		
		//Conquer
		merge(left,mid,right);
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
	
	mergeSort(left,right);
	
	display();
	
	return 0;
}
