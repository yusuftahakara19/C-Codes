#include <stdio.h>
#include <stdlib.h>


void printArray(int N, int arr[]){
	int i;
		 for(i=0;i<N;i++){
    	printf(" %d ",arr[i]);
	}
}

int main(int argc, char *argv[]) {
	int j,tmp,i,arraySize;
    printf("Enter array size : ");
    scanf("%d",&arraySize);

    int array[arraySize];
    for(i=0;i<arraySize;i++){
    	printf("Enter the %d. element of the array : ",i);
    	scanf("%d",&array[i]);
	}
	
	printf("\n");
	printArray(arraySize,array);

	
	for(i=1;i<arraySize;i++){
		tmp = array[i];
		j = i;
		
		while(j>0 && array[j-1]>tmp){
			array[j] = array[j-1];
			j--;
		}
		
		array[j] = tmp;
		printf("\n");
		printArray(arraySize,array);
		
	}
	
	
	
	

	return 0;
}
