
#include<iostream>
#include<conio.h>
using namespace std;
#include<stack>

stack <int> myStack;
int main()
{
	int n;
	double item;
	cout<<"\nNo of elements:\t";
	cin>>n;
	
	cout<<"\nEnter the elements:\t";
	for(int i=0;i<n;i++)
	{
		cin>>item;
		myStack.push(item);
	}
	
	cout<<"\nReversed Elements:\t";
	while(!myStack.empty())
	{
		cout<<myStack.top();
		myStack.pop();
		
	}
	
	getch();
	return 0;
}
