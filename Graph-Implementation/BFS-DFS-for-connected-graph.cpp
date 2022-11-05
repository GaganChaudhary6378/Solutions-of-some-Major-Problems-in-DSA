#include <iostream>
#include <queue>
using namespace std;

// DFS for disconnected graph
void printDFS(int **edges,int n,int sv,bool * visited){
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(i==sv){
            continue;
        }if(edges[sv][i]==1){
            if(visited[i]){
                continue;
            }
            printDFS(edges,n,i,visited);
        }
    }
}

// BFS for disconnected graph

void printBFS(int ** edges,int n,int sv,bool * visited){
    queue<int> remainingData;
    remainingData.push(sv);
    visited[sv]=true;
    while(remainingData.size()!=0){
        int front=remainingData.front();
        remainingData.pop();
        cout<<front<<" ";
        for(int i=0;i<n;i++){
            if(i==front){
                continue;
            }if(edges[front][i]==1){
                if(visited[i]){
                    continue;
                }
                remainingData.push(i);
                visited[i]=true;
            }
        }

    }
}
void BFS(int ** edges,int n){
    bool * visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            printBFS(edges,n,i,visited);
        }
    }
    delete [] visited;
}
void DFS(int ** edges,int n){
    bool * visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            printDFS(edges,n,i,visited);
        }
    }
    delete [] visited;
}

int main(){
    int n;
    int e;
    cin>>n>>e;
    int ** edges=new int* [n];
    for(int i=0;i<n;i++){
        edges[i]=new int [n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    
    cout<<"Required DFS traversal of a graph is :-"<<endl;
    DFS(edges,n);
    cout<<"Required BFS traversal of a graph is :-"<<endl;
    BFS(edges,n);

    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete [] edges;
}