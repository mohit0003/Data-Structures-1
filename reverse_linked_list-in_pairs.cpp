/*																				Submitted By : DEEPAK YADAV 

Question 3:

(LINKEDLIST): Reverse the linked list in pairs. For example a linked list 1-> 2-> 3 -> 4 -> 5,
then after the function has been called the linked list must be 2-> 1->4 -> 3 -> 5.

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
void Print(Node *current)
{
	if(current==NULL)
		cout<<"\nThe list is Empty..";	
	else
	{
		cout<<"\nThe list contains: ";
		while(current->next!=NULL)
		{
			cout<<current->element<<" -> ";
			current=current->next;
		}
		cout<<current->element;
	}	
}

//swap the two popinters
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//swap the element of the two successive pointers
void reverse_pairs(struct Node *head)
{
    struct Node *temp = head;
 
    while (temp != NULL && temp->next != NULL)
    {
        swap(&temp->element, &temp->next->element);
        temp = temp->next->next;
    }
}

int main()
/*   			
	objective: to reverse the linked list in pairs 
	
	input parameters: 
		n: no of elements to be inserted in the list
		num: elements that are to be inserted in the list
		
	output value: list before pair reversal and after pair reversal	
	
	approach: check whether if the head is there or not, if yes it creates a new node and assigns it with the data
			  and links it to the previous node, otherwise it assigns the new node as head.
*/
{
	
	Node *head=NULL;
	Node *last=NULL;
	int num,n;
	
	cout<<"\nENTER THE NO OF ELEMENTS TO BE INSERTED IN THE LIST:";
	cin>>n;
	cout<<"\n\nENTER THE ELEMENTS(SPACE SEPERATED):";
	
	for(int i=0;i<n;i++)
	{
		cin>>num;
		push(head,last,num);
	}
	
	cout<<"\n\n\nBEFORE REVERSING PAIRS!\n";
	Print(head);
	reverse_pairs(head);
	cout<<"\n\n\nAFTER REVERSING PAIRS!\n";
	Print(head);
	return 0;
}
