// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n=grid.size();
        int m= grid[0].size();
        vector<vector<int>> distance(n,vector<int>(m,1e9));
        
        queue<pair<int,pair<int,int>>> q;
        
        distance[source.first][source.second]=0;
        q.push({0,{source.first,source.second}});
        
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        if(source.first==destination.first && source.second == destination.second){
            return 0;
        }
        while(!q.empty()){
            int dist=q.front().first;
            
            int row=q.front().second.first;
            int col=q.front().second.second;
            
            q.pop();
            
            for(int i=0;i<4;i++){
                int nrow=drow[i]+row;
                int ncol=dcol[i]+col;
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol <m && grid[nrow][ncol]==1 && dist+1 < distance[nrow][ncol]){
                    distance[nrow][ncol]=dist+1;
                    if(nrow == destination.first && ncol == destination.second){
                        return dist+1;
                    }
                    q.push({dist+1,{nrow,ncol}});
                }
            }
        }return -1;
    }
};