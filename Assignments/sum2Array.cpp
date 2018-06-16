// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include <vector>
using namespace std;


vector<int> ans;

void sum2Array(int arr1[], int en1, int arr2[], int en2, int carryOver){
	if(en1 < 0 && en2 < 0) return;

	if(en1 >= 0 && en2 >= 0){
		int k = arr1[en1] + arr2[en2] + carryOver;
		int x = k%10;
		int y = k/10;
		if(y >= 0) sum2Array(arr1, --en1, arr2, --en2, y);
		ans.push_back(x);
		return;

	}

	while(en1 >= 0){
		ans.push_back(arr1[en1]);
		--en1;
	}

	while(en2 >= 0){
		ans.push_back(arr2[en2]);
		--en2;
	}

	return;
}

int main(){
	int n,m;
	cin >> n;
	int arr1[n];
	for(int i=0; i<n; ++i) cin >> arr1[i];

	cin >> m;
	int arr2[m];
	for(int j=0; j<m; ++j) cin >> arr2[j];

	//Print sum of last entries
	sum2Array(arr1, n-1, arr2, m-1, 0);

	for(vector<int>::iterator it = ans.begin(); it != ans.end(); ++it){
		cout << *it << ", ";
	}
	cout << "END";

	return 0;
}
		