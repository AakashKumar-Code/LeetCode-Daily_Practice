class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, pair<int, int>>mpp;

        int mini=1e9;

        for(int i=0; i<n; i++){
            if(mpp.find(nums[i])!=mpp.end()){
                if(mpp[nums[i]].second==-1){
                    mpp[nums[i]].second=i;
                }else{
                    int x=mpp[nums[i]].first;
                    int y=mpp[nums[i]].second;
                    int z=i;
                    int tmp=abs(x-y)+abs(y-z)+abs(z-x);
                    mini=min(mini, tmp);
                    mpp[nums[i]].first=y;
                    mpp[nums[i]].second=z;
                }
            }else{
                mpp[nums[i]]={i, -1};
            }
        }

        return mini==1e9?-1:mini;        
    }
};