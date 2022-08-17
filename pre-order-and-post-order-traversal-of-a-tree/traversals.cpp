#include <iostream>
using namespace std;
#include <queue>
#include "treenode.cpp"

treenode<int> *takeInputLevelWise(){
    int rootdata;
    cout<<"Enter root data : ";
    cin>>rootdata;
    treenode<int>* root=new treenode<int>(rootdata);

    queue<treenode<int>*> restNodes;
    restNodes.push(root);

    while(restNodes.size()!=0){
        treenode<int>* front=restNodes.front();
        restNodes.pop();
        int noofchilds;
        cout<<"Enter no of childs of"<<front->data<<": ";
        cin>>noofchilds;
        for(int i=0;i<noofchilds;i++){
            int childdata;
            cout<<"Enter the "<<i<<" th child of "<<front->data<<" : ";
            cin>>childdata;
            treenode<int>* child=new treenode<int>(childdata);
            front->children.push_back(child);
            restNodes.push(child);
        }
    }return root;
}
// Pre order traversal

void preOrder(treenode<int>* root){
    if(root==NULL){
        return;
    }cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        preOrder(root->children[i]);
    }
}

// Post order traversal

void postOrder(treenode<int>* root){
    if(root==NULL){
        return;
    }
    for(int i=0;i<root->children.size();i++){
        postOrder(root->children[i]);
    }cout<<root->data<<" ";
}

int main(){
    treenode<int>* root=takeInputLevelWise();
    cout<<endl;
    cout<<"Pre order traversal"<<endl;
    preOrder(root);
    cout<<endl;
    cout<<"Post order traversal"<<endl;
    postOrder(root);
}