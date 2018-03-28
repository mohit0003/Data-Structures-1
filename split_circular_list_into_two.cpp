/*																					Submitted By : DEEPAK YADAV 

Question 4:

(LINKEDLIST): Split a circular linked list into two equal parts circular linked lists. If the
number of nodes in the list are odd then make first list with one extra node than second list.

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
void Print(struct Node *current)
{
	if(current==NULL)
		cout<<"\nThe list is Empty..";	
	else
	{
		cout<<"\nThe list contains: ";
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

void split_circular_list(struct Node *head,struct Node **list1,struct Node **list2)
/*   			
	objective: splits a circular linked list  
	input parameters: none
	output value: none	
	approach: two pointers (one fast and one slow) are initialised to the head of the list such that the fast pointer moves 2 steps 
			  whereas the slow pointer moves a single step iteratively till the next (or next of next ) of fast ptr is head  
*/
{	
	if(!head)
		return;

	struct Node *fast_ptr=head,*slow_ptr=head;
	
	while(fast_ptr->next!=head && fast_ptr->next->next!=head) 
	{
		fast_ptr=fast_ptr->next->next;
		slow_ptr=slow_ptr->next;
	}
	
	//if the next of fast pointer is head then change it to NULL otherwise change the next of next of fast pointer to NULL
	fast_ptr->next==head ? fast_ptr->next=NULL : fast_ptr->next->next=NULL;
	
	//initialises the pointer of list1 with head
	*list1=head;
	
	//initialises the pointer of list2 with next of slow pointer ---- so that in case the no of elements are odd, list1 gets an extra element
	*list2=slow_ptr->next;
	slow_ptr->next=NULL;	
}

int main()

/*   			
	objective: to split a circular linked list into two equal parts circular linked lists 
	
	input parameters: 
		n: no of elements to be inserted in the list
		num: elements that are to be inserted in the list
		
	output value: list before split and its sublists after split	
	
	approach: an iterative function is called to split the circulalr list
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

	cout<<"\n\nCURRENT LIST!\n\t";
	Print(head);
	
	//Makes the linked list circular
	last->next=head;
	
	struct Node *list1=NULL, *list2=NULL;
	split_circular_list(head,&list1,&list2);
	cout<<"\n\nSUBLIST 1!\n\t";
	Print(list1);
	cout<<"\n\nSUBLIST 2!\n\t";
	Print(list2);
	return 0;
}
