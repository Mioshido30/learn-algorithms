#include<stdio.h>

int memo[100]={0};

int fibonacci(int n){
	if(n==0){
		return 0;
	} else if(n==1){
		return 1;
	} else{
		if(memo[n]==0){
			memo[n] = fibonacci(n-1) + fibonacci(n-2);
		}
		return memo[n];
	}
	
}

int main(){
	
	/* Fibonacci Sequence:
		0 1 1 2 3 5 8 13 21 .... ( Number(n) = Number(n-1) + Number(n-2) )
	*/
	
	printf("%d\n", fibonacci(40));
	
	return 0;
}
