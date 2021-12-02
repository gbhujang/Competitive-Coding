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
	Node* temp, *temp1, *dup;

	temp = head;

	while(temp != NULL && temp->next != NULL){
		temp1 = temp;

		while(temp1->next != NULL){
			if(temp->data == temp1->next->data){
				dup = temp1->next;
				temp1->next = temp1->next->next;
				delete(dup);
			}
			else temp1 = temp1->next;
		}
		temp = temp->next;
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
push(&head,3);
push(&head,4);
push(&head,3);
push(&head,4);
push(&head,4);
push(&head,4);
push(&head,4);
push(&head,4);
push(&head,4);
push(&head,4);
push(&head,4);

display(head);

removeDuplicate(head);

display(head);


}