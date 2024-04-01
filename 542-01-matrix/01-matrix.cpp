class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>>dist(n, vector<int>(m, 1e9));
        vector<vector<bool>>vis(n, vector<bool>(m, 0));

        queue<pair<pair<int, int>, int>>q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    q.push({{i, j}, 0});
                    vis[i][j]=1;
                }
            }
        }

        int dr[4]={-1, 0, 1, 0};
        int dc[4]={0, 1, 0, -1};

        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;
            q.pop();

            
            dist[r][c]=d;

            for(int i=0; i<4; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({{nr, nc}, d+1});
                }
            }
        }

        return dist;
    }
};