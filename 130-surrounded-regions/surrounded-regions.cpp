class Solution {
public:

    int dr[4]={-1, 0, 1, 0};
    int dc[4]={0, 1, 0, -1};

    void dfs(int r, int c, int n, int m, vector<vector<char>>& arr, vector<vector<bool>>&vis){

        for(int i=0; i<4; i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && arr[nr][nc]=='O'){
                vis[nr][nc]=1;
                dfs(nr, nc, n, m, arr, vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();        

        vector<vector<bool>>vis(n, vector<bool>(m, 0));

        for(int j=0; j<m; j++){
            if(board[0][j]=='O' && !vis[0][j]){
                vis[0][j]=1;
                dfs(0, j, n, m, board, vis);
            }
            if(board[n-1][j]=='O' && !vis[n-1][j]){
                vis[n-1][j]=1;
                dfs(n-1, j, n, m, board, vis);
            }
        }

        for(int i=1; i<n-1; i++){
            if(board[i][0]=='O' && !vis[i][0]){
                vis[i][0]=1;
                dfs(i, 0, n, m, board, vis);
            }
            if(board[i][m-1]=='O' && !vis[i][m-1]){
                vis[i][m-1]=1;
                dfs(i, m-1, n, m, board, vis);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }

        return;
        
    }
};