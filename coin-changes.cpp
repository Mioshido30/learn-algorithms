#include<stdio.h>

// Coin change - finding all coin combination for changes

// similar to infinite knapsack
int coinC(int coins[], int change, int n){

	if(change==0){
		return 1;
	} 
	
	if(n == 0 || change < 0){
		return 0;
	}
	
	return coinC(coins, change-coins[n-1], n) + 
		coinC(coins,change,n-1); 
	
}


int coinCDP(int coins[], int change, int n){
	int memo[change+1] = {0};
	
	memo[0] = 1;
	for(int i=0; i<n; i++){
		
		for(int j=0; j<=change; j++){
			if(j>= coins[i]){
				memo[j] = memo[j] + memo[j - coins[i]];
			}
		}
	}
	
	return memo[change];
}

int main(){
	
//	int coins[] = {100,200,500};
//	int changes = 1000;
	int coins[] = {1,2,3};
	int changes = 6;
	int n = sizeof(coins)/sizeof(coins[0]);
	
//	printf("%d", coinC(coins,changes,n));
	printf("%d", coinCDP(coins,changes,n));
	
	return 0;
}
