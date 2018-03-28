/*																						Submitted By : DEEPAK YADAV 

Question 5:

(LINKEDLIST): N people have decided to elect a leader by arranging themselves in a circle
and eliminating every Mth person around the circle, closing the ranks as each person drops
out. Find which person will be the last one remaining (with rank 1).

*/
#include<iostream>
#include<cstdlib>
using namespace std;

struct Node
{
    int element;
    struct Node *next;
    
};

void push(Node *&head,Node *&last,int e)
/*   			
	objective: creates a new node and links it to the previous node if any otherwise creates a head node 
	input parameters: none
	output value: none	
	approach: check whether if the head is there or not, if yes it creates a new node and assigns it with the data
			  and links it to the previous node, otherwise it assigns the new node as head.
*/
{			
	if(head==NULL)	
	{
		Node *temp = new Node;
		temp->element=e;
		temp->next=NULL;
		head=temp;
		last=temp;
	
	}
	
	else
	{
		Node *temp = new Node;
		temp->element=e;
		temp->next=NULL;
		last->next=temp;
		last=temp;
	
	}
}

//Prints the linked list
int Print(struct Node *current)
{
	if(current==NULL)
		cout<<"\nThe list is Empty..";	
	else
	{
	
		while(current!=NULL)
		{	
			if(current->next!=NULL)
				cout<<current->element<<"->";
			else
				cout<<current->element;
			current=current->next;
		}
	}	
}

void remove_node(struct Node **head,int index)
/*   			
	objective: removes the node at a given index by traversing the list & changes the head of the list to index next to the deleted node 
	input parameters: none
	output value: the subsequent person removed at each step	
	approach: two pointers are used to traverse the list so as to link the list after deleting the node at the desired index and subsequently 
			  changes the head of the list to index next to the deleted node to avoid any ambiguity the next time this function is called 
			  (as the need to update the index is ruled out as soon as the head is changed) 
*/
{
	
	struct Node *traverse=*head, *traversePrev=*head;
	int i;
	
	for(i=1;i<index;i++)
		traverse=traverse->next;
		
	for(i=1;i<index-1;i++)
		traversePrev=traversePrev->next;
	
	traversePrev->next=traverse->next;
	
	//head of the current list is updated to the next of the deleted node
	*head=traverse->next;
	cout<<"\n\nRANK OF PERSON ELIMINATED :\t "<<traverse->element;
	free(traverse);
}

int main()
/*   			
	objective: to choose a leader by eliminating every mth person in a circle until only one person remains 
	
	input parameters: 
		n: no of elements to be inserted in the list
		m: rank of the person to be eliminated
		
	output value: list denoting the ranks of the people and finally the rank of the leader is displayed	
	
	approach: every mth node is deleted till only 1 remains by calling the remove_node function n-1 times
*/
{
	Node *head=NULL;
	Node *last=NULL;
	int n,m;
	cout<<"\n\nENTER THE NO. OF PERSONS :\t";
	cin>>n;
	cout<<"\n\nRANK OF THE PERSON TO BE ELIMINATED :\t";
	cin>>m;
	for(int i=1;i<=n;i++)
	{
		push(head,last,i);
	}
	cout<<"\n\nTHE LIST CONTAINS : \t";
	Print(head);
	
	//makes the list circular
	last->next=head;
	
	for(int j=1;j<n;j++)
	{	
		remove_node(&head,m);
	}
	head->next=NULL;
	cout<<"\n\n\nTHE LEADER OF THE GROUP IS THE PERSON WITH RANK ";
	Print(head);
	
}
