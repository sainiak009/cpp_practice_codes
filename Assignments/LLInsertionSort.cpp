// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;
int INT_MIN = -99999;

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
	int n,x;
	cin >> n;

	for(int i=0; i<n; ++i){
		cin >> x;
		Node* newNode = new Node(x);
		addToFront(head, newNode);
	}
}

Node * insertionSort(Node* head){
	if(head==NULL) return NULL;

	Node* sortedHead = NULL;
	Node* sortedPrev = new Node(INT_MIN);
	Node* current = head;

	sortedHead = new Node(head->data);
	sortedPrev->next = sortedHead;
	current = current->next;
	Node* temp = NULL;

	while(current != NULL){

		temp = sortedPrev;
		
		while( (temp->next != NULL) && (current->data < temp->data))
		{	
			temp = temp->next ;
		}

		Node * next = temp->next;
		temp->next = new Node(current->data);
		temp->next->next = next;

		current = current->next;
	}

	return sortedHead;
}

int main(){
	Node* head = NULL;

	takeInputLL(head);
	printLL(head);

	Node* sorted = insertionSort(head);

	printLL(sorted);
	return 0;
}
		