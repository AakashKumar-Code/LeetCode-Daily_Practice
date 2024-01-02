class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int>mpp;
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }
        while(mpp.size()!=0){
            vector<int>temp;
            for (auto it = mpp.begin(); it != mpp.end(); ) {
            int t = it->first;
            temp.push_back(t);
            it->second--;
            
            if (it->second == 0) {
                it = mpp.erase(it);
            } else {
                ++it;
            }
        }
            ans.push_back(temp);
        }
        return ans;
    }
};