class Solution {
public:
    int dp[1002][1002][4];
    int lis(int i,int n, int prev, int cnt, vector<int>&arr){
        if(cnt>3) return 0;
        if (i == n) {
        return cnt == 3 ? 1 : 0;
        }
        if(prev!=-1 && dp[i][prev][cnt]!=-1) return dp[i][prev][cnt];
        int take=0, ntake=0;

        if(prev==-1 || (prev!=-1 && arr[prev]<arr[i])){
            take+=lis(i+1, n, i, cnt+1, arr);
        }
        ntake=lis(i+1, n, prev, cnt, arr);
        if(prev!=-1) dp[i][prev][cnt]=take+ntake;    
        return take+ntake; 
    }

    int lds(int i,int n, int prev, int cnt, vector<int>&arr){
        if(cnt>3) return 0;
        if (i == n) {
        return cnt == 3 ? 1 : 0;
        }
        if(prev!=-1 && dp[i][prev][cnt]!=-1) return dp[i][prev][cnt];

        int take=0, ntake=0;

        if(prev==-1 || (prev!=-1 && arr[prev]>arr[i])){
            take=lds(i+1, n, i, cnt+1, arr);
        }
        ntake=lds(i+1, n, prev, cnt, arr);
        if(prev!=-1) dp[i][prev][cnt]=take+ntake; 
        return take+ntake;     
    }

    int numTeams(vector<int>& rating) {
        int n=rating.size();
        memset(dp , -1 ,sizeof(dp));
        int ans1=lis(0, n, -1, 0, rating);
        memset(dp , -1 ,sizeof(dp));
        int ans2=lds(0, n, -1, 0, rating);
        return ans1+ans2;        
    }
};