class Solution {
public:

    bool check(vector<int>&nums, int n, int mid, int t){
        long long sum=0;
        for(int i=0; i<n; i++){
            sum += ceil((double)nums[i] / mid);
        }
        return sum<=t;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        long long sum=0;
        int maxi=-1e9;
        int n=nums.size();
        for(int i=0; i<n; i++){
            sum+=nums[i];
            maxi=max(maxi, nums[i]);
        }
        int ans=-1;
        int lo=1, hi=maxi;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(nums, n, mid, threshold)){
                ans=mid;
                hi=mid-1;
            }else lo=mid+1;
        }
        return ans;        
    }
};