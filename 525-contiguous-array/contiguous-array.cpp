class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int>mpp;
        int sum=0;
        mpp[0]=-1;
        int maxi=0;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                sum+=-1;
            }else sum+=1;

            if(mpp.find(sum)==mpp.end()){
                mpp[sum]=i;
            }else{
                maxi=max(maxi, i-mpp[sum]);
            }
        }
        return maxi;
        
    }
};