#include <bits/stdc++.h>
#include <climits>

using namespace std;

double currencies(int n, int x, int s, int f, int m, vector < vector<double> > A) {
    
    // double newCurrency = x*max(currencies(newCurrency, i, f, m-1, A));
    if(m==1 && s!=f){
        return x*A[s][f];
    }
    // if(m==0 && s==f) return x;

    double nextMax = -1;
    int nextStep;
    if(m>0){
        for(int i=0; i<n; ++i){
            if(i != s){
                cout << i << " " << f << " " << m <<  endl;
                double y = currencies(n, A[s][i]*x, i, f, m-1, A);
                if(nextMax < y){
                    nextMax = y;
                    nextStep = i;
                    cout << "i" << s << "j" << nextStep << "---" <<  endl;
                }
            }
        }
        
        // cout << nextMax << endl;
        cout << A[s][nextStep] << endl;
        return x*A[s][nextStep]*nextMax;
    }
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
