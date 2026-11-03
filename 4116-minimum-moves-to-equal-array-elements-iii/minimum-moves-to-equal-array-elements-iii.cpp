class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=0, maxi=0, n=nums.size();
        for(int &it:nums){
            maxi=max(maxi, it);
            sum+=it;
        }
        return (maxi*n)-sum;
    }
};