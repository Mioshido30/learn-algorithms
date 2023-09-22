#include<stdio.h>

//Descending
int* bubbleSort(int array[], int length){
	
	for(int i=0; i < length - 1; i++){
		for(int j=0; j < length - i - 1; j++){
			/* Switch to > for sort ascending*/
			if(array[j] < array[j+1]){
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	
	return array;
}


int main(){
	
	int old[] = {4,85,7,72,4,2,9,10,22,34};
	
	int length = sizeof(old)/sizeof(old[0]);
	int* sorted = bubbleSort(old,length);
	
	for(int i=0; i<length; i++){
		printf("%d\n",sorted[i]);
	}
	
	return 0;
}
