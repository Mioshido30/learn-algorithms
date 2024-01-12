#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#define maxN 100
using namespace std;

// PRIM

struct Adj{
	int dest;
	int weight;
};

struct Adj constructorAdj(int dest, int weight){
	struct Adj newEdge;
	newEdge.dest = dest;
	newEdge.weight = weight;
	return newEdge;
};

vector<Adj> adjList[maxN];

bool visited[maxN] = {0};

vector<Adj> queue;

void insertQueueAndSort(Adj newAdj){
	queue.push_back(newAdj);
	int index = queue.size() - 1;
	while (index > 0 && queue[index].weight < queue[index - 1].weight) {
	Adj t = queue[index];
	  queue[index] = queue[index - 1];
	  queue[index - 1] = t;
	  index--;
  }
} 

void pickNode(int x){
	if (visited[x] == true) {
		return;
	}
	
	visited[x] = 1;
	for (int i = 0; i < adjList[x].size(); i++) {
		insertQueueAndSort(adjList[x][i]);
	}
}

int main(){	
	adjList[0].push_back(constructorAdj(1, 9));
	adjList[0].push_back(constructorAdj(2, 75));
	adjList[1].push_back(constructorAdj(0, 9));
	adjList[1].push_back(constructorAdj(2, 95));
	adjList[1].push_back(constructorAdj(3, 19));
	adjList[1].push_back(constructorAdj(4, 42));
	adjList[2].push_back(constructorAdj(0, 75));
	adjList[2].push_back(constructorAdj(1, 95));
	adjList[2].push_back(constructorAdj(3, 51));
	adjList[3].push_back(constructorAdj(1, 19));
	adjList[3].push_back(constructorAdj(2, 51));
	adjList[3].push_back(constructorAdj(4, 31));
	adjList[4].push_back(constructorAdj(1, 42));
	adjList[4].push_back(constructorAdj(3, 31));

	int startingNode = 0;
	pickNode(startingNode);
	
	int totalWeight = 0;
	
	while (queue.size() > 0) {
		Adj curr = queue[0];
		queue.erase(queue.begin());
		
		if (visited[curr.dest] == true) {
			continue;
		}
		
		// Ambil adj
		totalWeight += curr.weight;
		pickNode(curr.dest);
	}
	
	printf("%d\n", totalWeight);
}
