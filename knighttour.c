#include <stdio.h>
#include<stdlib.h>
//Knight tour problem
/* given a regular 8*8 chess board, print out a route of how a knight can travel sequentially from one cell to another
the board is printed out with the order marked on each cell 
the function returns 1 if a solution is found
returns 0 if a solution cannot be determined.
*/
void printboard(int **board, int n){
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
            char cell = board[i][j];
            printf("%c",cell);
        }
        printf("\n");
    }
	return;
}

int checkingbounds(int n, int i, int j){
    if (i>=n || i<0 || j>=n || j<0){
        return 0;
    }
    return 1;
}

int knighttoursolve(int** board, int i, int j,int n){
    if(board[i][j])return 0;
    if(!(checkingbounds(n,i,j)))return 0;
    board[i][j] = 'K';
    if(knighttoursolve(board, i+2,j+1,n))return 1;
    if(knighttoursolve(board, i+2,j-1,n))return 1;
    if(knighttoursolve(board, i-2,j+1,n))return 1;
    if(knighttoursolve(board, i-2,j-1,n))return 1;
    if(knighttoursolve(board, i+1,j+2,n))return 1;
    if(knighttoursolve(board, i-1,j+2,n))return 1;
    if(knighttoursolve(board, i+1,j-2,n))return 1;
    if(knighttoursolve(board, i-2,j-2,n))return 1;
    board[i][j] = '\0';
    return 0;
}


int main(){
    int n;
    scanf("%d",&n); //n represents the dimension of the board (assuming board is n*n)

    //creating space for 2D array, initialized with zeroes
    int i;
    int** board;
    board = (int**)calloc(n,sizeof(int*));
    for (i = 0; i<n; i++){
        board[i] = (int* )calloc(n,sizeof(int));
    }

    //solving knight tour
    int solve = knighttoursolve(board, 0,0,n);
    if(solve){
        printf("Solved");
        printboard(board,n);
    }
    else{
        printf("No solution.");
    }
}
