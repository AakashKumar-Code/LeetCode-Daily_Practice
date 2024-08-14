class Solution {
public:
    int n;

    int solve(int mid, vector<int>&arr){
        int cnt=0;
        int i=0, j=0;
        for(; j<n; j++){
            for(; i<n && arr[j]-arr[i]>mid; i++){

            }
            if(i!=j) cnt+=(j-i);
        }
        return cnt;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        n=nums.size();
        sort(nums.begin(), nums.end());

        int lo=0, hi=nums[n-1]-nums[0];

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int cnt=solve(mid, nums);
            if (cnt < k) {
                lo = mid + 1;
            } else {
                hi = mid-1; // Try for smaller distances
            }
        }
        return lo;        
    }
};