class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>pre(n, vector<int>(m, 1)), suf(n, vector<int>(m, 1));

        unsigned long long pro=1;
        unsigned long long mod=12345;

        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                pro=(pro%mod);
                if(r==0 && c==0) continue;
                if(c==0) pro=(pro*grid[r-1][m-1])%mod;
                else pro=(pro*grid[r][c-1])%mod;
                pre[r][c]=pro;
            }
        }

        pro=1;

        for(int r=n-1; r>=0; r--){
            for(int c=m-1; c>=0; c--){
                pro=(pro%mod);
                if(r==n-1 && c==m-1) continue;
                if(c==m-1) pro=(pro*grid[r+1][0])%mod;
                else pro=(pro*grid[r][c+1])%mod;
                suf[r][c]=pro;
            }
        }

        vector<vector<int>>ans(n, vector<int>(m));

        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                ans[r][c]=((pre[r][c])*(suf[r][c]))%mod;
            }
        }

        return ans;        
    }
};