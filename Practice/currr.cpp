#include <bits/stdc++.h>
#include <limits>
#include <cmath>

using namespace std;

long maxCurr = -1;
long mod = 1000000007;
void currencies(int n, long x, int s, int f, int m, vector < vector<long> > A) {
   if(m==0 && s==f){
        if(x > maxCurr) maxCurr = x;
        return;
   }
   if(m==0) return;

   for(int i=0; i<n; ++i){
        if(i!=s)currencies(n, (x*A[s][i])%mod, i, f, m-1, A);
   }
}

int main() {
    int n;
    cin >> n;
    long x;
    int s;
    int f;
    int m;
    cin >> x >> s >> f >> m;
    vector< vector<long> > A(n,vector<long>(n));
    for(int A_i = 0;A_i < n;A_i++){
       for(int A_j = 0;A_j < n;A_j++){
          cin >> A[A_i][A_j];
       }
    }

    currencies(n, x, s, f, m, A);

    cout << maxCurr;
    return 0;
}
