class Solution {
public:
    int n, m;
    int dr[4]={-1, 0, 1, 0};
    int dc[4]={0, 1, 0, -1};

    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis){
        vis[r][c]=1;
        for(int i=0; i<4; i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
                dfs(nr, nc, grid, vis);
            }
        }
    }

    int num_of_islands(vector<vector<int>>& grid){

        vector<vector<bool>>vis(n, vector<bool>(m, 0));
        int cnt=0;
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(!vis[row][col] && grid[row][col]==1){
                    dfs(row, col, grid, vis);
                    cnt++;
                }
            }
        }
        return cnt;

    }

    int minDays(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        int cnt=num_of_islands(grid);

        if(cnt==0 || cnt>1) return 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    int cnt1=num_of_islands(grid);                    
                    if(cnt1>1 || cnt1==0) return 1;
                    grid[i][j]=1;
                }
            }
        }
        return 2;        
    }
};