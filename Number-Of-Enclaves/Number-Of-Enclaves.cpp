// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int, int>>  q;
        
        for(int i=0;i<m;i++){
            // traverse for 1st row
            if(!visited[0][i] && grid[0][i]==1){
                q.push({0,i});
            }
            //traverse for last row
            if(!visited[n-1][i] && grid[n-1][i]==1){
                q.push({n-1,i});
            }
        }for(int j=0;j<n;j++){
            // traverse for 1st boundary column
            if(!visited[j][0] && grid[j][0]==1){
                q.push({j,0});
            }
            //traverse for last boundary column
            if(!visited[j][m-1] && grid[j][m-1]==1){
                q.push({j,m-1});
            }
        }
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            visited[row][col]=1;
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                    q.push({nrow,ncol});
                    // visited[nrow][ncol]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    count++;
                }
            }
        }return count;
    }
};