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

	cout << endl;
	return;
}

void takeInputLL(Node* &head){
	int n;
	while(cin>>n && n!=-1){
		Node* newNode = new Node(n);
		addToFront(head, newNode);
	}
}

void deleteLL(Node * head, int index){
	Node * temp = head;
	if(index == 0){
		head = head->next;
		delete temp;
		return;
	}


}

int main(){

	return 0;
}
		