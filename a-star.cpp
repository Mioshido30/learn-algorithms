
#include<stdio.h>
#include<vector>
#include<iostream>
#include<math.h>

#define mapWidth 17
#define mapHeight 10
#define maxN 10000

using namespace std;

struct Position{
  int a;
  int b;
};

Position constructorPosition(int a, int b){
  Position newPos;
  newPos.a = a;
  newPos.b = b;
  return newPos;
}

struct node{
  char value;
  bool visited;
  node *before;
};

node constructorNode(char value, bool visited, node *before){
  node newNode;
  newNode.value = value;
  newNode.visited = visited;
  newNode.before = before;
  return newNode;
}

char rawMap[mapHeight][mapWidth+1] = {
  "#################",
  "# x  #          #",
  "#    #          #",
  "#    #     #    #",
  "#    #     #    #",
  "#    #     #    #",
  "#    #     #    #",
  "#          #    #",
  "#          #  y #",
  "#################",
};

node map[mapHeight][mapWidth];

Position startPos, endPos;

void inputmap(){
	for(int i = 0; i < mapHeight; i ++){
		for(int j = 0; j < mapWidth; j++){
			if(rawMap[i][j] == 'x'){
				startPos = constructorPosition(i, j);
			}else if(rawMap[i][j] == 'y'){
				endPos = constructorPosition(i, j);
			}
			map[i][j] = constructorNode(rawMap[i][j], false, NULL);
		}
	}
}

bool isValid(Position pos) {
	if(
	pos.a < 0 || pos.a >= mapHeight || pos.b < 0 || 
	pos.b >= mapWidth || map[pos.a][pos.b].visited || map[pos.a][pos.b].value == '#'
	)
	return false;
	return true;
}

void printMap(){
	for(int i = 0; i < mapHeight; i ++){
		for(int j = 0; j < mapWidth; j++){
			if(map[i][j].visited) printf(".");
			else printf("%c", map[i][j].value);
		}
		puts("");
	}
}

double getHeuristic(Position pos) {
	int a = endPos.a - pos.a;
	int b = endPos.b - pos.b;
	return sqrt(a*a + b*b);
}

int V[] = {0, -1, 0, 1};
int H[] = {1, 0, -1, 0};

void aStar() {
	vector<Position> queue;
	queue.push_back(startPos);
	bool found = false;
	
	while(queue.size()) {
		int resIdx = 0;
		for(int i=0; i<queue.size(); i++) {
			if(getHeuristic(queue[i]) < getHeuristic(queue[resIdx])) {
				resIdx = i;
			}
		}
		Position curr = queue[resIdx];
		queue.erase(queue.begin() + resIdx);
		
		if(curr.a == endPos.a && curr.b == endPos.b){
			found = true;
			break;
		}
		
		for(int i=0; i<4; i++) {
			Position newPos = constructorPosition(
				curr.a + V[i],
				curr.b + H[i]
			);
			if(!isValid(newPos)) continue;
			
			queue.push_back(newPos);
			map[newPos.a][newPos.b].visited = true; 
		}
		printMap();
	}
	if(found) printf("FOUND");
	else printf("NOT FOUND");
}

int main(){
	inputmap();
	printMap();
	aStar();
}
