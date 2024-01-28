class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int>prev(n+1, 0), curi(n+1, 0);
        for(int j=0; j<n; j++){
            prev[j]=triangle[n-1][j];
        }
        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                int d=triangle[i][j]+prev[j];
                int dr=triangle[i][j]+prev[j+1];
                curi[j]=min(d, dr);
            }
            prev=curi;
        }
        return prev[0];
    }
};