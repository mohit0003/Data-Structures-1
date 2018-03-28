#include <iostream>

#include <cstdlib>


#define SIZE 10



using namespace std;



class queue 
	/*   			

	objective: Create a class to implement Queue(circular) using dynamically created array 

	input parameters: none

	output value: none

	description:  Class definition

	approach: Class definition provides data member and member functions for the Queue class

	*/


{

	int *arr;			// array to store queue elements

	int capacity;			// maximum capacity of the Q

	int front;			// front points to front element in the Q

	int rear;			// rear points to last element in the Q

	int count;			// current size of the Q



public:

	queue(int size = SIZE)		// constructor
	{
		arr = new int[size];
		capacity = size;
		front = 0;
		rear = 0;
		count = 0;
	}
	~queue()				//destructor
	{
		delete []arr;
	}	

	void dequeue();

	void enqueue(int);

	int peek();  				// returns front element

	int size();				// returns current size of Q

	bool isEmpty();

	bool isFull();

};


	

void queue::dequeue()
{	
	if(count==0)
		cout<<"\nQueue Underflow!";
	else
	{
		front=(front+1)%capacity;
		count-=1;
	}
}

void queue::enqueue(int ele)
{
	if(count==capacity)
	{
		cout<<"\nQueue Overflow!";
	
	}

	else
	{
		arr[rear]=ele;
		rear=(rear+1)%capacity;	
		count+=1;	
	}
}

int queue::peek()
{
	if(count==0)
	{	cout<<"\nQueue is Empty...";
		return 0;
	}
	else
		return arr[++front];
}

int queue::size()
{
	return count;
}

bool queue::isFull()
{
	if(count==capacity)
		return true;
	else
		return false;
}

bool queue::isEmpty()
{
	if(count==0)
		return true;
	else
		return false;
}

int main()
{
   queue q;
   int n,value;
   cout<<"\n Press \n 1. Push\n 2. Pop\n 3. Peek \n 4. Size\n 5. Is Empty?\n 6. Is Full?\t";
   cin>>n;
   
   switch(n)
   {
      case 1:
	cout<<"\nEnter the value to be inserted:\t";
	cin>>value;
	q.enqueue(value);
	break;

      case 2:
	cout<<"\nThe value that is popped is: "<<q.peek();
	q.dequeue();
	break;

      case 3:
	cout<<"\nThe Value at the top of the stack is: "<<q.peek();
	break;

      case 4:
	cout<<"\nThe size of the stack is: "<<q.size();
	break;

      case 5:
	if(q.isEmpty()==true)
	   cout<<"\nThe stack is empty. ";
	else
	   cout<<"\nThe stack if not empty. ";
	break;

      case 6:
	if(q.isFull()==true)
	   cout<<"\nThe stack is full. ";
	else
	   cout<<"\nThe stack if not full. ";
	break;
   }

}


