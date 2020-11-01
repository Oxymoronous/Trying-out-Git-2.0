int removeDuplicates(int *arr, int n){
	int lastUnique = 0;
	int i;
	for (i = 0; i<n; i++){
		if(arr[lastUnique]!=arr[i]){
			arr[lastUnique+1] = arr[i]
			lastUnique = i;
		}
		printf("%d\n",lastUnique);
		for (int j = 0; j<n;j++){
			printf("%d ", *(arr+j));
		}
		
	}
	return (lastUnique);
}

//problem2
int min (int a, int b){
	if (a>=b)return b;
	return a;
}

int min_path_sum(int **grid, int m, int n, int i, int j){
	if ((i == 0) && (j == 0))return 0;
	int left = grid[i][j-1];
	int up = grid[i-1][j];
	int m = min(left, up);
	if (m == left){
		return min_path_sum(grid, m, n, i, j-1)+m;
	}else{
		return min_path_sum(grid, m, n, i-1 , j)+m; 
	}
}

//concepts questions
1. the output of the current program
ori = 01234

(5) 41230
(4) 31240
(3) 21340
(2) 12340
(1) 12340

2. how to engineer the code
ReverseArray(array+1,size-1)

//partB
1. accessing 2D array that is in 1D
to access row i column j
-> array[i*n+j]

2. random number between 7 and 17
rand()%11+7

3. size in the struct
800 + 32 bits = 104 bytes
