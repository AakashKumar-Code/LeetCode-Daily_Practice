class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>tmp(101, -1);
        int mini=101, maxi=-1;
        for(int &num:nums){
            tmp[num]=1;
            mini=min(mini, num);
            maxi=max(maxi, num);
        }
        vector<int>ans;

        for(int i=mini; i<=maxi; i++){
            if(tmp[i]==-1) ans.push_back(i);
        } 

        return ans;        
    }
};