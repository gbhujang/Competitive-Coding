//Rotate a Doubly Linked list in group of Given Size.[Very IMP]
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	char data;
	Node* prev;
	Node* next;
};

void push(Node** head, int data){

	Node* newnode = new Node();

	newnode->data = data;

	newnode->next = (*head);

	newnode->prev = NULL;

	if((*head) != NULL) (*head)->prev = newnode;

	(*head) = newnode;

}

Node* rotateDLL(Node* head, int k){

	head->prev = NULL;

	Node* current = head;
	Node* newHead;
	Node* temp;
	int count = 0;

	while(current != NULL && count < k){
		newHead = current;
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
		count++;
	}
	if(count >= k){
		Node* rest = rotateDLL(current,k);
		head->next = rest;
		if(rest != NULL){
			rest->prev = head;
		}
	}

	return newHead;
}


void printList(Node* head){

	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<"\n";
}


int main(){

	Node* head = NULL;

	push(&head,'e');
	push(&head,'d');
	push(&head,'c');
	push(&head,'b');
	push(&head,'a');

	cout<<"Before Rotation"<<endl;
	printList(head);

	int n;

	cin>>n;

	Node* temp = head;
	head = rotateDLL(head,n);

	if(head != NULL){
	cout<<"After Rotation"<<endl;
	 printList(head);
	}
	else printList(temp);


}