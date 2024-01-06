class Solution {
public:

    int n; 
    int dp[50001];

    int getNxtInd(vector<vector<int>>&forSort, int l, int currentJobEnd){
        int r=n-1;
        int res=n+1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(forSort[mid][0]>=currentJobEnd){
                res=mid;
                r=mid-1;
            }else l=mid+1;
        }
        return res;
    }

    int solve(int i, vector<vector<int>>&forSort){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int next=getNxtInd(forSort, i+1, forSort[i][1]);

        int doJob=forSort[i][2]+solve(next, forSort);
        int notDo=solve(i+1, forSort);
        return dp[i]=max(doJob, notDo);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        vector<vector<int>>forSort(n, vector<int>(3));
        
        for(int i=0; i<n; i++){
            forSort[i][0]=startTime[i];
            forSort[i][1]=endTime[i];
            forSort[i][2]=profit[i];
        }
        sort(forSort.begin(), forSort.end());
        memset(dp, -1, sizeof(dp));
        return solve(0, forSort);        
    }
};