class Solution {
public:

    bool static comp(pair<int, int>&a, pair<int, int>&b){
        if(a.first != b.first) 
            return a.first < b.first; // sort by frequency in ascending order
        return a.second > b.second;
    }

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int>mpp;
        int n=nums.size();

        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }

        vector<pair<int, int>>v;

        for(auto &it:mpp){
            v.push_back({it.second, it.first});
        }

        sort(v.begin(), v.end(), comp);

        vector<int> ans;
        ans.reserve(n); // Reserve space to avoid multiple allocations

        for(auto &it : v) {
            for(int i = 0; i < it.first; i++) {
                ans.push_back(it.second);
            }
        }

        return ans;
        
    }
};