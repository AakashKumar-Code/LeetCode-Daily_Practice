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

        vector<int>temp;

        for(int i=0; i<n; i++){
            if(nums[i]==maxi) temp.push_back(i);
            int size=temp.size();
            if(size>=k){
                int last_i=temp[size-k];
                ans+=last_i+1;
            }
        }

        return ans;
        
    }
};