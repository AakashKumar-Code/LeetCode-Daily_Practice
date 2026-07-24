class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st, st1;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                st.insert(nums[i]^nums[j]);
            }
        }

        for(int i=0; i<n; i++){
            for(auto &j:st){
                st1.insert(nums[i]^j);
            }
        }

        return st1.size();
    }
};