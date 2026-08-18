class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int>mpp, freq;
        int i=0, j=0;

        for(; j<n; j++){
            mpp[nums[j]]++;
            for(; i<n && (j-i+1)>k; i++){
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0) mpp.erase(nums[i]);
            }
            if(j-i+1==k){
                for(auto &it:mpp){
                    freq[it.first]++;
                }
            }
        }

        int maxi=-1;
        for(auto &i:freq){
            if(i.second==1){
                maxi=max(maxi, i.first);
            }
        }

        return maxi;
    }
};