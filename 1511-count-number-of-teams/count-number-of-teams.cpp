class Solution {
public:
int dp[1002][1002][4];
    int cal(int i , int prev ,int taken , vector<int> &arr)
    {
        if(taken > 3)   return 0;
        if(i == arr.size()) 
        {
            return taken == 3 ?1:0;
        }
        if(dp[i][prev][taken]!=-1)  return dp[i][prev][taken];

        int t = 0;

        if(prev == arr.size()+1 || arr[prev] < arr[i])
        {
            t = cal(i+1 , i , taken +1 , arr);
        }
        int nt = cal(i+1 , prev , taken ,arr);

        return dp[i][prev][taken] = t + nt;
    }
    int cal2(int i , int prev ,int taken , vector<int> &arr)
    {
        if(taken > 3)   return 0;
        if(i == arr.size()) 
        {
            return taken == 3 ?1:0;
        }
        if(dp[i][prev][taken]!=-1)  return dp[i][prev][taken];

        int t = 0;

        if(prev == arr.size()+1 || arr[prev] > arr[i])
        {
            t = cal2(i+1 , i , taken +1 , arr);
        }
        int nt = cal2(i+1 , prev , taken ,arr);

        return dp[i][prev][taken] = t + nt;
    }


    int numTeams(vector<int>& arr) {
            int n = arr.size();
            memset(dp , -1 ,sizeof(dp));
            int a = cal(0 , n+1 , 0 , arr);
            memset(dp , -1 ,sizeof(dp));
            int b =cal2(0 , n+1 , 0 ,arr);
            return a+b;
    }
};