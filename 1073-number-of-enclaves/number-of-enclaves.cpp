class Solution {
public:

    int dr[4]={-1, 0, 1, 0};
    int dc[4]={0, 1, 0, -1};

    void bfs(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<bool>>&vis){        
        queue<pair<int, int>>q;
        q.push({i, j});

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int t=0; t<4; t++){
                int nr=r+dr[t];
                int nc=c+dc[t];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
                    vis[nr][nc]=1;
                    q.push({nr, nc});
                }
            }            
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>>vis(n, vector<bool>(m, 0));

        for(int j=0; j<m; j++){
            if(grid[0][j] && !vis[0][j]){
                vis[0][j]=1;
                bfs(0, j, n, m, grid, vis);
            } 
            if(grid[n-1][j] && !vis[n-1][j]) {
                vis[n-1][j]=1;
                bfs(n-1, j, n, m, grid, vis);
            }
        }

        for(int i=1; i<n-1; i++){
            if(grid[i][0] && !vis[i][0]) {
                vis[i][0]=1;
                bfs(i, 0, n, m, grid, vis);
            }
            if(grid[i][m-1] && !vis[i][m-1]) {
                vis[i][m-1]=1;
                bfs(i, m-1, n, m, grid, vis);
            }
        }

        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]) cnt++;
            }
        }

        return cnt;
    }
};