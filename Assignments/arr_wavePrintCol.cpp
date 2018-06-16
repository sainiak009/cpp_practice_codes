// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

void wavePrint(int** arr, int row, int col, int curr_col){

	// int bottomBound = row;
	int rightBound = col;

	if(curr_col > rightBound){
		cout << "END";
		return;
	}

	int i;
	for(i=0; i<=row; ++i){
		cout << arr[i][curr_col] << ", ";
	}
	++curr_col;


	if(curr_col > rightBound){
		cout << "END";
		return;
	}
	for(int j=i-1; j>=0 ; --j){
		cout << arr[j][curr_col] << ", ";
	}

	wavePrint(arr, row, col, ++curr_col);
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
		