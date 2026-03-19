class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>cntX(n, vector<int>(m, 0));
        vector<vector<int>>cntY(n, vector<int>(m, 0));

        int ans=0;

        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                int i=0, j=0, k=0;
                if(r>0) i=cntX[r-1][c];
                if(c>0) j=cntX[r][c-1];
                if(r>0 && c>0) k=cntX[r-1][c-1];
                cntX[r][c]=(i+j-k+(grid[r][c]=='X'?1:0));

                i=0, j=0, k=0;
                if(r>0) i=cntY[r-1][c];
                if(c>0) j=cntY[r][c-1];
                if(r>0 && c>0) k=cntY[r-1][c-1];
                cntY[r][c]=(i+j-k+(grid[r][c]=='Y'?1:0));

                if(cntX[r][c]==cntY[r][c] && cntX[r][c]>0){
                    ans++;
                }
            }
        }

        return ans;

    }
};