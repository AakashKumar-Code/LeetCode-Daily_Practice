class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        

        vector<vector<bool>>vis(n, vector<bool>(m, 0));
        queue<pair<int, int>>q;

        int sR=entrance[0];
        int sC=entrance[1];

        if(sR<0 || sR>=n || sC<0 || sC>=m || maze[sR][sC]=='+') return -1;

        q.push({sR, sC});
        vis[sR][sC]=1;
        
        int steps=0;

        int dr[4]={-1, 0, 1, 0};
        int dc[4]={0, 1, 0, -1};

        while(!q.empty()){
            int sz=q.size();
            steps++;
            for(int t=0; t<sz; t++){
                auto it=q.front();
                q.pop();
                int r=it.first;
                int c=it.second;

                for(int i=0; i<4; i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && maze[nr][nc]=='.' && !vis[nr][nc]){
                        if(nr==0 || nr==n-1 || nc==0 || nc==m-1) return steps;
                        vis[nr][nc]=1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return -1;
        
    }
};