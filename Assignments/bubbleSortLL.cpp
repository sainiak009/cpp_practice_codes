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
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << endl;
	return;
}

void takeInputLL(Node* &head, int arr[], int n){
	
	for(int i=n-1; i>=0; --i){
		Node* newNode = new Node(arr[i]);
		addToFront(head, newNode);
	}
}

//Bubble Sort for Linked Lists
void bubbleSortLL(Node* &head){
	if(head == NULL || head->next == NULL) return;

	int swapped = 1;

	while(swapped){
		swapped = 0;
		Node* temp = head;
		while(temp && temp->next){
			if(temp->data > temp->next->data){
				int t = temp->data;
				temp->data = temp->next->data;
				temp->next->data = t;
				swapped = 1;
			}
			temp = temp->next;
		}

	}

	return;
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;++i) cin >> arr[i];

	Node* head = NULL;
	takeInputLL(head, arr, n);

	
	bubbleSortLL(head);
	printLL(head);
	return 0;
}
		