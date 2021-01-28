#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX 50

typedef struct node
{
	int label;
	bool isVisited;
	struct node *next;
	
} Vertex;

typedef struct List{
	Vertex *head, *tail;
} List;

List *adjList[MAX];
//Vertex* vertexList[MAX];
//bool isVisited[MAX] = {false};
int vertexCount; // number of vertices

// ***************ADJ-LIST FUNCTIONS******************************
// create a new vertex node
Vertex *newVertex(int label){
	Vertex *node;
	node = (Vertex*)malloc(sizeof(Vertex));
	
	node->label = label;
	node->isVisited = false;
	node->next = NULL;
	return node;
}

// initialize an adj list
void initAdjList(){
	int i = 0; 
	
	for(;i <vertexCount; i++){
		adjList[i] = (List*) malloc(sizeof(List));
		adjList[i]->head = newVertex(-1);
		adjList[i]->tail = newVertex(-1);
		adjList[i]->head->next = adjList[i]->tail;
	}
}

// add undirected edge to adj list
void addUndirectedEdge( int source, int destination){
	Vertex *v = newVertex(destination);
	v->next = adjList[source]->head->next;
	adjList[source]->head->next = v;
	
	Vertex *v2 = newVertex(source);
	v2->next = adjList[destination]->head->next;
	adjList[destination]->head->next = v2;
}

// vanilla LL traversal
void traverse(List *L){
	Vertex *temp = L->head->next;
	printf("[HEAD]->");
	while(temp != L->tail){
		printf("%d ->", temp->label);
		temp = temp->next;
	}
	printf("[TAIL]\n");
}

// display entire adj list
void traverseAdjList(){
	int i = 0; 
	for(; i<vertexCount; i++){
		printf("%d ", i);
		traverse(adjList[i]);
	}
}

// ***************GRAPH FUNCTIONS******************************
// vanilla DFS util fn on ADJ list
void DFSUtil(int vertexIndex, int isVisited[]){
	 isVisited[vertexIndex] = true;
	 Vertex *temp = adjList[vertexIndex]->head->next;
	 
	 while(temp != adjList[vertexIndex]->tail){
	 	// if temp vertex is not visited
		if ( isVisited[temp->label] == false)
//			printf("now visiting %d", temp->label);
			DFSUtil(temp->label, isVisited);
		temp = temp->next;
	}
}

// calculate number of connected components
int numOfConnectedComponents(){
	int connectedComponentCount = 0;
	int i = 0;
	bool isVisited[MAX] = {false};
//	printf("%d ", isVisited[MAX-10]);
//	isVisited = (bool*) malloc(vertexCount*sizeOf(bool));
	for(; i<vertexCount; i++){
		if (isVisited[i] == false){
			DFSUtil(i, isVisited);
			connectedComponentCount++;
		}
	}
	printf("%d", connectedComponentCount);
	return connectedComponentCount;
}

void buildGraphFromFile(FILE *f){
	
}

main(){
	vertexCount = 10;
	//initVertexList();
	initAdjList();
	
	// add edges
	addUndirectedEdge(1, 0);
    addUndirectedEdge(2, 3);
    addUndirectedEdge(3, 4);
//	addUndirectedEdge(0,1);
//	addUndirectedEdge(0,2);
//	addUndirectedEdge(0,3);
//	addUndirectedEdge(0,4);
//	
	// show the adj list
	traverseAdjList();
	
	// calculate the #of Connected components
	numOfConnectedComponents();
}
