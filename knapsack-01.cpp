#include<stdio.h>

// Knapsack (0 1)

int max(int a, int b){
	return (a>b)? a : b;
}

// BruteForce
int knap(int weight[], int val[], int n, int carry, int currItem){
	
	if(currItem == n || carry == 0){
		return 0;
	}
	
	if(weight[currItem] <= carry){
		return max( knap(weight,val,n,carry-weight[currItem], currItem+1) + val[currItem],
		knap(weight,val,n,carry,currItem+1)
		);
	} else{
		return knap(weight,val,n,carry,currItem+1); 
	}
}

// Knapsack using Dynamic Programming
int memo[100][10000] = {0};
int knapDP(int weight[], int val[], int n, int carry, int currItem){
	
	if(currItem == n || carry==0){
		return 0;
	} 
	
	if(memo[currItem][carry]!=0){
		return memo[currItem][carry];
	}
	
	if(weight[currItem] <= carry){
		return memo[currItem][carry] = max(
			knapDP(weight,val,n,carry-weight[currItem],currItem+1)+val[currItem],
			knapDP(weight,val,n,carry,currItem+1)
		);
	} else{
		return memo[currItem][carry] = knapDP(weight,val,n,carry,currItem+1);
	}
}

int main(){

	int weight[] = {4,1,7,9,1};
	int value[] = {100,200,300,400,300};
	int carry = 13;
	int n = sizeof(weight)/sizeof(weight[0]);
	
//	printf("%d", knap(weight,value,n,carry,0));
	printf("%d", knapDP(weight,value,n,carry,0));
	
		
	return 0;
}
