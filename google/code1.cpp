#include<iostream>
#include"../myTemplates/dtsBinaryTree.hpp"

using namespace std;

void countNotForbidden(dtsBinaryTreeNode<bool>* node,long& ret){
    if(!node){
        return;
    }
    if(!node->leftChild && !node->rightChild && node->value){//if not forbidden
        ++ret;
    }
    if(node->leftChild){
        countNotForbidden(node->leftChild,ret);
    }
    if(node->rightChild){
        countNotForbidden(node->rightChild,ret);
    }
}

long countNotForbidden(dtsBinaryTree<bool>& bTree){
    long ret=0;
    countNotForbidden(bTree.getRoot(),ret);
    return ret;
}

//set/reset all the nodes after this node
void setForbidden(dtsBinaryTreeNode<bool>* node,bool val){
    if(!node){
        return;
    }
    if(!node->leftChild && !node->rightChild){
        node->value=val;
    }
    if(node->leftChild){
        countNotForbidden(node->leftChild,ret);
    }
    if(node->rightChild){
        countNotForbidden(node->rightChild,ret);
    }
}

int getElseSequencesNum(){
    dtsBinaryTree<bool> bTree;
    //build a binary tree
    //true = not forbidden
    //false = forbidden
    //left = black
    //right = red
    int N,P;
    cin>>N>>P;
    int forbiddenPrefixNumber=0;
    for(int i=0;i<P;++i){
        string str;
        cin>>str;
        
    }
    


    return 0;
}

int main(){
    int T=0;
    cin>>T;
    for(int i=1;i<T;++i){
        cout<<"Case #"<<i<<": "<<getElseSequencesNum()<<endl;
    }
    return 0;
}
