#include <bits/stdc++.h>

using namespace std;

int traderProfit(int k, int n, vector <int> A) {
    int profit[k+1][n+1];
    
    //Populating base cases
    for (int i = 0; i <= k; i++)
        profit[i][0] = 0;
 
    for (int j= 0; j <= n; j++)
        profit[0][j] = 0;
 
    // bottom-up approach
    for (int i = 1; i <= k; i++){

        int prevMax = INT_MIN;
        for (int j = 1; j < n; j++){

            prevMax = max(prevMax,profit[i-1][j-1] - A[j-1]);
            profit[i][j] = max(profit[i][j-1],A[j] + prevMax);
        }
    }
 
    return profit[k][n-1];
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        int result = traderProfit(k, n, arr);
        cout << result << endl;
    }
    return 0;
}
