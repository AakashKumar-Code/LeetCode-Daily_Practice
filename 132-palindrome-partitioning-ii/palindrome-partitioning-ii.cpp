class Solution {
public:

    bool isPal(int lo, int hi, string &s){
        while(lo<=hi){
            if(s[lo++]!=s[hi--]) return 0;
        }
        return 1;
    }

    int minCut(string s) {
        int n=s.length();
        vector<int>dp(n+1, 0);
        for(int ind=n-1; ind>=0; ind--){
            int mini=1e9;
            for(int i=ind; i<n; i++){
                if(isPal(ind, i, s)){
                    int ops=1+dp[i+1];
                    mini=min(mini, ops);
                }
            }
            dp[ind]=mini;
        }
        return dp[0]-1;
    }
};