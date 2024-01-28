class Solution {
public:


    bool isPal(int lo, int hi, string &s){
        while(lo<=hi){
            if(s[lo++]!=s[hi--]) return 0;
        }
        return 1;
    }

    int solve(int ind, int &n, string &s, vector<int>&dp){
        if(ind==n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int mini=1e9;
        for(int i=ind; i<n; i++){
            if(isPal(ind, i, s)){
                int ops=1+solve(i+1, n, s, dp);
                mini=min(mini, ops);
            }
        }
        return dp[ind]=mini;
    }

    int minCut(string s) {
        int n=s.length();
        vector<int>dp(n+1, -1);
        return solve(0, n, s, dp)-1;
    }
};