class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int i=0, j=0, maxi=0;
        unordered_map<int, int>mpp;

        for(; j<n; j++){
            mpp[fruits[j]]++;
            for(; i<n && mpp.size()>2; i++){
                mpp[fruits[i]]--;
                if(mpp[fruits[i]]==0) mpp.erase(fruits[i]);
            }
            maxi=max(maxi, (j-i+1));
        }

        return maxi;        
    }
};