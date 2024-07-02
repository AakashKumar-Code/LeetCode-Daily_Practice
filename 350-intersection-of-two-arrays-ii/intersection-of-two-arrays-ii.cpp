class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>mpp;
        int n=nums1.size(), m=nums2.size();

        for(int i=0; i<n; i++){
            mpp[nums1[i]]++;
        }

        vector<int>ans;
        for(int i=0; i<m; i++){
            if(mpp.find(nums2[i])!=mpp.end()){
                ans.push_back(nums2[i]);
                mpp[nums2[i]]--;
                if(mpp[nums2[i]]==0) mpp.erase(nums2[i]);
            }
        }
        return ans;
    }
};