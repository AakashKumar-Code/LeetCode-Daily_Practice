class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%3!=0) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        int cnt=0;
        int maxi=0;
        vector<int>temp;
        for(int i=n-1; i>=0; i--){
            if(cnt==0){
                maxi=nums[i];
            }
            cnt++;
            if(maxi-nums[i]>k) return {};
            temp.push_back(nums[i]);
            if(cnt==3){
                ans.push_back(temp);
                temp.clear();
                cnt=0;
            }
        }
        return ans;
    }
};