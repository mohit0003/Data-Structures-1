#include<iostream>
#include<cstdlib>
#define SIZE 100 // or const int SIZE=100;

using namespace std;

class stack
{
	/*
	objective : Create a class for implementing Stack using Array
	input parameters: none
	output value: none
	description: class definition
	approach: class defines data member and member function of the stack class
	*/

	int *arr;			// for dynamic array
	int top;
	int capacity; 

public:
	stack(int size=SIZE)		//constructor
	{  arr= new int[SIZE];
	   top=-1;
	}	
	
	void push(int &value)
	{
	   top+=1;
	   arr[top]=value;
	}

	int pop()
	{
	   int temp = arr[top];

	   top-=1;
	   return temp;
	}

	int peek()
	{
	   return arr[top];
	}

	int size()
	{
	   return top+1;
	}

	bool isEmpty()
	{
	   if(top==-1)
		return true;
	   else
		return false;
	}

	bool isFull()
	{
	   if(SIZE==top+1)
		return true;
	   else
	 	return false;
	} 

	~stack()			//destructor
	{
	   delete arr;
	}
};


int main()
{
   stack sobj;
   int n,value;
   cout<<"\n Press \n 1. Push\n 2. Pop\n 3. Peek \n 4. Size\n 5. Is Empty?\n 6. Is Full?\t";
   cin>>n;
   
   switch(n)
   {
      case 1:
	cout<<"\nEnter the value to be inserted:\t";
	cin>>value;
	sobj.push(value);
	break;

      case 2:
	cout<<"\nThe value that is popped is: "<<sobj.pop();
	break;

      case 3:
	cout<<"\nThe Value at the top of the stack is: "<<sobj.peek();
	break;

      case 4:
	cout<<"\nThe size of the stack is: "<<sobj.size();
	break;

      case 5:
	if(sobj.isEmpty()==true)
	   cout<<"\nThe stack is empty. ";
	else
	   cout<<"\nThe stack if not empty. ";
	break;

      case 6:
	if(sobj.isFull()==true)
	   cout<<"\nThe stack is full. ";
	else
	   cout<<"\nThe stack if not full. ";
	break;
   }

}

