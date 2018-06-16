// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node *next;

	Node(int num){
		data = num;
		next = NULL;
	}
};

void addToTail(Node* &head, Node* nodeToAdd){
	if(head == NULL){
		head = nodeToAdd;
		return;
	}	

	Node* last = head;
	while(last->next) last = last->next;
	last->next = nodeToAdd;
}

void printLL(Node* head){
	Node* temp = head;

	while(temp != NULL){
		cout << "--->" << temp->data;
		temp = temp->next;
	}

	cout << endl;
	return;
}

void takeInputLL(Node* &head){
	// cout << "Enter numbers for LL(-1 to terminate input) :";
	int n;

	while(cin>>n && n!=-1){
		Node* newNode = new Node(n);
		addToTail(head, newNode);
	}
}

void kthlastLL(Node* head, int k){
	Node* slow = head;
	Node* fast = head;

	for(int i=0; i<k-1; ++i){
		if(fast->next) fast = fast->next;
		else return;
	}

	while(fast->next){
		fast = fast->next;
		slow = slow->next;
	}

	cout << slow->data << endl;
}

int main(){
	Node* head = NULL;
	takeInputLL(head);
	int k;
	cin >> k;

	kthlastLL(head, k);
	return 0;
}
		