#include <iostream>
#include <set>
using namespace std;


int main() {
    int n,x,q;
    set<int> s;
    set<int>::iterator it;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> q >> x;
        switch(q){
            case 1:
                s.insert(x);
                break;
            case 2:
                s.erase(x);
                break;
            case 3:
                it = s.find(x);
                if(it == s.end()) cout << "No" << endl;
                else cout << "Yes" << endl;
                break;
        }
        
    }  
    return 0;
}
