#include <iostream>
#include <vector>
using namespace std;

long dp[251][51] = {};
bool calculated[251][51] = {false};

long getWays(long n, vector < long > c, long m){
    if(n == 0) return 1;
    if(calculated[n][m] == true) return dp[n][m];
    
    if(m > c.size()-1) return 0;
    long ways = 0;

    long div = n/c[m];


    for(long i=0; i<=div; ++i){
        long bal = n - i*c[m];
        ways += getWays(bal, c, m+1);
    }

    dp[n][m] = ways;
    calculated[n][m] = true;
    return ways;

}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    long ways = getWays(n, c, 0);
    cout << ways;
    return 0;
}