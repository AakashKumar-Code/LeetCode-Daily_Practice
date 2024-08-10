class Solution {
public:

    int dr[4]={-1, 0, 1, 0};
    int dc[4]={0, 1, 0, -1};
    int n, m;

    void dfs(int r, int c, vector<vector<int>>&arr, vector<vector<bool>>&vis){
        vis[r][c]=1;
        for(int i=0; i<4; i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n*3 && nc>=0 && nc<m*3 && arr[nr][nc]==0 && !vis[nr][nc]){
                dfs(nr, nc, arr, vis);
            }
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        n=grid.size();
        m=grid[0].size();

        vector<vector<int>>arr(n*3, vector<int>(m*3, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='/'){
                    arr[i*3][j*3+2]=1;
                    arr[i*3+1][j*3+1]=1;
                    arr[i*3+2][j*3]=1;
                }else if(grid[i][j]=='\\'){
                    arr[i*3][j*3]=1;
                    arr[i*3+1][j*3+1]=1;
                    arr[i*3+2][j*3+2]=1;
                }
            }
        }

        vector<vector<bool>>vis(n*3, vector<bool>(m*3, 0));

        int cnt=0;

        for(int i=0; i<n*3; i++){
            for(int j=0; j<m*3; j++){
                if(!vis[i][j] && arr[i][j]==0){
                    dfs(i, j, arr, vis);
                    cnt++;
                }
            }
        }
        return cnt;        
    }
};