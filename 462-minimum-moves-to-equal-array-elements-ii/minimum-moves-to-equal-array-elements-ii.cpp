class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(), nums.end());

        int m=0;
        if((n%2)==1){
            m=nums[(n-1)/2];
        }else{
            m=((nums[(n-1)/2]+nums[n/2])/2);
        }

        int diff=0;

        for(int i=0; i<n; i++){
            diff+=(abs(nums[i]-m));
        }

        return diff;
    }
};