class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int row=0; row<n; row++){
            for(int col=1; col<m; col++){
                matrix[row][col]+=matrix[row][col-1];
            }
        }

        int ans=0;
        for(int startCol=0; startCol<m; startCol++){
            for(int col=startCol; col<m; col++){
                unordered_map<int, int>mpp;
                mpp.insert({0, 1});
                int sum=0;
                for(int row=0; row<n; row++){
                    sum+=matrix[row][col]-(startCol>0?matrix[row][startCol-1]:0);
                    if(mpp.find(sum-target)!=mpp.end()){
                        ans+=mpp[sum-target];
                    }
                    mpp[sum]++;
                }
            }
        }
        return ans;
    }
};