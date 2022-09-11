#include <iostream>
using namespace std;
#include "binary-tree-class.cpp"
#include <queue>

void printLevelWise(binaryTreeNode<int> *root){
    if(root==NULL){
        return ;
    }if(root->data==-1){
        return;
    }

    queue<binaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        binaryTreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<": ";
        if(front->left!=NULL){
            binaryTreeNode<int>* leftchild=front->left;
            cout<<"L"<<front->left->data<<",";
            pendingNodes.push(leftchild);
        }
        else{
            cout<<"L-1,";
        }
        if(front->right!=NULL){
            binaryTreeNode<int>* rightchild=front->right;
            cout<<"R"<<front->right->data;
            pendingNodes.push(rightchild);
        }
        else{
            cout<<"R-1";
        }
        cout<<endl;
    }
}




binaryTreeNode<int> *takeInputLevelWise(){
    int data;
    cout<<"Enter root data: ";
    cin>>data;
    if(data==-1){
        return NULL;
    }
    binaryTreeNode<int> *root=new binaryTreeNode<int>(data);
    queue<binaryTreeNode<int>*> remainingNodes;
    remainingNodes.push(root);
    while(remainingNodes.size()!=0){
        binaryTreeNode<int>* front=remainingNodes.front();
        remainingNodes.pop();
        int leftChildData;
        cout<<"Enter the data of left child of "<<front->data<<": ";
        cin>>leftChildData;
        if(leftChildData!=-1){
            binaryTreeNode<int> *leftChild=new binaryTreeNode<int>(leftChildData);
            front->left=leftChild;
            remainingNodes.push(leftChild);
        }
        int rightChildData;
        cout<<"Enter the data of right child of "<<front->data<<": ";
        cin>>rightChildData;
        if(rightChildData!=-1){
            binaryTreeNode<int> *rightChild=new binaryTreeNode<int>(rightChildData);
            front->right=rightChild;
            remainingNodes.push(rightChild);
        }
    }
    return root;
}
// In order traversal in binary-tree

void inOrder(binaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main(){
    binaryTreeNode<int>* root=takeInputLevelWise();
    printLevelWise(root);
    inOrder(root);

}
