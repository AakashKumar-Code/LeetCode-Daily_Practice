class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();

        int dr[4]={-1, 0, 1, 0};
        int dc[4]={0, 1, 0, -1};

        queue<pair<int, int>>q;
        q.push({sr, sc});
        int prev=image[sr][sc];

        vector<vector<bool>>vis(n, vector<bool>(m, 0));
        vis[sr][sc]=1;

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            image[r][c]=color;

            for(int i=0; i<4; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && image[nr][nc]==prev){
                    vis[nr][nc]=1;
                    q.push({nr, nc});
                }
            }
        }

        return image;
    }
};