class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();        
        int ones=0;
        for(int i=0; i<n; i++){
            if(nums[i]==1) ones++;
        }
        int N=n+ones;
        int i=0, j=0;
        int maxi=0, currCnt=0;

        for(; j<N; j++){
            if(nums[j%n]==1) currCnt+=1;
            for(; i<N && (j-i+1>ones); i++){
                if(nums[i%n]==1) currCnt-=1;
            }
            if(j-i+1==ones){
                maxi=max(maxi, currCnt);
                if(maxi==ones) return 0;
            }
        }
        return ones-maxi;          
    }
};