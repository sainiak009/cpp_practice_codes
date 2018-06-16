// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include "LL.h"
using namespace std;

class Stack{
	Node* head;
public:
	Stack(){
		head = NULL;
	}

	bool is_empty(){
		if(head == NULL) return true;
		return false;
	}

	void push(int num){
		Node * newNode = new Node(num);
		if(head == NULL){
			head = newNode;
			return;
		}
		newNode->next = head;
		head = newNode;
		return;
	}

	int pop(){
		int temp = head->data;
		Node * tempNode = head;
		head = head->next;
		delete tempNode;
		return temp;
	}

	int top(){
		return head->data;
	}

	void printLL(){
		Node* temp = head;

		while(temp != NULL){
			cout << "--->" << temp->data;
			temp = temp->next;
		}

		cout << endl;
		return;
	}

};


void putAtBotton(Stack &s, int num){
	if(s.is_empty()){
		s.push(num);
		return;
	}

	int top = s.pop();
	putAtBotton(s, num);
	s.push(top);
}

void inverseStack(Stack &s){
	if(s.is_empty()) return;

	int top = s.pop();
	inverseStack(s);
	putAtBotton(s,top);
}

int main(){
	int n;
	Stack s;
	while(cin >> n && n != -1){
		s.push(n);
	}
		
	s.printLL();

	inverseStack(s);
	s.printLL();
	return 0;
}
		