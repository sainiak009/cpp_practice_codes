// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include <utility>
#include <climits>
using namespace std;

unsigned long long int dp[100] = {};

unsigned long long int multiplyIt(long x){
	if(dp[x] != 0) return dp[x];
	if(x==1) return 1;
	dp[x] = x*multiplyIt(x-1);
	cout << dp[x] << endl;
	return dp[x];
}

int countScore(unsigned long long int num){
	int sum = 0;
	int zeroes = 0;
	int temp;
	while (num != 0){
		temp = num % 10;
		if(temp == 0) ++zeroes;

       	sum = sum + temp;
       	num = num / 10;
    }
    cout << sum	<< " " << zeroes << endl;
    return sum - zeroes;
}

int main(){
	int t;
	cin >> t;
	int i = 1;
	pair<int,int> p, winner, runnerUp;
	winner.first = INT_MIN;
	runnerUp.first = INT_MAX;	
	while(i<=t){
		int n;
		cin >> n;
		unsigned long long int p = multiplyIt(n);
		cout << p << "p" << endl;
		int score = countScore(p);
		if(score > winner.first){
			winner.first = score;
			winner.second = i;
		}
		if(score < runnerUp.first){
			runnerUp.first = score;
			runnerUp.second = i;
		}

		++i;
	}

	cout << winner.second << " " << winner.first << endl;
	cout << runnerUp.second << " " << runnerUp.first << endl;  

	return 0;
}
		