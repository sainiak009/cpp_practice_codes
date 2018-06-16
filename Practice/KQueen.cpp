// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

const int N = 9 ;

void print(bool board[][N]){
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

bool canPlace(bool board[][N], int r, int c){
	//checking column
	for(int x = 0; x < r; ++x){
		if (board[x][c] == 1) return false;
	}

	//checking left diagonal
	for(int i = r-1, j = c-1; i >= 0 && j >= 0; --i, --j){
		if(board[i][j] == 1) return false;
	}

	//checking right disgonal
	for(int i = r-1, j = c+1; i >= 0 && j < N; --i, ++j){
		if(board[i][j] == 1) return false;
	}

	return true;
}

bool NQueen(bool board[][N], int row){
	if(row >= N) return true; //Returns true if all queens are placed

	for(int c=0; c<N; ++c){ // Iterating over columns for placing queens
		if(canPlace(board,row,c)){
			board[row][c] = 1;
			if(NQueen(board, row+1)){ //Checking if board is solvable with our placed queen
				return true;
			}
			board[row][c] = 0; //Restoring to previous state if board is not soved with placed queen
		}
	}
	//Retrun false if no place to put queen
	return false;
}

int main(){
	bool board[N][N] = {};

	//Solves and return true or false
	bool is_solved = NQueen(board, 0);
	if(is_solved) print(board);
	else cout << "Queens can't be placed on this board" << endl;
	return 0;
}
		