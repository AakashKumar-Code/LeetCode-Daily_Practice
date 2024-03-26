class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        bool contains1=0;
        for(int i=0; i<n; i++){
            if(nums[i]==1){
                contains1=1;
            }else if(nums[i]<=0 || nums[i]>n){
                nums[i]=1;
            }
        }
        if(!contains1) return 1;
        for(int i=0; i<n; i++){
            int idx=abs(nums[i])-1;
            if(nums[idx]>0) nums[idx]*=(-1);
        }
        for(int i=0; i<n; i++){
            if(nums[i]>0) return i+1;
        }
        return n+1;        
    }
};