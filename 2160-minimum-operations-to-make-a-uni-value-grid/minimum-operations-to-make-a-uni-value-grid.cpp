class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==1 && m==1) return 0;

        vector<int>tmp;
        int rem=grid[0][0]%x;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((grid[i][j]%x)!=rem) return -1;
                tmp.push_back(grid[i][j]);
            }
        }

        sort(tmp.begin(), tmp.end());

        int mid=tmp[(m*n)/2];

        int ops=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ops+=(abs(grid[i][j]-mid)/x);
            }
        }
        
        return ops;
    }
};