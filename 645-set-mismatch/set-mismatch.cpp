class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int miss=-1, rep=-1;
        vector<bool>vis(n+1, 0);
        for(int i=0; i<n; i++){
            if(vis[nums[i]]==1){
                rep=nums[i];
            }else{
                vis[nums[i]]=1;
            }
        }
        for(int i=1; i<=n; i++){
            if(vis[i]!=1){
                miss=i;
                break;
            }
        }
        return {rep, miss};
    }
};