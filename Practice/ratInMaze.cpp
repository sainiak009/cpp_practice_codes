#include <iostream>
using namespace std;
int N, M;
int path[10][10];

//prints 2D char array
void printChar(char board[][10]){
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j) cout << board[i][j] << " ";
            cout << endl;
    }
}

//prints 2D int array
void printInt(int board[][10]){
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j) cout << board[i][j] << " ";
            cout << endl;
    }
}



bool ratInMaze(char maze[][10], int x, int y){
	if(x == N-1 && y == M-1 ){
		path[x][y] = 1;
		return true;
	}

	//checks if box is safe
	if(maze[x][y] == 'X') return false;

	//Places rat there
	path[x][y] = 1;

	//checks if right path is safe
	if(y < M){
		if(ratInMaze(maze, x, y+1)) return true;
	} 

	//checks if down path is safe
	if(x < N){
		if(ratInMaze(maze, x+1, y)) return true;
	}

	//No path is safe // Backtrack and return flase
	path[x][y] = 0;

	return false; 

}



int main(){
	char maze[][10] = {
		"0000XX",
        "X0XX0X",
        "X000X0",
        "00X000"
    };

    N = 4;
    M = 6;

	//Solves the maze  starting from cell x,y
	bool solved = ratInMaze(maze, 0, 0);

	if(solved){
		printChar(maze);
		cout << endl << endl;
		printInt(path);
	}else{
		cout << "No path";
	}
}