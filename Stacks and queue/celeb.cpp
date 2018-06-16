//Deepak Aggarwal, Coding Blocks

#include <iostream>
#include <stack>
using namespace std;

bool doesKnow(int x, int y){
	static int mat[][4] = {
		{0, 0, 1, 1},
		{0, 0, 1, 0},
		{0, 0, 0, 0},
		{1, 1, 1, 1}
	};
	return mat[x][y];
}

int celeb(int N){
	// Initiating stack
	stack<int> persons;

	//Filling the stack
	for(int i=0; i<N; ++i){
		persons.push(i);
	}

	//Get top two persons to compare
	while(persons.size() > 1){
		int p1 = persons.top(); persons.pop();
		int p2 = persons.top(); persons.pop();
		if(doesKnow(p1,p2)){
			persons.push(p2);
		}else{
			persons.push(p1);
		}
	}

	return persons.top();

}

int main(){
	int N = 4;

	// Finding and printing the celebrity
	cout << celeb(N); // 2 is the celeb
}