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

int countleaf(treenode<int> * root){
    if(root==NULL){
        return 0;
    }
    if(root->children.size()==0){
        return 1;
    }int total=0;
    for(int i=0;i<root->children.size();i++){
        total=total+countleaf(root->children[i]);
    }return total;
}

int main(){
    treenode<int>* root=takeInputLevelWise();
    cout<<endl;
    int count=countleaf(root);
    cout<<"No of leaf nodes are : "<<count<<endl;
}