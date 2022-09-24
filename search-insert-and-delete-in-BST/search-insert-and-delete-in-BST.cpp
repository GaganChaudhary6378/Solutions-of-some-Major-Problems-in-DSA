#include <iostream>
#include "BinarySearchTree.cpp"
using namespace std;

int main(){
    BST a;

    a.insert(10);
    a.insert(5);
    a.insert(20);
    a.insert(3);
    a.insert(7);
    a.insert(15);

    cout<<"Before deletion the tree is"<<endl;
    a.printTree();

    cout<<"We are searching the element"<<endl;
    cout<<a.search(10)<<endl;
    cout<<a.search(100)<<endl;

    a.deleteData(10);
    a.deleteData(100);

    cout<<"After Deletion"<<endl;
    a.printTree();
}