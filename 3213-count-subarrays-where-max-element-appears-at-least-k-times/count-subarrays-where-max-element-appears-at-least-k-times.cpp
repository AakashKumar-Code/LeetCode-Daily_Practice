class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=-1e9;
        for(int i=0; i<n; i++){
            maxi=max(maxi, nums[i]);
        }        
        int cnt=0;
        long long ans=0;

        int i=0, j=0;

        for(; j<n; j++){
            if(nums[j]==maxi){
                cnt++;
            }
            for(; i<n && cnt>=k; i++){
                ans+=(n-j);
                if(nums[i]==maxi){
                    cnt--;
                }
            }
        }

        return ans;
        
    }
};