#include<stdio.h> 

// Number of vertices in the graph 
#define V 6 

#define INF 99999 

FILE *f;
int dist[V][V];
int graph[V][V]={ 		{0,	5,	6,	INF,	INF,	INF}, 
						{5,	0,	8,	3,	4,	INF}, 
						{6,	8,	0,	INF,	6,	INF}, 
						{INF,	3,	INF,	0,	3,	7}, 
						{INF ,	4,	6,	3,	0,	7}, 
						{INF,	INF,	INF,	7,	7,	0}, 
					}; 

// initialize dist matrix
void initDistMatrix(){
	int i, j;
	for (i = 0; i < V; i++) 
		for (j = 0; j < V; j++) 
			dist[i][j] = graph[i][j]; 
}

// floyd warshall algo
void floydWarshall () 
{ 
	
	int i, j, k; 

	// init dist matrix
	// loop -1
	for (k = 0; k < V; k++) 
	{ 
		// loop - 2
		for (i = 0; i < V; i++) 
		{ 
			// loop-3
			for (j = 0; j < V; j++) 
			{ 
				// relaxation condition
				if (dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j]; 
			}
		} 
		fprintf(f,"************K = %d************\n", k);
		printSolution();
		fprintf(f,"******************************\n");
	} 
} 

// print the floyd warshall matrix
void printSolution() 
{ 
	int i, j;
	for (i = 0; i < V; i++) 
	{ 
		for (j = 0; j < V; j++) 
		{ 
			if (dist[i][j] == INF) 
				fprintf(f,"%7s", "INF"); 
			else
				fprintf (f, "%7d", dist[i][j]); 
		} 
		fprintf(f,"\n"); 
	} 
} 

// driver func
int main() 
{
	f = fopen("floyd-warshall-result.txt", "w+");
	initDistMatrix();
	floydWarshall(); 
//	printSolution();
	fclose(f);
	return 0; 
} 

