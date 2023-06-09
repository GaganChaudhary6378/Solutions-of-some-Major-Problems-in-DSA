class Solution
{
    private:
    
    void dfs(int node,int visited [], vector<int> adj[],stack <int> &s){
        visited[node]=1;
        
        for(auto it: adj[node]){
            if(!visited[it]){
                dfs(it,visited,adj,s);
            }
        }
        s.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int visited[V]={0};
	    stack<int> s;
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            dfs(i,visited,adj,s);
	        }
	    }
	    vector<int> ans;
	    
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	        }
	        return ans;
	}
};