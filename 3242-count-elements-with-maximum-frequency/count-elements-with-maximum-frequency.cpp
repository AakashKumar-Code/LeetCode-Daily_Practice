class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(101, 0);
        int maxi=0;
        int cnt=0;
        for(int i=0; i<n; i++){
            temp[nums[i]]++;
            if(temp[nums[i]]>maxi){
                maxi=temp[nums[i]];
                cnt=1;
            }else if(temp[nums[i]]==maxi){
                cnt++;
            }
        }
        return cnt*maxi;
    }
};