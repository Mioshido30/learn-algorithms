#include<stdio.h>

int linearSearch(int arr[], int len, int toSearch){
	for(int i=0; i<len; i++){
		if(arr[i] == toSearch){
			return i;
		} 
	}
	return -1;
}


int main(){
	
	int arr[10] = {100,33,45,67,23,12,56,34,28,3};
	int len = (sizeof(arr)/sizeof(arr[0]));
	int search = 12;
	
	int index = linearSearch(arr, len, search);
	if(index != -1){
		printf("Number found in index: %d\n", index);
	} else{
		printf("Number not found");		
	}
	
	return 0;
}
