#include<stdio.h>

// Descending
int* selectionSort(int array[], int length){
	
	for(int i=0; i < length - 1; i++){
		int max = i;
		for(int j=i+1; j < length; j++){
			/*Switch to < for sort ascending*/
			if(array[j] > array[max]){
				max = j;
			}
		}
		int temp = array[i];
		array[i] = array[max];
		array[max] = temp;
	}
	
	return array;
}

int main(){
	
	int old[] = {4,85,7,72,4,2,9,10,22,34};
	
	int length = sizeof(old)/sizeof(old[0]);
	int* sorted = selectionSort(old,length);
	
	for(int i=0; i<length; i++){
		printf("%d\n",sorted[i]);
	}
	
	return 0;
}
