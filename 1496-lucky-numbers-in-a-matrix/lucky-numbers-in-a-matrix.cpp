class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        unordered_set<int>st;

        vector<int>ans;

        for(int i=0; i<n; i++){
            int mini=matrix[i][0];
            for(int j=1; j<m; j++){
                mini=min(mini, matrix[i][j]);
            }
            st.insert(mini);
        }

        for(int j=0; j<m; j++){
            int maxi=matrix[0][j];
            for(int i=1; i<n; i++){
                maxi=max(maxi, matrix[i][j]);
            }
            if(st.find(maxi)!=st.end()){
                ans.push_back(maxi);
            }
        }

        return ans;
    }
};