class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();

        int maxi=-1e9;
        if(colors[0]!=colors[n-1]){
            return n-1;
        }
        for(int i=1; i<n-1; i++){
            if(colors[i]!=colors[0]){
                maxi=max(maxi, i);
            }
            if(colors[i]!=colors[n-1]){
                maxi=max(maxi, n-i-1);
            }
        }

        return maxi;        
    }
};