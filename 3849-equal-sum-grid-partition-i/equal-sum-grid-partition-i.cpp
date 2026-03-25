class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        unsigned long long sum=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                sum+=grid[i][j];
            }
        }

        unsigned long long rsum=0, csum=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                rsum+=grid[i][j];
            }
            if((2*rsum)==sum) return true;
        }

        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                csum+=grid[i][j];
            }
            if((2*csum)==sum) return true;
        }

        return false;
        
    }
};