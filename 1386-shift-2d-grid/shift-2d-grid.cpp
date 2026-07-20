class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        int len=m*n;

        k=(k%len);

        vector<int>tmp;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                tmp.push_back(grid[i][j]);
            }
        }

        vector<int>tmp2(m*n);

        for(int i=0; i<len; i++){
            tmp2[(i+k)%len]=tmp[i];
        }

        int ind=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                grid[i][j]=tmp2[ind++];
            }
        }

        return grid;        
    }
};