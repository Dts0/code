#include<iostream>
#include<vector>

using namespace std;

#define Max_Node 11
#define END -1

typedef struct node
{
    int left;
    int right;
}Node;

void Initialize_Tree(vector<Node>& Tree,int N)//初始化树
{
    for (int i=1; i<=N; ++i)
    {
        Tree[i].left=END;
        Tree[i].right=END;
    }
}

void Build_Tree(vector<Node>& Tree,int N)//读取输入并建树
{
    int value,flag=0,root=0,pre=0;
    while (N--)
    {
        cin>>value;
        if (flag==0)//读到的第一个结点为根结点，记录下来
        {
            root=value;
            pre=root;
            flag=1;
        }else
        {
            while (1)
            {
                if (value>pre && Tree[pre].right!=END)//当前输入值比访问的上一个结点pre（pre最初为根结点）大，且pre有右孩子
                {
                    pre=Tree[pre].right;
                }
                if (value>pre && Tree[pre].right==END)//当前输入值比访问的上一个结点pre（pre最初为根结点）大，且pre无右孩子
                {
                    Tree[pre].right=value;
                    pre=root;//下一次输入数字也从根结点开始比较
                    break;
                }
                if (value<pre && Tree[pre].left!=END)//当前输入值比访问的上一个结点pre（pre最初为根结点）小，且pre有左孩子
                {
                    pre=Tree[pre].left;
                }
                if (value<pre && Tree[pre].left==END)//当前输入值比访问的上一个结点pre（pre最初为根结点）小，且pre无左孩子
                {
                    Tree[pre].left=value;
                    pre=root;//下一次输入数字也从根结点开始比较
                    break;
                }
            }
        }
    }
}

bool Compare_Tree(vector<Node> Tree1,vector<Node> Tree2,int N)//比较两棵树的每一个结点的左右孩子结点是否相等
{
    int i=1;
    for (; i<=N; ++i)
    {
        if (!(Tree1[i].left==Tree2[i].left && Tree1[i].right==Tree2[i].right))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int N,L;
    int flag=0;
    while (1)
    {
        cin>>N;
        if (N==0)
        {
            break;
        }
        cin>>L;
        vector<vector<Node> > vec(L,vector<Node>(Max_Node));
        vector<Node> Tree(Max_Node);
        Initialize_Tree(Tree, N);
        for (int i=0; i<L; ++i)
        {
            Initialize_Tree(vec[i], N);
        }
        Build_Tree(Tree, N);
        for (int i=0; i<L; i++)
        {
            Build_Tree(vec[i], N);
            if (Compare_Tree(Tree, vec[i], N))
            {
                if (flag==0)
                {
                    flag=1;
                    cout<<"Yes";
                }else
                {
                    cout<<'\n'<<"Yes";
                }
            }else
            {
                if (flag==0)
                {
                    flag=1;
                    cout<<"No";
                }else
                {
                    cout<<'\n'<<"No";
                }
            }
        }
    }
    
    return 0;
}

