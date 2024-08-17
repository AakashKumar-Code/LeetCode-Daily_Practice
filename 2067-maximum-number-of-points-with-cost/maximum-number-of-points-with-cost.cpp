class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int m=points[0].size();

        vector<long long>curr(m), prev(m);

        for(int j=0; j<m; j++) prev[j]=points[0][j];

        for(int i=1; i<n; i++){
            vector<long long>left(m, 0), right(m, 0);
            left[0]=prev[0];
            for(int j=1; j<m; j++){
                left[j]=max(left[j-1]-1, prev[j]);
            }
            right[m-1]=prev[m-1];
            for(int j=m-2; j>=0; j--){
                right[j]=max(right[j+1]-1, prev[j]);
            }
            for(int j=0; j<m; j++){
                curr[j]=max(left[j], right[j])+points[i][j];
            }
            prev=curr;
        }
        long long maxi=-1e9;
        for(int j=0; j<m; j++){
            maxi=max(maxi, prev[j]);
        }
        return maxi;        
    }
};