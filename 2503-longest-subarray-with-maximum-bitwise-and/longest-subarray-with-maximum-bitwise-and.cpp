class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();

        int maxi=0;
        for(int i=0; i<n; i++) maxi=max(maxi, nums[i]);

        int cnt=0, maxCnt=1;
        for(int i=0; i<n; i++){
            if(nums[i]==maxi){
                if(cnt>=1){
                    cnt++;
                    maxCnt=max(maxCnt, cnt);
                }
                else cnt=1;
            }else cnt=0;
        }       

        return maxCnt;
    }
};