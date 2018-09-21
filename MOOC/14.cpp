#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct TNode* BSTree;
struct TNode
{
    BSTree left;
    BSTree right;
    int data;
};
vector<int> a;
int rootindex(int left, int right)
{
    int index;
    int totol = right -left +1;
    int depth = (int)(log2(totol+1)-1);
    int bottom = totol - exp2(depth+1)+1;
    if(bottom <= exp2(depth)) index = (totol - bottom)/2 + bottom;
    else index = (totol - bottom)/2 + exp2(depth);
    return left+index;
}
BSTree findroot(int left, int right)
{
    if(left<=right)
    {
        int root = rootindex(left,right);
        BSTree rootnode = new TNode;
        rootnode->data = a[root];
        rootnode->left = findroot(left,root-1);
        rootnode->right = findroot(root+1,right);
        return rootnode;
    }
    else return NULL;

}
void levelOrderTraverse(BSTree t)
{
    queue<BSTree> q;
    q.push(t);
    a.clear();
    while(!q.empty())
    {
        BSTree tmp = q.front();
        a.push_back(tmp->data);
        q.pop();
        if(tmp->left!=NULL) q.push(tmp->left);
        if(tmp->right!=NULL) q.push(tmp->right);
    }
}
void printvec(vector<int> v)
{
    for(int i=0;i<(v.size()-1);i++)
    {
        cout<<v[i]<<' ';
    }
    cout<<v[v.size()-1];
}
int main()
{
    int n,x;
    cin>>n;
    a.push_back(-1);
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    BSTree tree = findroot(1,n);
    levelOrderTraverse(tree);
    printvec(a);
    return 0;
}

