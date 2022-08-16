#include <iostream>
#include <queue>
using namespace std;
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

void printLevelWise(treenode<int>*root){
    if(root==NULL){
        return;
    }
    queue<treenode<int>*> restnodes;
    restnodes.push(root);
    while(restnodes.size()!=0){
        treenode<int>* front=restnodes.front();
        cout<<front->data<<" : ";
        restnodes.pop();
        for(int i=0;i<front->children.size();i++){
            cout<<front->children[i]->data<<",";
            restnodes.push(front->children[i]);
        }cout<<endl;
    }
}


int main(){
    cout<<"Taking the input Level wise in a tree"<<endl;
    treenode<int> *root=takeInputLevelWise();
    cout<<endl;
    cout<<"Printing the tree LevelWise"<<endl;
    printLevelWise(root);
}
