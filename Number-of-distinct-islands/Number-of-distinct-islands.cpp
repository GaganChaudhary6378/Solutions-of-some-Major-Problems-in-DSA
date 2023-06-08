// User function Template for C++

class Solution {
    private: 
    void dfs(int row,int col,vector<vector<int>> &visited,vector<vector<int>>& grid,vector<pair<int,int>> &vec,int baseRow,int baseCol){
        visited[row][col]=1;
        vec.push_back({row-baseRow,col-baseCol});
        
        int n=grid.size();
        int m=grid[0].size();
        
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+-1,0,+1};
        
        for(int i=0;i<4;i++){
            int nrow=drow[i]+row;
            int ncol=dcol[i]+col;
            
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,visited,grid,vec,baseRow,baseCol);
            }
        }
        
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> visited(n,vector<int> (m,0));
        set<vector<pair<int,int>>> s;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> vec;
                    dfs(i,j,visited,grid,vec,i,j);
                    s.insert(vec);
   
                }
            }
        }return s.size();
    }
};