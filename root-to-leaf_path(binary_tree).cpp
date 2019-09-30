/*																				Submitted By : DEEPAK YADAV 

Question 6:																				

(BINARYTREE): Given a binary tree, print out all its root –to –leaf paths.

*/
#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;

struct node
{	
	int data;
	struct node *left,*right;	
};

void all_paths(struct node *root,queue<int> q,queue<int> q_temp)
/*   			
	objective: to determine all root -to -leaf paths of a binary tree 
	input parameters: none
	output value: all root -to -leaf paths of a binary tree are displayed
	approach: recursive approach with the help of two queues
*/
{
	/* if a node doesn't have any of the left or right subnodes then the elements of the queue are displayed 
	   and popped subsequently. All the node elements of the queue are moved into a temporary queue until the
	   queue gets empty except the current node which is again moved into the original queue*/
	if(root->left==NULL&&root->right==NULL)
	{
		while(!q.empty())
		{
			int temp1 = q.front();
			cout<<temp1;
			cout<<" -> ";
			q.pop();
			q_temp.push(temp1);	
		}	
		
		cout<<root->data<<endl<<endl;
		
		while(!q_temp.empty())
		{
			int temp2=q_temp.front();
			q_temp.pop();
			q.push(temp2);
		}
	}
	
	else
	{
		/* if the node has both the left and right node then the root is pushed into the queue and 
		   then the function is recalled with the subnodes as the root nodes      */
		if(root->left!=NULL&&root->right!=NULL)
		{
			q.push(root->data);
			all_paths(root->left,q,q_temp);
			
			all_paths(root->right,q,q_temp);
		}
		
		/* else if the node has both the left node then the root is pushed into the queue and then
		   the function is recalled with the left subnode as the root node */
		else if(root->left!=NULL&&root->right==NULL)
		{
			q.push(root->data);
			all_paths(root->left,q,q_temp);
		}
		
		/* else if the node has both the right node then the root is pushed into the queue and then
		   the function is recalled with the right subnode as the root node */
		else
		{
			q.push(root->data);
			all_paths(root->right,q,q_temp);	
		}
		
	}
	
}

//makes a new node by taking the data element as a parameter and initializing its left and right nodes as NULL
struct node* newnode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  
  return(node);
}

int main()
/*   			
	objective: to print out all its root –to –leaf paths of given binary tree
	input parameters: none	
	output value: none	
	approach: a recursive function is called 
*/
{
	queue<int> q;
	queue<int> q_temp;
	struct node *root = newnode(10);
	root->left = newnode(9);
    root->right = newnode(12);
      
    root->left->left = newnode(4);
    root->left->right = newnode(50);
    root->right->right = newnode(-7);
      
    root->left->left->left = newnode(18);
    root->left->left->right = newnode(9);
	
	cout<<"\n\nALL THE POSSIBLE ROOT -TO -LEAF PATHS ARE :\n\n";
	all_paths(root,q,q_temp);
	
}

