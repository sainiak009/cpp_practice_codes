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

void addToFront(Node* &head, Node* nodeToAdd){
	if(head == NULL){
		head = nodeToAdd;
		return;
	}

	nodeToAdd->next = head;
	head = nodeToAdd;
}

void printLL(Node* head){
	Node* temp = head;

	while(temp != NULL){
		cout << "--->" << temp->data;
		temp = temp->next;
	}
	return;
}

void takeInputLL(Node* &head){
	cout << "Enter numbers for LL(-1 to terminate input) :";
	int n;

	while(cin>>n && n!=-1){
		Node* newNode = new Node(n);
		addToFront(head, newNode);
	}
}

int main(){
	Node* head = NULL; //Initiallizing Linked List
	
	takeInputLL(head); 
	printLL(head);
	return 0;
}
		