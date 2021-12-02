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

void removeDuplicate(Node* head){

	Node* n_temp = head;


	if(n_temp == NULL) cout<<"\nUnderflow\n";

	Node* temp;

	while(n_temp->next != NULL){
		if(n_temp->data == n_temp->next->data){
			temp = n_temp->next->next;
			free(n_temp->next);
			n_temp->next = temp; 
		}

		else n_temp = n_temp->next;
	}

	
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

push(&head,1);
push(&head,2);
push(&head,2);
push(&head,3);
push(&head,3);


display(head);

removeDuplicate(head);

display(head);

}