#include<stdio.h>

int binarySearch(int arr[], int len, int toSearch){
	int start = 0;
	int end = len - 1;
	
	while(start <= end){
		int mid = (start + end) / 2;
		
		if(arr[mid] == toSearch) {
			return mid;
		} else if(arr[mid] > toSearch){
			end = mid - 1;
		} else{
			start = mid + 1;
		}
	}
	
	return -1;
}


int main(){
	
	int arr[10] = {10,12,19,28,37,46,55,78,89,100}; // Need to be Sorted Array
	int len = (sizeof(arr)/sizeof(arr[0]));
	int search = 12;
	
	int index = binarySearch(arr, len, search);
	if(index != -1){
		printf("Number found in index: %d\n", index);
	} else{
		printf("Number not found");		
	}
	
	return 0;
}
