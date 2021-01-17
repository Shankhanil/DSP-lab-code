/*
***********************PROGRAM DESCRIPTION*******************
C program to sort an array and search the range of a value in sorted
array
*************************************************************


***********************STRUCTURE DESCRIPTION*****************
struct Stack: A structure describing a stack
int top: integer variable representing the top of the stack
unsigned maxSize: unsigned int variable representing the max
					capacity of the stack
int *stackArray: integer stackArray representing the stack as an stackArray
Stack* stack: a stack
*************************************************************

***********************FUNCTION DESCRIPTION******************
void searchFunction(): searches for an element in a sorted array
void swap(): swaps two integer values
void partition(), quickSort(): Function to partition an array, and
								sort an array using quick Sort. Pivot is
								the rightmost element of the subarray.
void printArray(): prints an array
*************************************************************
*/



#include<stdio.h> 
#include<stdbool.h>
#include<stdlib.h>
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; // choosing the pivot 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high- 1; j++) 
	{ 
		// If current element is smaller than the pivot 
		if (arr[j] < pivot) 
		{ 
			i++; // increment index of smaller element 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		// pi is partitioning index, arr[p] is now 
		// at right place
		int pi = partition(arr, low, high); 

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 

void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 

void searchFunction(int arr[], int size, int value){
    int i=0;
    _Bool flag = false, isFound = false;
    for (; i<size; i++){
        if ( arr[i] == value ){
            isFound = true;
            if (!flag ) printf("Begins at %d\n", i+1);
            flag = true;
        }
        if (arr[i]!= value && flag) {
            printf("ends at %d", i);
            break;
        }
    }
    if (!isFound) printf("Value %d not found in array", value);
}

// **********************DRIVER CODE******************************
int main() 
{ 
    int n, i=0, value;
    printf("Enter array size:");
    scanf("%d", &n);
	int *arr;
	arr = (int*) calloc(n, sizeof(int));
	for(; i<n; i++){
	    scanf("%d", arr+i);
	}
	
	printf("Enter search value:");
    scanf("%d", &value);
    
	printf("Original array: \n"); 
	printArray(arr, n);
	
	quickSort(arr, 0, n-1); 
	
	printf("Sorted array: \n");
	printArray(arr, n); 
	
	searchFunction(arr, n, value);
	
	return 0; 
} 
