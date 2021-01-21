#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct vertex{
	char label; // label of the vertex
	bool isVisited; // is the vertex visited

}vertex;

// ****************QUEUE FUNCTIONS*****************
int queue[MAX]; // defining the queue
int rear = -1, front = 0;

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

// creating new vertex
void newVertex(char label){
	vertex *nv = (vertex*) malloc(sizeof(vertex));
	
	nv->label = label;
	nv->isVisited = false;
	
	// and adding new vertex to vertex list
	vList[++vCount] = nv;
}

// function to get index of edge
int getEdgeIndex(char label){
	int i= 0;
	for (; i<=vCount; i++){
		if (vList[i]->label == label) return i;
	}
	return -1;
}
void addEdge(char label1, char label2){
	int index1 = getEdgeIndex(label1), index2 = getEdgeIndex(label2); 
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
	int unvVertex; // unvisited vertex
	
	// if queue not empty then continue the loop
	while (!isEmpty()){
		// dequeue and store temporary vertex index from vlist in tempVindex
		int tempVindex = dequeue();
		// get unvisited vertex index 
		unvVertex = getAdjUnvVertex(tempVindex);
		
		// if there is some unvisited vertex
		while (-1 != unvVertex){
			// then mark it visited
			vList[unvVertex]->isVisited = true;
			// display it
			displayVertex(unvVertex);
			// enqeue it
			enqueue(unvVertex);
			// and get unvisited adj vertex of that and continue loop
			unvVertex = getAdjUnvVertex(tempVindex);
		}
	}
}
// ****************DRIVER CODE*********************
int main(){
	// creating new graph
	newVertex('0');
	newVertex('1');
	newVertex('2');
	newVertex('3');
	newVertex('4');
	
	addEdge('1', '0');
	addEdge('0', '2');
	addEdge('1', '2');
	addEdge('2', '4');
	addEdge('0', '3');
	bfs();
	
	// resetting the vCount = -1, meaning the graph is empty
	vCount = -1;
	printf("\n");
	
	// creating new graph
	newVertex('1');
	newVertex('2');
	newVertex('3');
	newVertex('4');
	newVertex('5');
	newVertex('6');

	addEdge('1', '4');
	addEdge('1', '2');
	addEdge('2', '3');
	addEdge('2', '5');
	addEdge('5', '6');
	bfs();
	
	return 0;
}
