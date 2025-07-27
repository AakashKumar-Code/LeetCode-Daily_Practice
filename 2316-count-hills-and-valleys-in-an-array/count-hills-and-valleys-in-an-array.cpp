class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;

        for(int i=0; i<n; i++){
            int lft=i-1;
            int rgt=i+1;
            while(lft>0 && nums[lft]==nums[i]){
                lft--;
            }
            while(rgt<n && nums[rgt]==nums[i]){
                rgt++;
            }
            if(lft<0 || rgt>=n) continue;
            if(nums[i]==nums[i-1]) continue;
            if((nums[i]>nums[lft] && nums[i]>nums[rgt]) || 
                nums[i]<nums[lft] && nums[i]<nums[rgt]){
                    
                    cnt++;
                }
        }
        
        return cnt;
    }
};