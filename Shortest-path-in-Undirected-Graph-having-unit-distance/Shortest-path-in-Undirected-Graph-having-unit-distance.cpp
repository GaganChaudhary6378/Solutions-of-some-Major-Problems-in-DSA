// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        // first create an adjacency list 
        vector<int>adj[N];
        
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        // till here we have created an adjacency list
        queue<int> q;
        
        vector<int> dist(N);
        
        for(int i=0;i<N;i++){
            dist[i]=INT_MAX;
        }
        dist[src]=0;
        q.push(src);
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it : adj[node]){
                if(dist[node]+1<dist[it]){
                    dist[it]=dist[node]+1;
                    q.push(it);
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        return dist;
    }
};