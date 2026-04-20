class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();

        int maxi=-1e9;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(colors[i]==colors[j]) continue;
                maxi=max(maxi, j-i);
            }
        }

        return maxi;        
    }
};