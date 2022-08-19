#include <iostream>
using namespace std;
#include <queue>
#include "binary-tree-class.cpp"

BinaryTreeNode<int>* takeInputLevelWise(){
    int data;
    cout<<"Enter root data"<<endl;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(data);
    queue<BinaryTreeNode<int>*> restNodes;
    restNodes.push(root);
    while(restNodes.size()!=0){
        BinaryTreeNode<int>* front=restNodes.front();
        restNodes.pop();
        cout<<"Enter left child of "<<front->data<<endl;
        int leftchild;
        cin>>leftchild;
        if(leftchild!=-1){
            BinaryTreeNode<int>* child=new BinaryTreeNode<int>(leftchild);
            front->left=child;
            restNodes.push(child);
        }
        cout<<"Enter right child of "<<front->data<<endl;
        int rightchild;
        cin>>rightchild;
        if(rightchild!=-1){
            BinaryTreeNode<int>* child=new BinaryTreeNode<int>(rightchild);
            front->right=child;
            restNodes.push(child);
        }
    }
    return root;
}

void printLevelWise(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> restNode;
    restNode.push(root);
    while(restNode.size()!=0){
        BinaryTreeNode<int>* front=restNode.front();
        restNode.pop();
        cout<<front->data<<" ";
        if(front->left!=NULL){
        BinaryTreeNode<int>* child=front->left;
        cout<<"L"<<child->data<<" ";
        restNode.push(child);
        }
        if(front->right!=NULL){
            BinaryTreeNode<int>* child=front->right;
            cout<<"R"<<child->data;
            restNode.push(child);
        }cout<<endl;
    }

}
int main(){
    BinaryTreeNode<int>* root=takeInputLevelWise();
    cout<<endl;
    printLevelWise(root);
}