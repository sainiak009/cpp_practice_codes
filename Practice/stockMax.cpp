// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

//1 : Nothing
//2 : Buy
//3 : Sell

long stockMax(int *prices, int be, int en){
	int maxSoFar = 0;
	long profit = 0;
	for(int i=en; i>=be; --i){
		if(prices[i] > maxSoFar) maxSoFar = prices[i];
		profit += maxSoFar - prices[i];
	}

	return profit;

}

int main(){
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		int prices[n],actions[n];

		for(int i=0; i<n; ++i){
			cin >> prices[i];
		}

		//Prints all combiantions of options available to sell or purchase from index be
		long ans = stockMax(prices, 0,n-1);

		cout << ans << endl;
	}

	return 0;
}
		