class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n=arrays.size();
        int maxi=arrays[0].back();
        int mini=arrays[0].front();
        int diff=-1e9;

        for(int i=1; i<n; i++){
            diff=max(diff, max(maxi-arrays[i].front(), arrays[i].back()-mini));
            maxi=max(maxi, arrays[i].back());
            mini=min(mini, arrays[i].front());
        }
        return diff;        
    }
};