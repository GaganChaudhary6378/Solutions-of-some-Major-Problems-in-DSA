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

treenode<int>* maxData(treenode<int>* root){
    treenode<int> *max=root;
    if(root==NULL){
        return 0;
    }
    for(int i=0;i<root->children.size();i++){
        treenode<int>* c=maxData(root->children[i]);
        if(c->data>max->data){
            max=c;
        }
    }return max;
}
int main(){
    treenode<int>* root=takeInputLevelWise();
    treenode<int>*max=maxData(root);
    cout<<endl;
    cout<<"Node with maximum data is : "<<max->data<<endl;
}