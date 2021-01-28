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

List *adjList[MAX]; // the adjaceny LIST array
bool isVisited[MAX] = {false}; // a boolean array marking the visit-status of a vertex i
int vertexCount; // total number of vertices in the graph

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
void DFSUtil(int vertexIndex) {
	// marking the current vertex as visited
	isVisited[vertexIndex] = true;
	Vertex *temp = adjList[vertexIndex]->head->next;
	
	while(temp != adjList[vertexIndex]->tail){
		if ( isVisited[temp->label] == false)
			DFSUtil(temp->label); // recursive calling DFS-util
		temp = temp->next;
	}
}

// calculate number of connected components
int numOfConnectedComponents(){
	
	int connectedComponentCount = 0;
	int i = 0;
	
	for(; i<vertexCount; i++){
		if (isVisited[i] == false){
			DFSUtil(i);
			connectedComponentCount++;
		}
	}
	return connectedComponentCount;
}

void buildGraphFromFile(FILE *f){
	int v1, v2;
	
	fscanf(f, "%d", &vertexCount);
	printf("Total vertices = %d\n", vertexCount);
    printf("\n\n");
	initAdjList();
    
	while(fscanf(f, "%d", &v1) == 1) {
    	if (fscanf(f, "%d", &v2) == 1){
    		if (
					(v1 < 0 || v1 >= vertexCount) || 
					(v2 < 0 || v2 >= vertexCount)
				)
					printf("Invalid vertex %d and %d skipping...\n", v1, v2);
			else{
        		addUndirectedEdge(v1, v2);
        		printf("Added undirected edge btn %d and %d\n", v1, v2);
			}
		}
    }
    printf("\n\n");
    printf("the adj list representation of the graph is as \n");
    traverseAdjList();
    printf("\n\n");
}

main(){
	FILE *inputFIle, *outputFile;
	inputFIle = fopen("connected-component-input-file.txt", "r");
	outputFIle = fopen("connected-component-output-file.txt", "w");
	buildGraphFromFile(inputFile);
	printf("Total number of connected components = %d\n", numOfConnectedComponents());
	
}
