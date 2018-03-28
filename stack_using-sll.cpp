#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

class stack
{
	private:
		struct node *top;
	public:
		stack()	//constructor
		{
			top=NULL;
		}
		
		void push();
		void pop();
		void show();
		void peek();
		void isEmpty();
};

void stack::push()
{
	int value;
	struct node *ptr;
	ptr = new node;
	cout<<"\nEnter the value to be inserted :";
	cin>>value;
	ptr->data=value;
	ptr->next=top;
	top=ptr;
}

void stack::pop()
{
	struct node *temp;
	if(top==NULL)
	{
		cout<<"The list is Empty..";
		return;
	}
	temp=top;
	top=temp->next;
	cout<<"\nThe item popped out is "<<temp->data;
	delete temp;
}

void stack::show()
{
	struct node *temp1=top;
	if(top==NULL)
	{
		cout<<"The list is Empty..";
		return;
	}
	while(temp1!=NULL)
	{	
		if(temp1->next!=NULL)
		{
			cout<<temp1->data<<" -> ";
			temp1=temp1->next;
		}
		
		else
		{
			cout<<temp1->data;
			temp1=temp1->next;
		}
	}
}

void stack::peek()
{
	if(top==NULL)
	{
		cout<<"\nThe list is empty..";
		return;
	}
	
	cout<<"\nThe element at the top of the stack is "<<top->data;
}

void stack::isEmpty()
{
	if(top==NULL)
	{
		cout<<"\nThe stack is empty..";
		return;
	}
	
	cout<<"\nThe Stack is not empty";
}

int main()

{

    stack s;

    int choice;

    while(1)

    {

        cout<<"\n-----------------------------------------------------------";

        cout<<"\n\t\tSTACK USING LINKED LIST\n\n";

        cout<<"1:PUSH\n2:POP\n3:DISPLAY STACK\n4:PEEK\n5.IS THE STACK EMPTY?\n6:EXIT";

        cout<<"\nEnter your choice(1-4): ";

        cin>>choice;

        switch(choice)

        {

            case 1:

                s.push();

                break;

            case 2:

                s.pop();

                break;

            case 3:

                s.show();

                break;

            case 4:

                s.peek();

                break;
                
            case 5:
            	
            	s.isEmpty();
            	
            	break;
            	
            case 6:
            	
            	return 0;
            	
            	break;

            default:

                cout<<"\nPlease enter correct choice(1-6)!!";

                break;

        }

    }

    return 0;

}



