// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include "LL.h"
using namespace std;


void cycleDetRem(Node* &head){
	if(head == NULL || head->next == NULL) return;

	//Cycle detection
	Node* slow_p = head;
	Node* fast_p = head;
	while(slow_p && fast_p->next){
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if(slow_p == fast_p) break;
	}
	if(slow_p != fast_p) return;

	//Cycle Removal
	Node* temp = head;
	Node* last = NULL;
	while(temp != slow_p){
		temp = temp->next;
		last = slow_p;
		slow_p = slow_p->next;
	}

	//Removing link which causing cycle
	last->next = NULL;
}

int main(){
	Node* head = NULL;
	takeInputLL(head);
	printLL(head);
	head->next->next->next->next = head->next;
	// printLL(head);
	//Detect cycle, get meeting node and remove cycle
	cycleDetRem(head);
	printLL(head);

	return 0;
}
		