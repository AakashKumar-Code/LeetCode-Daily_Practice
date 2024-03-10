class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st1, st2;
        int n=nums1.size();
        int m=nums2.size();
        if(n<m){
            st1={nums2.begin(), nums2.end()};
            for(int i=0; i<n; i++){
                if(st1.find(nums1[i])!=st1.end()){
                    st2.insert(nums1[i]);
                }
            }
            vector<int>ans(st2.begin(), st2.end());
            return ans;
        }else{
            st1={nums1.begin(), nums1.end()};
            for(int i=0; i<m; i++){
                if(st1.find(nums2[i])!=st1.end()){
                    st2.insert(nums2[i]);
                }
            }
            vector<int>ans(st2.begin(), st2.end());
            return ans;
        }
        return {};
    }
};