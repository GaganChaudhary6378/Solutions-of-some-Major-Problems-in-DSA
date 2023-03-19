class Solution {
    private:
    void dfs(int node,vector<int> adjList[],int visited[]){
        visited[node]=1;
        for(auto it : adjList[node]){
            if(!visited[it]){
                dfs(it,adjList,visited);
            }
        }

    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // So first i am converting this adjacency matrix to adjacency list
        int V=isConnected.size();
        vector<int> adjList[V];
        cout<<V;
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }int visited[V];
        for(int i=0;i<V;i++){
            visited[i]=0;
        }
        // visited[0]=1;
        int count=0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                count++;
                dfs(i,adjList,visited);
            }
        }
        return count;
    }
};