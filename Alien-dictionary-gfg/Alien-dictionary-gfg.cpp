// User function Template for C++

class Solution{
    private: 
    vector<int> topoSort(vector<int> adj[],int V){
        int indegree[V]={0};
        
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        vector<int> topo;
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return topo;
    }
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        
        for(int i=0;i<N-1;i++){
            string first=dict[i];
            string second=dict[i+1];
            
            int len=min(first.size(),second.size());
            
            for(int j=0;j<len;j++){
                if(first[j]!=second[j]){
                    adj[first[j] - 'a'].push_back(second[j] - 'a');
                    break;
                }
            }
            
        }vector<int> topo=topoSort(adj,K);
            
            string ans="";
            for(auto it : topo){
                ans=ans+ char(it+'a');
            }
            
            return ans;
    }
};