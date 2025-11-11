class Solution {
public:

    pair<int, int>count(string &s){
        int cnt0=0, cnt1=0;
        for(char &ch:s){
            if(ch=='0') cnt0++;
            else cnt1++;
        }
        return {cnt0, cnt1};
    }

    int solve(int i, int x, int y, vector<pair<int, int>>&v, int n, vector<vector<vector<int>>>&dp){
        if(i>=n) return 0;
        if(dp[i][x][y]!=-1) return dp[i][x][y];
        int take=0, ntake=0;
        if(x>=v[i].first && y>=v[i].second){
            take=1+solve(i+1, x-v[i].first, y-v[i].second, v, n, dp);
        }
        ntake=solve(i+1, x, y, v, n, dp);
        return dp[i][x][y]=max(take, ntake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>>v;

        for(auto &it:strs){
            v.push_back(count(it));
        }
        int max0=0, max1=0;
    	vector<vector<vector<int>>>dp(601, vector<vector<int>>(101, vector<int>(101, -1)));
        return solve(0, m, n, v, v.size(), dp);
        
    }
};