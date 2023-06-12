// User function Template for C++
class Solution {
    private:
    
    void topo(int node,vector<pair<int,int>> adj[],int visited[],stack<int> &s){
        visited[node]=1;
        
        for(auto it : adj[node]){
            int u=it.first;
            if(!visited[u]){
                topo(u,adj,visited,s);
            }
        }s.push(node);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // first i have to make a graph
        // creating a adjacency list
        
        vector<pair<int,int>> adj[N];
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int d=edges[i][2];
            adj[u].push_back({v,d});
        }
        
        // now till here our adjacency list is ready apply toposort now
        int visited[N]={0};
        stack<int> s;
        for(int i=0;i<N;i++){
            if(!visited[i]){
                topo(i,adj,visited,s);
            }
        }
        vector<int> dist(N);    
        for(int i=0;i<N;i++){
            dist[i]=1e9;
        }
        dist[0]=0;
        while(!s.empty()){
            int node=s.top();
            s.pop();
            for(auto it : adj[node]){
                int v=it.first;
                int wt=it.second;
                if(dist[node]+wt <dist[v]){
                    dist[v]=dist[node]+wt;
                }
            }
        }for(int i=0;i<N;i++){
            if(dist[i]==1e9){
                dist[i]=-1;
            }
        }
        return dist;
    }
};