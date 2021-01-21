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
int stack[MAX]; // defining the queue
int top = -1;

void push(int data){
	stack[++top] = data; 	
}

int pop(){
	if (top >= 0) return stack[top--];
	return -1;
}
bool isEmpty(){
	return (top == -1);
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
void dfs(){
	int i;
	vList[0]->isVisited = true;
	
	push(0);
	displayVertex(0);
	int unvVertex;
	
	// while stack is not empty
	while (!isEmpty()){
		// peek stack top
		int tempVindex = stack[top];
		
		// get unv adj vertex against temp vertex
		unvVertex = getAdjUnvVertex(tempVindex);
		
		// if no adj vertex
		if (-1 == unvVertex){
			pop(); // then pop from stack
		}
		else{
			// else visit vertex and push to stack
			vList[unvVertex]->isVisited = true;
			displayVertex(unvVertex);
			push(unvVertex);
//			unvVertex = getAdjUnvVertex(tempVindex);
		}
	}
}
// ****************DRIVER CODE*********************
int main(){
//	vertex* nv1, nv2, nv3;
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
	dfs();
	
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
	dfs();
	
	return 0;
}
