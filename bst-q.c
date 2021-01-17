#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct vertex{
	char label; // label of the vertex
//	int vindex; // index of the vertex in the vertex-list
	bool isVisited; // is the vertex visited

}vertex;

// ****************QUEUE FUNCTIONS*****************
int queue[MAX]; // defining the queue
int rear = -1, front = 0, qsize = 0;

void enqueue(int data){
	queue[++rear] = data; 	
}

int dequeue(){
	if (front <= rear) return queue[front++];
	else {
		front = 0;
		rear = -1;
		return -1;
	}
}
bool isEmpty(){
	return (front > rear);
}
// ****************GRAPH FUNCTIONS*****************
int adjM[MAX][MAX];
vertex* vList[MAX];
int vCount = -1;

void newVertex(char label){
	vertex *nv = (vertex*) malloc(sizeof(vertex));
	
	nv->label = label;
	nv->isVisited = false;
	
	vList[++vCount] = nv;
}
int getEdgeIndex(char label){
	int i= 0;
	for (; i<=vCount; i++){
		if (vList[i]->label == label) return i;
	}
	return -1;
}
void addEdge(char label1, char label2){
	int index1 = getEdgeIndex(label1), index2 = getEdgeIndex(label2); 
//	printf("%d %d", index1, index2);
	if (index1 != -1 && index2!= -1){
		adjM[index1][index2] = 1;
		adjM[index2][index1] = 1;
	}
}
void displayVertex(int index){
	printf("%c ", vList[index]->label);
}

int getAdjUnvVertex(int index){
	int i = 0;
	for(; i<=vCount; i++){
		if(adjM[index][i] == 1 && vList[i]->isVisited == false) return i;
	}
	return -1;
}
// ***************TRAVERSAL FN*********************
void bfs(){
//	int i;
	vList[0]->isVisited = true;
	
	enqueue(0);
	displayVertex(0);
	int unvVertex;
	while (!isEmpty()){
		int tempVindex = dequeue();
		unvVertex = getAdjUnvVertex(tempVindex);
		while (-1 != unvVertex){
			vList[unvVertex]->isVisited = true;
			displayVertex(unvVertex);
			enqueue(unvVertex);
			unvVertex = getAdjUnvVertex(tempVindex);
		}
	}
}
// ****************DRIVER CODE*********************
int main(){
//	vertex* nv1, nv2, nv3;
	newVertex('A');
	newVertex('B');
	newVertex('C');

	addEdge('A', 'C');
	addEdge('C', 'B');
	bfs();
	return 0;
}
