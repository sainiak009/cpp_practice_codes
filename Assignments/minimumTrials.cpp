#include <iostream>
using namespace std;


//Prints no. of mini trials needed for given no. of plates and floors
void minTrials(int k, int f, int trials){
	
}

int main(){
	int t;
	cin >> t;
	int input[t][2], trials;
	for(int i=0; i<t; ++i){
		cin >> input[i][0] >> input[i][1];
	}

	for(int j=0; j<t; ++j){
		//Prints no. of mini trials needed for given no. of plates and floors
		trials = 0;
		minTrials(input[j][0], input[j][1], trials);
	}
	return 0;
}