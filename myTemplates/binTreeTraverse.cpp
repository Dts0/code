#include"dtsBinaryTree.hpp"
#include"dtsStack.hpp"
#include"dtsQueue.hpp"
#include<vector>
using namespace std;

void traverse_pre(dtsBinaryTreeNode<int>* root){
	dtsStack<dtsBinaryTreeNode<int>*> stack;
	while(root || stack.top()){//必须栈空而且root也为空才结束
		while(root){
			cout<<root->value<<" ";
			stack.push(root);
			root=root->leftChild;
		}
		root=stack.pop();
		root=root->rightChild;
	}
}
void traverse_in(dtsBinaryTreeNode<int>* root){
	dtsStack<dtsBinaryTreeNode<int>*> stack;
	while(root || stack.top()){//必须栈空而且root也为空才结束
		while(root){
			stack.push(root);
			root=root->leftChild;
		}
		root=stack.pop();
		cout<<root->value<<" ";
		root=root->rightChild;
	}
}

void traverse_post(dtsBinaryTreeNode<int>* root){
	dtsStack<pair<dtsBinaryTreeNode<int>*,bool>> stack;
	stack.push(make_pair(root,false));
	bool visited;
	while(!stack.empty()){
		root=stack.top().first;
		visited=stack.top().second;
		stack.pop();
		if(root==NULL)
			continue;
		if(visited){
			cout<<root->value<<" ";
		}
		else {
			stack.push(make_pair(root,true));
			stack.push(make_pair(root->rightChild,false));
			stack.push(make_pair(root->leftChild,false));
		}
	}
}

void traverse_BFS(dtsBinaryTreeNode<int>* root){
	dtsQueue<dtsBinaryTreeNode<int>*> queue0;
	if(root)
		queue0.push(root);
	while(!queue0.empty()){
		//queue0.print();
		dtsBinaryTreeNode<int>* tmp=queue0.pop();
		cout<<tmp->value<<" ";
		//cout<<tmp->leftChild<<","<<tmp->rightChild<<endl<<endl;
		if(tmp->leftChild){
			queue0.push(tmp->leftChild);
		}
		if(tmp->rightChild){
			queue0.push(tmp->rightChild);
		}
	}
}

dtsBinaryTreeNode<int>* formCore(vector<int>::iterator startPre,vector<int>::iterator endPre,
								 vector<int>::iterator startIn,vector<int>::iterator endIn){
	int rootVal=startPre[0];//根结点为前序遍历第一个
	dtsBinaryTreeNode<int>* root=new dtsBinaryTreeNode<int>(rootVal);

	if(startPre==endPre){
		return root;
		//if(startPre==endPre && *startPre==*endPre){
		//	return root;
		//}
		// else {
		//	throw exception("invalid input during preorder traverse");
		//}
	}
	vector<int>::iterator rootIn=startIn;
	while(rootIn!=endIn && *rootIn!=rootVal){//在中序遍历中找到根结点
		++rootIn;
	}
	//if(startIn==endIn && *startIn!=*endIn){
	//	throw exception("invalid input during inorder traverse");
	//}
	int leftLength=rootIn-startIn;
	int rightLength=endIn-rootIn;
	vector<int>::iterator leftPreEnd=startPre+leftLength;
	if(leftLength>0){//构建左子树
		root->leftChild=formCore(startPre+1,leftPreEnd,startIn,rootIn-1);
	} else {
		root->leftChild=NULL;
	}
	if(rightLength>0){
		root->rightChild=formCore(leftPreEnd+1,endPre,rootIn+1,endIn);
	} else {
		root->rightChild=NULL;
	}


}

dtsBinaryTreeNode<int>* formTreeWithTravRst(vector<int> preTraverse,vector<int> inTraverse){
	if(preTraverse.empty() || inTraverse.empty())
		return NULL;
	return formCore(preTraverse.begin(),preTraverse.end()-1,
					inTraverse.begin(),inTraverse.end()-1);
}


int main(){
	/*       0
	*     1      2
	*   3  6   4   5
	*/
/*
//debug for dtsList while try to find the reason why pTail and pBegin is not NULL
	dtsList<int> list;
	list.add2End(1)
		.add2Head(2);
	cout<<list.deleteFromEnd()<<endl;
	cout<<list.deleteFromHead()<<endl;
	cout<<list.deleteFromHead()<<endl;
*/


	dtsBinaryTreeNode<int>* root=new dtsBinaryTreeNode<int>(0);
	dtsBinaryTree<int> tree(root);
	tree.add2Left_val(1,0).add2Right_val(2,0).add2Left_val(3,1)
		.add2Left_val(4,2).add2Right_val(5,2).add2Right_val(6,1);

	tree.print_pre();
	traverse_pre(root);
	cout<<endl;
	tree.print_in();
	traverse_in(root);
	cout<<endl;
	tree.print_post();
	traverse_post(root);
	cout<<endl;
	traverse_BFS(root);
	cout<<endl;
	cout<<endl;

	vector<int> preTrav{1,2,4,7,3,5,6,8};
	vector<int> inTrav{4,7,2,1,5,3,8,6};
	dtsBinaryTreeNode<int>* formedTreeRoot=formTreeWithTravRst(preTrav,inTrav);
	dtsBinaryTree<int> tree_formed(formedTreeRoot);
	tree_formed.print_pre();
	tree_formed.print_in();
	tree_formed.print_post();

	return 0;
}
