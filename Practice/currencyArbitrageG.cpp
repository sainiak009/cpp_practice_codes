#include <bits/stdc++.h>
#include <limits>
#include <cmath>

using namespace std;

int mod = 1000000007;
double currencies(int n, int x, int s, int f, int m, vector < vector<double> > A) {
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            if(i!=j) A[i][j] = -log(A[i][j]);

    vector <double> V(n);
    for(int i=0; i<n; ++i)
        V[i] = numeric_limits<double>::infinity();
    V[s] = 0;

    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            for(int k=0; k<n; ++k){
                if(j != k){
                    V[k] = min( V[k], V[j] + A[j][k] );
                }
            }

    double temp = V[f];
    temp = exp(abs(temp));
    return temp*x;
}

int main() {
    int n;
    cin >> n;
    int x;
    int s;
    int f;
    int m;
    cin >> x >> s >> f >> m;
    vector< vector<double> > A(n,vector<double>(n));
    for(int A_i = 0;A_i < n;A_i++){
       for(int A_j = 0;A_j < n;A_j++){
          cin >> A[A_i][A_j];
       }
    }

    cout << currencies(n, x, s, f, m, A);
    return 0;
}
