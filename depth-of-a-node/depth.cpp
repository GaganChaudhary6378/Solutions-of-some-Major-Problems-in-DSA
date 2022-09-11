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
// we have to print the node present at the kth level/depth
void printAtK(treenode<int>* root,int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<endl;
    }
    for(int i=0;i<root->children.size();i++){
        printAtK(root->children[i],k-1);
    }
}

int main(){
    treenode<int>* root=takeInputLevelWise();
    cout<<endl;
    int x;
    cout<<"Enter the level which you want to print"<<endl;
    cin>>x;
    cout<<"Printing at level : "<<x<<endl;
    printAtK(root,x);
}