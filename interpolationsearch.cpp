#include<stdio.h>

// Interpolation search
int interpolationSearch(int data[], int len, int key){
	int left = 0, right = len-1;
	while(data[left]<key && data[right]>key){
		int mid = left + (right-left)*(key-data[left])/(data[right]-data[left]);
		if(data[mid]==key) return mid;
		else if(data[mid]<key) left = mid+1;
		else if(data[mid]>key) right = mid+1;
	}
	if(data[left]==key) return left;
	else if(data[right]==key) return right;
	return -1;
}


int main(){
	
	int arr[10] = {10,12,19,28,37,46,55,78,89,100}; // Need to be Sorted Array
	int len = (sizeof(arr)/sizeof(arr[0]));
	int search = 12;
	
	int index = interpolationSearch(arr, len, search);
	if(index != -1){
		printf("Number found in index: %d\n", index);
	} else{
		printf("Number not found");		
	}
	
	return 0;
}
