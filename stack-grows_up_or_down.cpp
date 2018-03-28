/*																					Submitted By : DEEPAK YADAV 

Question 1:

(STACK):On a given machine, how do you check whether the stack grows up or down? 

*/
#include<iostream>
#include<cstdlib>
#include<stack>
using namespace std;

int main()
/*   			
	objective: to check whether the stack grows up or down 
	
	input parameters: 
		ch1 : an integer that is to be pushed into the stack
		ch2 : another integer that is to be pushed into the stack
		
	output value: 
		addr1 : the address of the first input variable that is pushed into the stack
		addr2 	the address of the second input variable that is pushed into the stack
	
	approach: the address of both the integers are compared to determine whether the stack grows up or down
*/
{
	stack<int> st;
	int ch1,ch2;
	int *addr1,*addr2;
	cout<<"Enter a number to push into the stack :";
	cin>>ch1;
	st.push(ch1);
	addr1=&st.top();
	cout<<"Enter another number to push into the stack:";
	cin>>ch2;
	st.push(ch2);
	addr2=&st.top();
	
	if(addr1<addr2)
		cout<<"\nThe stack grows up..\n\n\tSince, address of 1st number is "<<addr1<<"\n\tWhereas, address of 2nd number is "<<addr2;
	else if(addr2<addr1)
		cout<<"\nThe stack grows down..\n\n\tSince, address of 1st number is "<<addr1<<"\n\tWhereas, address of 2nd number is "<<addr2;
	else
		cout<<"Error..";
}
