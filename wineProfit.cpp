// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include <algorithm>
using namespace std;

//Returns maximum profit possible for index between be and en
int maxProfit(int arr[], int be, int en, int year){
	if(be==en) return arr[be]*year;

	int leftProfit = arr[be]*year + maxProfit(arr, be+1, en, year+1);
	int rightProfit = arr[en]*year + maxProfit(arr, be, en-1, year+1);
	int result = max(leftProfit, rightProfit);
	return result;
}

int main(){
	int m;
	cin >> m;
	int arr[m];

	for(int i=0; i<m ; ++i) cin >> arr[i];

	//Returns maximum profit possible for index between be and en
	cout << maxProfit(arr, 0, m-1, 1);
	return 0;
}
		