#include<iostream>
#include<cstdlib>
#include<stack>
#include<string>
using namespace std;

//sets the precedence of the operators
int precedence(char ch)
{
	if(ch=='^')
		return 2;
	else if(ch=='*'||ch=='/')
		return 1;
	else if(ch=='+'||ch=='-')
		return 0;
	else
		return-1;
}

//converts an infix expression to a postfix expression
void infix_to_postfix(string s)
{
	stack<char> st;
	int len= s.length();
	string str;
	
	for(int i=0;i<len;i++)
	{
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
			str+=s[i];
		else if(s[i]=='(')
			st.push('(');
		else if (s[i]==')')
			{
				while(!st.empty()&&st.top()!='(')
					{
						char ch= st.top();
						st.pop();
						str+=ch;
					}
				if(st.top()=='(')
					st.pop();
			}
		else
		{
			while(!st.empty()&&precedence(s[i])<=precedence(st.top()))
				{
					char ch= st.top();
					st.pop();
					str+=ch;
				}
				st.push(s[i]);
		}
	}
	
	while(!st.empty())
	{
		char ch=st.top();
		st.pop();
		str+=ch;
	}
	cout<<str<<endl;
}

int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infix_to_postfix(exp);
    return 0;
}
