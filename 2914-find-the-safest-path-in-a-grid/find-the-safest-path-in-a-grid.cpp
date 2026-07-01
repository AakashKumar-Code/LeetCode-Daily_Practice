class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();

        if(grid[0][0]==1 || grid[n-1][n-1]==1) return 0;

        queue<pair<int, int>>q;

        vector<vector<int>>dis(n, vector<int>(n, 1e9));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    q.push({i, j});
                    dis[i][j]=0;
                }
            }
        }

        int dr[4]={0, 1, 0, -1};
        int dc[4]={1, 0, -1, 0};

        while(!q.empty()){
            auto [r, c]=q.front();
            q.pop();

            for(int i=0; i<4; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<n && dis[nr][nc]==1e9){
                    q.push({nr, nc});
                    dis[nr][nc]=dis[r][c]+1;
                }
            }
        }

        int lo=0, hi=n;
        int ans=1e9;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            queue<pair<int, int>>q;
            vector<vector<bool>>vis(n, vector<bool>(n, 0));
            bool possible = false;

            if(dis[0][0]>=mid){
                q.push({0, 0});
                vis[0][0]=1;               

                while(!q.empty()){
                    auto [r, c]=q.front();
                    q.pop();

                    if(r==n-1 && c==n-1){
                        possible=true;
                        break;
                    }

                    for(int i=0; i<4; i++){
                        int nr=r+dr[i];
                        int nc=c+dc[i];

                        if(nr>=0 && nr<n && nc>=0 && nc<n && dis[nr][nc]>=mid && !vis[nr][nc]){
                            vis[nr][nc]=1;
                            q.push({nr, nc});
                        }
                    }
                }
            }
            if(possible){
                ans=mid;
                lo=mid+1;
            }else hi=mid-1;
        }

        return ans;        
    }
};