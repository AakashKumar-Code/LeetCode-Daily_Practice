class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int ind=-1;
        for(int i=0; i<n; i++){
            if(cnt==0){
                cnt++;
                ind=i;
            }else if(nums[ind]==nums[i]){
                cnt++;
            }else if(nums[ind]!=nums[i]){
                cnt--;
            }
        }
        return nums[ind];
    }
};