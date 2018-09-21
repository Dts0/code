#include <string>
#include <iostream>
#include <stack>
using namespace std;

const string PUSH("Push");
const string POP("Pop");

typedef struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int d):data(d), left(NULL), right(NULL){}
}Node;

void PostOrderTraverse(Node *root)
{
	Node* temp = root;
	Node* pre = NULL;
	stack<Node*> S;
	int flag = 0;

	while(temp || !S.empty())
	{
		if(temp)
		{
			S.push(temp);
			temp = temp->left;
		}
		else
		{
			temp = S.top();
			if(temp->right && temp->right != pre)
				temp = temp->right;
			else
			{
				if(!flag)
				{
					flag = 1;
					cout<< temp->data;
				}
				else
					cout<<" "<<temp->data;
				S.pop();
				pre = temp;
				temp = NULL;
			}
		}
	}
	cout<<endl;
}

int main()
{
	int n, data;
	string act;
	stack<Node*> S;
	Node* root = NULL, *pre = NULL;
	int l = 1, r = 0;
	cin >> n;

	//First, build the tree , root of tree is *root.
	for(int i=1; i <= 2*n; i++)
	{
		Node* temp;
		cin >> act;
		if(act == PUSH)
		{
			cin >> data;
			temp = new Node(data);
			if(i == 1)
			{
				root = temp;
			}

			S.push(temp);
			if(pre)
			{
				if(l == 1)
					pre->left = temp;
				else
					pre->right = temp;
			}
			l = 1;
			pre = temp;
		}
		else if(act == POP)
		{
			pre = S.top();
			S.pop();
			l = 0;
		}
	}

	PostOrderTraverse(root);

	return 0;
}
