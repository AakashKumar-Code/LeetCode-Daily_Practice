class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int maxi=-1e9;
        for(int i=0; i<n; i++) maxi=max(maxi, citations[i]);
        

        vector<int>f(maxi+1, 0);
        for(int i=0; i<n; i++){
            f[citations[i]]++;
        }

        int prev=0;
        for(int i=maxi; i>=0; i--){
            f[i]+=prev;
            prev=f[i];
            if(i<=f[i]) return i;
        }
        return 0;
    }
};