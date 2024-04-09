class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int>st, ans;
        for(int i=0; i<n; i++){
            if(st.find(k+nums[i])!=st.end()){
                ans.insert(min(nums[i], k+nums[i]));
            }
            if(st.find(nums[i]-k)!=st.end()){
                ans.insert(min(nums[i], nums[i]-k));
            }
            st.insert(nums[i]);            
        }
        return ans.size();        
    }
};