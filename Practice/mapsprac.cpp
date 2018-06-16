#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    map<string,int> marks;
    int n,q,y;
    string stu;
    cin >> n;
    
    for(int i=0; i<n; ++i){
        cin >> q;
        switch(q){
            case 1:
                cin.ignore();
                scanf("%s %d", &stu, &y);
                cout << stu << " " << y << endl;
        }
    }
    
    return 0;
}
