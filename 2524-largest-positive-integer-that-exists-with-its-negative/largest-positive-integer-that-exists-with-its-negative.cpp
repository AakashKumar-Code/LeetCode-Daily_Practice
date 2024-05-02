class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxi=-1e9;
        int n=nums.size();
        unordered_set<int>st;

        for(int i=0; i<n; i++){
            if(nums[i]<0) st.insert(nums[i]);
        }

        for(int i=0; i<n; i++){
            if(nums[i]>0 && st.find(-1*nums[i])!=st.end()){
                maxi=max(maxi, nums[i]);
            }
        }
        return maxi==-1e9?-1:maxi;
    }
};