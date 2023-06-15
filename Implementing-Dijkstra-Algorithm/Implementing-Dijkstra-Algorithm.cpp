class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        // thats the way to declare a min priority queue
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int> dist(V);
        
        for(int i=0;i<V;i++){
            dist[i]=1e9;
        }
        dist[S]=0;
        
        pq.push({0,S});
        
        while(!pq.empty()){
            int distance=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int node=it[0];
                int nodeDist=it[1];
                
                if(distance+ nodeDist < dist[node]){
                    dist[node]=distance + nodeDist;
                    pq.push({dist[node],node});
                }
            }
        }return dist;
        
        
        
    }
};