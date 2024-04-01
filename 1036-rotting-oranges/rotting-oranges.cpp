class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int time=0;

        queue<pair<int, int>>q;
        bool fresh=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2) q.push({i, j});
                if(grid[i][j]==1) fresh=1;
            }
        }
        if(q.empty()){
            if(fresh) return -1;
            else return 0;
        }

        int dr[4]={-1, 0, 1, 0};
        int dc[4]={0, 1, 0, -1};

        vector<vector<bool>>vis(n, vector<bool>(m, 0));

        while(!q.empty()){
            int sz=q.size();
            for(int t=0; t<sz; t++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();

                for(int i=0; i<4; i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
                        vis[nr][nc]=1;
                        q.push({nr, nc});
                    }
                }
            }
            time++;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]) return -1;
            }
        }

        return time-1;
    }
};