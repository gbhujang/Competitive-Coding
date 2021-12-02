//Write a Program to Move the last element to Front in a Linked List.

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;
};

void push(Node** head, int data){
	
	Node* newnode = new Node();

	newnode->data = data;

	newnode->next = *head;

	*head = newnode;

}

void moveToFirst(Node** head){

	Node* last =  *head;

	Node* temp = *head;

	while(last->next != NULL) last = last->next;

	//cout<<last->data<<endl;

	while((*head)->next->next != last->next) (*head) = (*head)->next;

	// cout<<head->data<<endl;

	(*head)->next = NULL;

	(*head)= temp;

	// cout<<head->data<<endl;

	last->next = (*head);

	(*head) = last;



	// cout<<head->data<<endl;



}

void display(Node* head){

	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}

	cout<<"\n";	
}

int main(){

Node* head = NULL;

push(&head,4);
push(&head,1);
push(&head,2);
push(&head,3);

display(head);

moveToFirst(&head);

display(head);

}