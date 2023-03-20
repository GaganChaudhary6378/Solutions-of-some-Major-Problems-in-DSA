class Solution {
    void bfs(int row,int col,vector<vector<int>> &visited,vector<vector<char>> grid){
        visited[row][col]=1;
        queue<pair<int,int>> bfs;
        bfs.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        while(!bfs.empty()){
            int row=bfs.front().first;
            int col=bfs.front().second;
            bfs.pop();
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int nrow=row+delrow;
                    int ncol=col+delcol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                    && grid[nrow][ncol]=='1' && !visited[nrow][ncol]){
                        visited[nrow][ncol]=1;
                        bfs.push({nrow,ncol});
                        
                    }
                }
            }
        }

    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(); // number of rows
        int m=grid[0].size(); // number of columns
        vector<vector<int>> visited(n,vector<int>(m,0));
        int count=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!visited[row][col] && grid[row][col]=='1'){
                    bfs(row,col,visited,grid);
                    count++;
                }
            }
        }return count;
    }
};