// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;


class Node{
public:
	int data;
	Node * next; // self refrencial class
	
	Node(int num){
		data = num;
		next = NULL; //NULL is a macro
	}
}

Node * tail = new Node(0);
Node* takeInput(int n){
	//take n numbers and add each successive number to the front of LL
	Node *ele = new Node(n);
	ele->next = pntr;
	pntr = ele;
	return ele;
}

void print(Node* head){

}

int main(){
	int n;
	cin >> n;
	
	Node ll = takeInput(n);
	return 0;
}
		