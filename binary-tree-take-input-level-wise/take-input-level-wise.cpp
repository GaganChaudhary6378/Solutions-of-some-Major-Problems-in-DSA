#include <iostream>
using namespace std;
#include "binary-tree-class.cpp"
#include <queue>


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

void printBinaryTree(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }cout<<root->data<<" : ";
    if(root->left!=NULL){
        cout<<"L"<<root->left->data<<" ";
    }if(root->right!=NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}
int main(){
    BinaryTreeNode<int>* root=takeInputLevelWise();
    cout<<endl;
    printBinaryTree(root);
}