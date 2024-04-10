class Solution {
public:

    int dr[4]={-1, 0, 1, 0};
    int dc[4]={0, 1, 0, -1};

    void bfs(int i, int j, int n, int m, vector<vector<char>>& grid, vector<vector<bool>>&vis){
        
        queue<pair<int, int>>q;
        q.push({i, j});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int ind=0; ind<4; ind++){
                int nr=r+dr[ind];
                int nc=c+dc[ind];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]=='1'){
                    vis[nr][nc]=1;
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m, 0));
        int cnt=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    vis[i][j]=1;
                    bfs(i, j, n, m, grid, vis);
                    cnt++;
                }
            }
        }

        return cnt;
        
    }
};