class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;

        int cnt=0;
        
        for(int i=0; i<n; i++){
            if(cnt>0){
                if(nums[i]==0){
                    cnt++;
                }else cnt=0;
            }else{
                if(nums[i]==0) cnt++;
            }
            ans+=cnt;
        }

        return ans;
        
    }
};