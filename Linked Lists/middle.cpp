// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include "LL.h"
using namespace std;


void reverseLL(Node* &head){
	if(head	== NULL || head->next == NULL) return;

	Node* curr = head;
	Node* prev = NULL;
	Node* ahead = NULL;
	while(curr){
		ahead = curr->next;
		curr->next = prev; //Link reversed
		prev = curr;
		curr = ahead;
	}

	head = prev;

}

Node* LLDup(Node* head){
	if(head == NULL) return NULL;
	Node* head2 = NULL;

	while(head){
		Node* newNode = new Node(head->data);
		addToFront(head2, newNode);
	}

	reverseLL(head2);

}

int main(){
	Node* head = NULL; //Initiating linked list

	takeInputLL(head); //Populating linked list

	Node* head2 = LLDup(head);

	return 0;
}
		