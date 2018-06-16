// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

void wavePrint(int** arr, int row, int col, int curr_row){

	int bottomBound = row;

	if(curr_row > bottomBound){
		cout << "END";
		return;
	}
	int i;
	for(i=0; i<=col; ++i){
		cout << arr[curr_row][i] << ", ";
	}
	++curr_row;


	if(curr_row > bottomBound){
		cout << "END";
		return;
	}
	for(int j=i-1; j>=0 ; --j){
		cout << arr[curr_row][j] << ", ";
	}

	wavePrint(arr, bottomBound, col, ++curr_row);
}

int main(){
	int m,n;
	cin >> m >> n;
	int **arr = new int*[m];

	for(int k=0; k<m; ++k){
		arr[k] = new int[n]; 
	}

	for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j){
			cin >> arr[i][j];
		}
	}

	wavePrint(arr, m-1, n-1, 0);
	return 0;
}
		