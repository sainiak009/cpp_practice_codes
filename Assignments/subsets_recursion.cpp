#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> result;
int cnt = 0;

bool compareStr(const string& A, const string& B){
	return A.size() < B.size();
}

//Prints all numbers whose sum is K starting from index be
void subsets(int arr[], int be, int en, int k, char decisionSoFar[], int i){
	if(be > en){
		if(decisionSoFar[0] == 0) return;
		decisionSoFar[i] = '\0';
		string s = decisionSoFar;
		if(k==0){
			++cnt;
			result.push_back(s);
		}
		return;
	}
	
	subsets(arr, be+1, en, k, decisionSoFar, i);
	if(k >= arr[be]){
		decisionSoFar[i] = arr[be] + '0';
		int bal = k - arr[be];
		subsets(arr, be+1, en, bal, decisionSoFar, i+1);
	}
}

int main(){
	int n, k;
	cin >> n;
	int inp[n];
	for(int l=0; l<n; ++l){
		cin >> inp[l];
	}

	cin >> k;
	//Prints all numbers whose sum is K starting from index be
	char decisionSoFar[21];
	decisionSoFar[0] = 0;
	subsets(inp, 0, n-1, k, decisionSoFar, 0);

	sort(result.begin(), result.end(), compareStr);

	for(int m = 0; m <= cnt; ++m){
		for(int x = result[m].length()-1; x>=0; --x ) cout << result[m][x] << " ";
			cout << endl;
	}
}
