class Solution {
public:

    vector<pair<int, int>>servings={{100, 0}, {75, 25}, {50, 50}, {25, 75}};

    double solve(int a, int b, vector<vector<double>>&dp){
        if(a<=0){
            if(b<=0) return 0.5;
            else return 1.0;
        }

        if(b<=0) return 0.0;

        if(dp[a][b]!=-1.0) return dp[a][b];

        double tot=0.0;

        for(auto &it:servings){
            double a_used=it.first;
            double b_used=it.second;
            tot+=solve(a-a_used, b-b_used, dp);
        }

        return dp[a][b]=tot*(0.25);
    }

    double soupServings(int n) {

        if(n>=5000) return 1;

        vector<vector<double>>dp(n+1, vector<double>(n+1, -1.0));
        return solve(n, n, dp);
        
    }
};