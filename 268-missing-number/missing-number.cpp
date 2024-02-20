class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int num=(nums[0]^0)^n;
        for(int i=1; i<n; i++){
            num^=nums[i];
            num^=i;
        }
        return num;
    }
};