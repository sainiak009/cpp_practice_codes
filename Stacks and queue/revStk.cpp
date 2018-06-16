// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include <stack>
using namespace std;

void putAtBotton(stack<int> &s, int num){
	if(s.empty()){
		s.push(num);
		return;
	}

	int top = s.top();
	s.pop();
	putAtBotton(s, num);
	s.push(top);
}

void inverseStack(stack<int> &s){
	if(s.empty() == true) return;

	int top = s.top();
	s.pop();
	inverseStack(s);
	putAtBotton(s,top);
}


int main(){
	stack<int> s;
	int n;
	int x;
	cin >> n;

	switch(n){
		case 0:
			cout << endl;
			return 0;
		case 1:
			cin >> x;
			cout << x << endl;
			return 0;
	}

	for(int i=0; i<n; ++i){
		cin >> x;
		s.push(x);
	}

	inverseStack(s);

	for(int i=0; i<n; ++i){
		cout << s.top() << endl;
		s.pop();
	}

	return 0;
}
		