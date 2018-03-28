/*																				Submitted By : DEEPAK YADAV 	

Question 2:

(QUEUE): Given a stack of integers, how do you check whether each successive pair of
numbers in the stack is consecutive or not. The pairs can be increasing or decreasing, and if
the stack has an odd number of elements, the element at the top is left out of a pair. For
example , if the stack of elements are [ 4,5,-2,-3,11,10,5,6,20] , then the output should be
true because each of the pairs (4,5), (-2,-3),(11,10) and (5,6) consist of consecutive numbers.

*/
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;

int consecutive_pairs(queue<int> q)
/*   			
	objective: returns whether each successive pair of numbers in the queue is consecutive or not 
	input parameters: none
	output value: none	
	approach: check whether the successive pairs at the front are consecutive or not recursively 
*/
{
	int num1,num2;
	
	if(!q.empty())
	{	
		num1=q.front();
		q.pop();
		num2=q.front();
		q.pop();
		if((abs(num1)==abs(num2)+1)||(abs(num1)==abs(num2)-1))
			return consecutive_pairs(q);
		else 
			return 0;	
	}
		
	else 
		return 1;

}

int main()
/*   			
	objective: to check whether each successive pair of numbers in the stack is consecutive or not 
	input parameters: 
		num: integers that are to be pushed into the stack
	output value: none	
	approach:  a recursive function is called which returns a value based on the input 
*/
{
	stack<int> st;
	queue<int> q;
	int num,response;
	char ch;
	do{
		cout<<"\nEnter a number into the stack:";
		cin>>num;
		st.push(num);
		cout<<"\nDo you wish to enter more?(Y/N)\t ";
		cin>>ch;
	}while(ch=='Y'||ch=='y');
	
	//determines the size of the stack	
	int length=st.size();
	
	//if the number of integers in the stack are odd then the last integer that is pushed is popped out 
	// and the elements of the stack are transferred into a queue in the reverse (the order doesn't matter)
	if(length%2!=0)
	{	
		st.pop();
		for(int i=0;i<length-1;i++)
		{	
			int temp=st.top();
			q.push(temp);
			st.pop();
		}
	}
	
	//else the elements of the stack are transferred into a queue in the reverse  	
	else
	{
		for(int i=0;i<length;i++)
		{	
			int temp=st.top();
			q.push(temp);
			st.pop();
		}
	}
	
	response=consecutive_pairs(q);
	
	if(response==1)
		cout<<"\nEach successive pair of numbers in the stack is consecutive!";
	else if(response==0)
		cout<<"\nEach successive pair of numbers in the stack is not consecutive!";
	else
		cout<<"Error!";
}
