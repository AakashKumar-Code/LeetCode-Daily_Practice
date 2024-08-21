class Solution {
public:

    int dp[101][101];

    int solve(int l, int r, string &s){
        if(l==r) return 1;
        if(l>r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int i=l+1;
        while(s[i]==s[l]){
            i++;
        }
        if(i>r) return 1;
        int tmp=1+solve(i, r, s);
        int mini=INT_MAX;
        for(int j=i; j<=r; j++){
            if(s[j]==s[l]){
                int tmp2=solve(i, j-1, s)+solve(j, r, s);
                mini=min(mini, tmp2);
            }
        }
        return dp[l][r]=min(mini, tmp);
    }

    int strangePrinter(string s) {
        int n=s.length();
        memset(dp, -1, sizeof(dp));
        return solve(0, n-1, s);        
    }
};