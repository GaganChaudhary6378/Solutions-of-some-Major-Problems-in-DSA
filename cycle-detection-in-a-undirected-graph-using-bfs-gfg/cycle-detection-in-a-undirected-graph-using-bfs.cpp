class Solution {
    private:
    bool bfs(int src,vector<int> adj[],int visited[]){
        visited[src]=1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto adjacentNode : adj[node]){
                if(!visited[adjacentNode]){
                    visited[adjacentNode]=1;
                    q.push({adjacentNode,node});
                }
                else if(parent!= adjacentNode){
                    return true;
                }
            }
        }return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int visited[V]={0};
        
        // now if we have multiple components then we have to traverse to all of them through visited array
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(bfs(i,adj,visited)){
                    return true;
                }
            }
        }return false;
        
    }
};