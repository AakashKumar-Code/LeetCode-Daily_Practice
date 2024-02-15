class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());

        vector<long long>pre(n, 0);
        
        for(int i=1; i<n; i++){
            pre[i]=pre[i-1]+nums[i-1];
        }
        
        int i=n-1;
        for(; i>=0; i--){
            if(nums[i]<pre[i]) break;
        }
        if(i<=1) return -1;
        return pre[i]+nums[i];
    }
};