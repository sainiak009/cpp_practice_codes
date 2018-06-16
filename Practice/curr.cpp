#include <bits/stdc++.h>

using namespace std;

long long buyMaximumProducts(int n, long long k, vector <int> a) {
    long long stocks = 0;

    vector< pair <int,int> > vect;

    for (int i=0; i<n; i++)
        vect.push_back( make_pair(a[i], i+1));

    sort(vect.begin(), vect.end());

    for(int i=0; i<n; ++i){
        k = k - vect[i].second*vect[i].first;
        if(k >= 0) stocks += vect[i].second;
        else{
            int x = ceil((double)abs(k)/(double)vect[i].first);
            stocks += vect[i].second-x;
            return stocks;
        }
    }

    return stocks;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    long long k;
    cin >> k;
    long long result = buyMaximumProducts(n, k, arr);
    cout << result << endl;
    return 0;
}
