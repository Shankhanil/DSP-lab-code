#include <stdio.h>

#define MAX 30

typedef struct edge {
  int src, dest, weight;
} edge;

typedef struct edgeList {
  edge data[MAX];
  int n;
} edgeList;

edgeList elist;

int Graph[MAX][MAX], n, vertexCount;
edgeList spanList;

FILE *inputFile, *outputFile;

//*************FUNCTION SIGNATURES**************
void buildGraphFromFile(FILE *f);
void addUndirectedEdge();
void kruskalAlgo();	// implementation of kruskal algo
int  find(int belongs[], int vertexno);	// find operation
void applyUnion(int belongs[], int c1, int c2); // union operation
void sort(); // refactored O(n^2) sort algo, to sort the elist based on their weights
void print(); // print result
//**********************************************

//*************FUNCTION DESCRIPTION**************
void addUndirectedEdge( int src, int dest, int weight){
	elist.data[elist.n].src = src;
	elist.data[elist.n].dest = dest;
	elist.data[elist.n].weight = weight;
	elist.n++;
}

void buildGraphFromFile(FILE *f){
	int v1, v2, weight;
	
	fscanf(f, "%d", &vertexCount);
	fprintf(outputFile, "Total vertices = %d\n", vertexCount);
	fprintf(outputFile, "\n\n");
	
	elist.n = 0;
    
	while(fscanf(f, "%d", &v1) == 1) {
		if (fscanf(f, "%d", &v2) == 1 && fscanf(f, "%d", &weight) == 1 ) {
			if (
				(v1 < 0 || v1 >= vertexCount) || 
				(v2 < 0 || v2 >= vertexCount)
			)
				fprintf(outputFile, "Invalid vertex %d and %d skipping...\n", v1, v2);
			else{
				addUndirectedEdge(v1, v2, weight);
				fprintf(outputFile, "Added undirected edge btn %d and %d, weight = %d\n", v1, v2, weight);
			}
		}
	}
}

void kruskalAlgo() {
	int belongs[MAX], i, j, cno1, cno2;

	// sort the edgeList based on weight of edge
	sort();
	
	// i-th belongs-set contains the i-th edge only. 
	// belongs-set updates as more edges are added, 
	for (i = 0; i < vertexCount; i++)
		belongs[i] = i;
	
	// initialize mst size as 0
	spanList.n = 0;

	// building the mst
	for (i = 0; i < elist.n; i++) {
		
		cno1 = find(belongs, elist.data[i].src);
		cno2 = find(belongs, elist.data[i].dest);
		
		// if on including the edge btn src and dest
		// NOT cause cycle...
		if (cno1 != cno2) {
			// ...then add edge to mst
			spanList.data[spanList.n] = elist.data[i];
			spanList.n = spanList.n + 1;
			// and add src and vertex to i-th belongs set
			applyUnion(belongs, cno1, cno2);
		}
	}
}
int find(int belongs[], int vertexno) {
  return (belongs[vertexno]); // return true if 
}

void applyUnion(int belongs[], int c1, int c2) {
  int i;

  for (i = 0; i < vertexCount; i++)
    if (belongs[i] == c2)
      belongs[i] = c1;
}

void sort() {
  int i, j;
  edge temp;

  for (i = 1; i < elist.n; i++)
    for (j = 0; j < elist.n - 1; j++)
      if (elist.data[j].weight > elist.data[j + 1].weight) {
        temp = elist.data[j];
        elist.data[j] = elist.data[j + 1];
        elist.data[j + 1] = temp;
      }
}

// Printing the result
void print() {
	int i, cost = 0;
	fprintf(outputFile, "\n\n------------MST SOLUTION---------------");
	for (i = 0; i < spanList.n; i++) {
		fprintf(outputFile, "\n%d - %d : %d", spanList.data[i].src, spanList.data[i].dest, spanList.data[i].weight);
		cost = cost + spanList.data[i].weight;
	}
	fprintf(outputFile, "\n\n------------MST COST---------------");
	fprintf(outputFile, "\nSpanning tree cost: %d", cost);
}

//***************DRIVER CODE*****************************
int main() {
	int i, j, total_cost;
	printf("Input read from: ./kruskal-mst-input-file.txt\n");
	inputFile = fopen("kruskal-mst-input-file.txt", "r");
	outputFile = fopen("kruskal-mst-output-file.txt", "w");
	buildGraphFromFile(inputFile);
	kruskalAlgo();
	print();
	printf("Output written to: ./kruskal-mst-output-file.txt");
}
