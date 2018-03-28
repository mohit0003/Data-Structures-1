#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

class queue
{
	private:
		struct node *front;
	public:
		queue()	//constructor
		{
			front=NULL;
		}
		
		void push();
		void pop();
		void show();
		void peek();
		void isEmpty();
};

void queue::push()
{
	int value;
	struct node *ptr, *traverse;
	traverse=front;
	ptr = new node;
	cout<<"\nEnter the value to be inserted :";
	cin>>value;
	if(front==NULL)
	{
		ptr->data=value;
		ptr->next=front;
		front=ptr;
	}
	else
	{
		while(traverse->next!=NULL)
			traverse=traverse->next;
		ptr->data=value;
		ptr->next=NULL;
		traverse->next=ptr;
	}
}

void queue::pop()
{
	struct node *temp;
	if(front==NULL)
	{
		cout<<"The list is Empty..";
		return;
	}
	temp=front;
	front=temp->next;
	cout<<"\nThe item popped out is "<<temp->data;
	delete temp;
}

void queue::show()
{
	struct node *temp1=front;
	if(front==NULL)
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

void queue::peek()
{
	if(front==NULL)
	{
		cout<<"\nThe list is empty..";
		return;
	}
	
	cout<<"\nThe element at the front of the queue is "<<front->data;
}

void queue::isEmpty()
{
	if(front==NULL)
	{
		cout<<"\nThe queue is empty..";
		return;
	}
	
	cout<<"\nThe queue is not empty";
}

int main()

{

    queue s;

    int choice;

    while(1)

    {

        cout<<"\n-----------------------------------------------------------";

        cout<<"\n\t\tQUEUE USING LINKED LIST\n\n";

        cout<<"1:PUSH\n2:POP\n3:DISPLAY QUEUE\n4:PEEK\n5.IS THE QUEUE EMPTY?\n6:EXIT";

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



