#include <iostream>
using namespace std;
#include "treenode.cpp"

treenode<int>* takeInput(){
    int rootdata;
    cout<<"Enter data"<<endl;
    cin>>rootdata;
    treenode<int>* root=new treenode<int>(rootdata);
    int n;
    cout<<"Enter number of childrens of root node"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        treenode<int>* child=takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(treenode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" :";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<" ,";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}

int main(){
    treenode<int>*root=takeInput();
    printTree(root);
}