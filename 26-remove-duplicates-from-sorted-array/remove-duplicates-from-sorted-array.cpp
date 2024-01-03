class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int ind=1;
        int prev=nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]!=prev){
                prev=nums[i];
                swap(nums[i], nums[ind]);
                ind++;
            }
        }
        return ind;
    }
};