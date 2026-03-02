class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();

        vector<int>tmp(n, 0);

        for(int i=0; i<n; i++){
            int j=n-1, cnt=0;
            while(j>=0 && grid[i][j]==0){
                cnt++;
                j--;
            }

            tmp[i]=cnt;
        }

        int ans=0;

        for(int i=0; i<n; i++){
            int j=i;
            int need=n-i-1;
            while(j<n && tmp[j]<need){
                j++;
            }
            if(j==n) return -1;
            ans+=(j-i);
            while(j>i){
                swap(tmp[j], tmp[j-1]);
                j--;
            }
        }

        return ans;        
    }
};