class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        if(numRows==1) return ans;
        ans.push_back({1, 1});
        
        for(int i=3; i<=numRows; i++){
            vector<int>tmp(i);
            tmp[0]=1;
            tmp[i-1]=1;

            for(int j=1; j<i-1; j++){
                tmp[j]=ans[i-2][j]+ans[i-2][j-1];
            }

            ans.push_back(tmp);
        }

        return ans;        
    }
};