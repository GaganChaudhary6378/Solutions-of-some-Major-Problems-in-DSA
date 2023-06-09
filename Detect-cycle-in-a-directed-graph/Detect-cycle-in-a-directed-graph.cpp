class Solution {
    private:
    bool dfs(int node,int visited [] , int pathVisited [], vector<int> adj[]){
        visited[node]=1;
        pathVisited[node]=1;
        
        for(auto it : adj[node]){
            if(!visited[it]){
                if(dfs(it,visited,pathVisited,adj)==true){
                    return true;
                };
            }else if(pathVisited[it] && visited[it]){
                return true;
            }
        }
        pathVisited[node]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int visited[V]={0};
        int pathVisited[V]={0};
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,visited,pathVisited,adj)==true){
                    return true;
                };
            }
        }
        return false;
    }
};