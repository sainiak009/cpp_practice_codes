// Ankit Saini - sainiak009@gmail.com
// Backtracking is used

#include <iostream>
using namespace std;

const int N = 9;

void print(int board[][N]){
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cout << board[i][j] << " " ;
		}
		cout << endl;
	}
}

bool canPlace(int mat[][N], int row, int col, int num){
	for(int c = 0; c < N; ++c){
		if (mat[row][c] == num)	return false;
	}
	//check in col
	for(int r = 0; r < N; ++r){
		if (mat[r][col] == num) return false;
	}
	//check in box	
	int rootN = 3;	//sqrt(N)
	int box_rst = (row / rootN) * rootN;
	//				box No
	int box_cst = col / rootN * rootN;

	for(int i = box_rst; i < box_rst + 3; ++i){
		for(int j = box_cst; j < box_cst + 3; ++j){
			if (mat[i][j] == num) return false;
		} 
	}

	return true;


}


bool solve(int mat[][N], int row, int col){
	if(row == N) return true;

	if(col == N) return solve( mat, row+1, 0);

	if(mat[row][col] != 0) return solve( mat, row, col+1);

	for(int i=1; i<=N; ++i){
		if(canPlace(mat, row, col, i)){
			mat[row][col] = i;
			if(solve(mat, row, col + 1)) return true;
			else mat[row][col] = 0; // Backtracking
		}
	}

	return false;
}

int main(){
	int mat[9][9] =
					{{5,3,0,0,7,0,0,0,0},
					{6,0,0,1,9,5,0,0,0},
					{0,9,8,0,0,0,0,6,0},
					{8,0,0,0,6,0,0,0,3},
					{4,0,0,8,0,3,0,0,1},
					{7,0,0,0,2,0,0,0,6},
					{0,6,0,0,0,0,2,8,0},
					{0,0,0,4,1,9,0,0,5},
					{0,0,0,0,8,0,0,7,9}};

	// Solves sudoku from ith row
	bool ans = solve(mat, 0, 0);

	if(ans) print(mat);

	return 0;
}
		