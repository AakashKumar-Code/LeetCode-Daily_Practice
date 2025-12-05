class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int cnt=0, totSum=0, sum=0;
        for(int i=0; i<n; i++) totSum+=nums[i];

        for(int i=0; i<n-1; i++){
            sum+=nums[i];
            if(((totSum-2*sum)%2)==0) cnt++;
        }

        return cnt;        
    }
};