class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int>prev(n, 0), curi(n, 0);
        for(int j=0; j<n; j++){
            prev[j]=matrix[0][j];
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int ldg=1e9, rdg=1e9;
                int up=matrix[i][j]+prev[j];
                if(j-1>=0) ldg=matrix[i][j]+prev[j-1];
                if(j+1<n) rdg=matrix[i][j]+prev[j+1];
                curi[j]=min({up, ldg, rdg});
            }
            prev=curi;
        }
        int mini = *min_element(prev.begin(), prev.end());
        return mini;
    }
};