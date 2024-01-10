
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

Position x, y;

void inputmap(){
	for(int i = 0; i < mapHeight; i ++){
		for(int j = 0; j < mapWidth; j++){
			if(rawMap[i][j] == 'x'){
				x = constructorPosition(i, j);
			}else if(rawMap[i][j] == 'y'){
				y = constructorPosition(i, j);
			}
			map[i][j] = constructorNode(rawMap[i][j], false, NULL);
		}
	}
}

void printMap(){
	for(int i = 0; i < mapHeight; i ++){
		for(int j = 0; j < mapWidth; j++){
//			if(map[i][j].visited) printf(".");
//			else 
			printf("%c", map[i][j].value);
		}
		puts("");
	}
}

int V[] = {0, -1, 0, 1};
int H[] = {1, 0, -1, 0};

bool isValid(Position pos) {
	// if position invalid
	// atau kotak udh divisit
	// return false
	if(
		pos.a < 0 || pos.b < 0
		|| pos.a >= mapHeight || pos.b >= mapWidth
		|| map[pos.a][pos.b].visited ||
		map[pos.a][pos.b].value == '#'
	) return false;
	return true;
}

void backtrack(node *curr) {
	if(curr == NULL) return;
	curr->value = '=';
	backtrack(curr->before);
}

void dijkstra(){
	vector<Position> queue;
	queue.push_back(x);
	
	map[x.a][x.b].visited = true;
	bool found = false;
	
	while(queue.size()){
		Position curr = queue[0];
		queue.erase(queue.begin());
		
//		if(map[curr.a][curr.b].visited){
//			continue;
//		}
		
		if(curr.a == y.a && curr.b == y.b){
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
			map[newPos.a][newPos.b].before = &map[curr.a][curr.b];
		}
		printMap();
	}
	if(found) printf("FOUND\n");
	else printf("NOT FOUND");
	
	backtrack(&map[y.a][y.b]);
	printMap();
}



int main(){
	inputmap();
	printMap();
	dijkstra();
}
