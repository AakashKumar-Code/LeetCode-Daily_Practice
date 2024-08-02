class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int N=2*n;
        vector<int>arr(N);
        int ones=0;

        for(int i=0; i<N; i++){
            arr[i]=nums[i%n];
            if(nums[i%n]==1) ones++;
        }
        ones/=2;

        int i=0, j=0;
        int maxi=0, currCnt=0;

        for(; j<N; j++){
            if(arr[j]==1) currCnt++;
            for(; i<N && (j-i+1>ones); i++){
                if(arr[i]==1) currCnt--;
            }
            if(j-i+1==ones){
                maxi=max(maxi, currCnt);
            }
        }
        return ones-maxi;       
        
    }
};