#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char* color;
    int index;
} color_t;


int printMatrix(color_t* colors,int **matrix,int n){
	int i,j;
	  printf("\n\n");
	    for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                printf(" 	%s	 ", colors[matrix[i][j]].color );
            printf("\n");
    }
    printf("\n\n");
    return 1;
}


void solve(color_t* colors,int **board,int n,int row,int choice) {
	
	  int i,j,last,counter;

    
    // if all rows have been processed, the game board has been solved
    if (row == -1) {
        return;
    }

    	counter =0;
    	while ( counter < n && !check(board,n) ){
    		
    // shift the colors in the current row and check against previous rows
        last = board[row][n - 1];  
        for (j = n - 1; j > 0; j--) {
        board[row][j] = board[row][j - 1];
      }  
     // put temporary variable at the beginning
      board[row][0] = last;
      
       	  if(choice == 2)
            printMatrix(colors,board,n);
            
         counter++;
		}  
		
	      if(counter == n)
		    solve(colors,board,n,row - 1,choice); 

}

//checking that there is only 1 of each color in each column
int check(int **matrix,int N) {
  int i,j,column;
  
  for (column = 0; column < N; column++) {
	for ( i = 0; i < N; i++) {
 	 for (  j = 0; j < i; j++) {
   		 if (i != j && matrix[i][column] == matrix[j][column]) {
       		 return 0;
   		 }
    
 	 }
	}
  }
	return 1;
}




int main() {
	 int n,i,j,colorSize,temp,choice;
    colorSize = 8; // Define 8 colors since n is maximum 8
    
    // The matrix size taken
 while(1){
 
    do{
     printf("Enter matrix size between [3-8] : ");
     scanf("%d", &n);
	}while(n<3 || n>8);
    
    
    
    // Colors will be kept in an array
    color_t* colors = (color_t*)malloc(colorSize * sizeof(color_t));
    
    colors[0].color = (char*)malloc(strlen("red") + 1);
    strcpy(colors[0].color, "red");
    colors[0].index = 0;
    colors[1].color = (char*)malloc(strlen("green") + 1);
    strcpy(colors[1].color, "green");
    colors[1].index = 1;
    colors[2].color = (char*)malloc(strlen("blue") + 1);
    strcpy(colors[2].color, "blue");
    colors[2].index = 2;
    colors[3].color = (char*)malloc(strlen("yellow") + 1);
    strcpy(colors[3].color, "yellow");
    colors[3].index = 3;
    colors[4].color = (char*)malloc(strlen("purple") + 1);
    strcpy(colors[4].color, "purple");
    colors[4].index = 4;
    colors[5].color = (char*)malloc(strlen("orange") + 1);
    strcpy(colors[5].color, "orange");
    colors[5].index = 5;
    colors[6].color = (char*)malloc(strlen("pink") + 1);
    strcpy(colors[6].color, "pink");
    colors[6].index = 6;
    colors[7].color = (char*)malloc(strlen("brown") + 1);
    strcpy(colors[7].color, "brown");
    colors[7].index = 7;
    
    for(i=0;i<n;i++){ //there are N colors on an NxN game board.
    	printf("\n%d -> %s",i,colors[i].color);
	}

    
    // Allocate memory for the matrix
    int** matrix = (int**)malloc(n * sizeof(int*));
    for ( i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    // Get values for the matrix from the user
     printf("\n\nEnter color index between [0-%d]\n",n-1);
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
        	do{
        	    printf("\nmatrix[%d][%d]: ", i, j);
                scanf("%d", &temp);	
			}while(temp>=n || temp<0);
            matrix[i][j] = temp;
        }
    }
    
    	printf("\n\n ********************************* Entered Matrix *********************************\n\n");
      	printMatrix(colors,matrix,n);
     	printf("\n\n **********************************************************************************\n\n");

    
    
   	printf ("\n\n 1- Working in normal mode");
	printf ("\n 2- Working in detail mode");
	printf("\n Make your choice : ");
	scanf("%d",&choice);

    solve(colors,matrix, n, n-1,choice);  
    
    if(check(matrix,n)){
    	printf("\n\n ********************************* Solution found *********************************\n\n");
    	printMatrix(colors,matrix,n);
    	printf("\n\n **********************************************************************************\n\n");
	}else{
		printf("\n\n ********************************* No solution found for the given matrix *********************************\n\n");

	}

	
   // Free the allocated memory
    for ( i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

   // Free the allocated memory
    for ( i = 0; i < n; i++) {
        free(colors[i].color);
    }
    free(colors);
    

    printf("\n\n");
}
    
    
    return 0;
}

