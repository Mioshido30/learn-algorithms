#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define maxN 100

// DISJOINT SET

int parent[maxN];

void initDisjoint() {
	for (int i = 0; i < maxN; i++) {
		parent[i] = i; // Semuanya adalah parent dari diri sendiri karena belum ada hubungan.
	}
}

int getAncestor(int x){
	if (parent[x] == x) {
		return x;
	}
	// Ketika parentnya beda berarti cari parent dari parent.
	return getAncestor(parent[x]);
}

bool isSameAncestor(int x, int y) {
	return getAncestor(x) == getAncestor(y);
}

void merge(int x, int y) {
	// Merge ancestor dari x dan y	
	int ancX = getAncestor(x);
	int ancY = getAncestor(y);
	
	// Kalau sudah sama, return
	if (ancX == ancY) {
		return;
	}
	
	// Jadikan grup yang sama dengan menyamakan parent
	parent[ancX] = ancY;
}

// KRUSKAL

struct Edge {
	int source;
	int dest;
	int weight;
};

struct Edge constructorEdge(int source, int dest, int weight) {
	struct Edge newEdge;
	newEdge.source = source;
	newEdge.dest = dest;
	newEdge.weight = weight;
	return newEdge;
};

struct Edge edgeList[] = {
  	constructorEdge(0, 1, 9),
  	constructorEdge(0, 2, 75),
  	constructorEdge(1, 2, 95),
  	constructorEdge(1, 3, 19),
  	constructorEdge(1, 4, 42),
  	constructorEdge(2, 3, 51),
	constructorEdge(3, 4, 31)
};

int edgeListSize = 7;

void sortEdgeList() {
	// Insertion Sort
	for (int i = 0; i < edgeListSize; i++) {
		int index = i;
		while (index > 0 && edgeList[index].weight < edgeList[index - 1].weight) {
			Edge t = edgeList[index];
			edgeList[index] = edgeList[index - 1];
			edgeList[index - 1] = t;
			index--;
		}
	}

	// Bubble Sort
	/*
	for (int i = 0; i < edgeListSize; i++) {
		for (int j = 0; j < edgeListSize - i - 1; j++) {
			if (edgeList[j].weight > edgeList[j + 1].weight) {
				Edge t = edgeList[j];
				edgeList[j] = edgeList[j + 1];
				edgeList[j + 1] = t;
			}
		} 
	}
	*/
}


int main() {
	initDisjoint();
	
	sortEdgeList();
	
	int totalWeight = 0;
	
	for (int i = 0; i < edgeListSize; i++) {
		Edge edge = edgeList[i];
		if (isSameAncestor(edge.source, edge.dest)) {
			continue;
		}
		
		// Merge
		totalWeight += edge.weight;
		merge(edge.source, edge.dest);
		printf("%d %d %d\n", edge.source, edge.dest, edge.weight);
	}
	
	printf("%d\n", totalWeight);
	
	return 0;	
}
