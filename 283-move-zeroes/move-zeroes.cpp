class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]!=0) continue;
            else{
                int j=i+1;
                for(; j<n; j++){
                    if(nums[j]!=0) break;
                }
                if(j<n) swap(nums[i], nums[j]);
            }
        }
    }
};