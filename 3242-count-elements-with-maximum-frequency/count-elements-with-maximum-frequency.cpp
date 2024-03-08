class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int>mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }
        int maxi=-1e9;
        for(auto&it:mpp){
            maxi=max(maxi, it.second);
        }
        int sum=0;
        for(auto &it:mpp){
            if(it.second==maxi) sum+=it.second;
        }
        return sum;
    }
};