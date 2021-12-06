//Intersection of two Sorted Linked List.


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

	newnode->next = (*head);

	*head = newnode;
}

Node* intersection(Node* first, Node* second){


   Node dummy;

   Node* tail = &dummy;

   dummy.next = NULL;

	while(first != NULL && second != NULL){
		if(first->data == second->data){

			push(&(tail->next),first->data);
			tail = tail->next;
			first = first->next;
			second = second->next;
		}
		else if(first->data < second->data) first = first->next;

		else  second = second->next;

	}

	return(dummy.next);


}

void display(Node* head){

	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}

	cout<<"\n";	
}

int main(){

  Node* first = NULL;
    Node* second = NULL;
    Node* head = NULL;
 
    /* Let us create the first sorted
     linked list to test the functions
     Created linked list will be
     1->2->3->4->5->6 */
    push(&first, 6);
    push(&first, 5);
    push(&first, 4);
    push(&first, 3);
    push(&first, 2);
    push(&first, 1);
 
    /* Let us create the second sorted linked list
   Created linked list will be 2->4->6->8 */
    push(&second, 8);
    push(&second, 6);
    push(&second, 4);
    push(&second, 2);
    head = intersection(first,second);

    display(head);

}