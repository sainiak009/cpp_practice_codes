#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int q;
    cin >> n >> q;

    vector< pair<int,int> > t_p(n);
    for(int t_i = 0; t_i < n; t_i++){
       cin >> t_p[t_i].first;
    }

    for(int p_i = 0; p_i < n; p_i++){
       cin >> t_p[p_i].second;
    }

    vector< pair<int,int> > queries_1(q);
    for(int i=0; i<n; ++i){
        queries_1[i].first = 0;
        queries_1[i].second = 0;
    }
    for(int a0 = 0; a0 < q; a0++){
        int _type;
        int v;
        cin >> _type >> v;

        if(_type == 1){
            int i;
            vector< pair<int,int> >::iterator low = lower_bound(queries_1.begin(), queries_1.end(),make_pair(v,0));
            if(low == queries_1.end()) i = 0;
            else{
                 int k = low - queries_1.begin();
                 i = queries_1[k].second;
            }
            
            while(v > t_p[i].second && i < n) ++i; //this process is repetitive for each query
            

            if(i == n) cout << -1 << endl;
            else{
                cout << t_p[i].first << endl;
                pair<int,int> temp(v, t_p[i].first);
                queries_1[a0] = temp;
                for(int i = a0; i>0; --i){
                    if(queries_1[i].first < queries_1[i-1].first) swap(queries_1[i],queries_1[i-1]);
                    else break;
                }
            }


        }
        else{
            vector< pair<int,int> >::iterator j;
            j = upper_bound(t_p.begin(), t_p.end(), make_pair(v, 0));
            
            int k = j - t_p.begin();
            if(k > 0 && t_p[k-1].first == v) k = k-1;
            int max_element = -1;
            for(int i=k; i<n; ++i){
                if(t_p[i].second > max_element)
                    max_element = t_p[i].second;
            }
            cout << max_element << endl;
        }
    }
    return 0;
}
