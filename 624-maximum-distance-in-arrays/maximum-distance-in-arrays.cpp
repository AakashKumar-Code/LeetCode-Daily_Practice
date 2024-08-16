class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m=arrays.size();
        bool isSz=1;
        int maxEl=-1e9, minEl=1e9;
        vector<int>maxi, mini;
        for(int i=0; i<m; i++){
            int n=arrays[i].size();
            maxi.push_back(arrays[i][n-1]);
            mini.push_back(arrays[i][0]);
            if(n>1) isSz=0;
            maxEl=max(maxEl, arrays[i][n-1]);
            minEl=min(minEl, arrays[i][0]);
        }
        if(isSz) return maxEl-minEl;

        int diff=-1e9;

        for(int i=0; i<maxi.size(); i++){
            for(int j=0; j<mini.size(); j++){
                if(i!=j) diff=max(diff, abs(maxi[i]-mini[j]));
            }
        }
        return diff;
    }
};