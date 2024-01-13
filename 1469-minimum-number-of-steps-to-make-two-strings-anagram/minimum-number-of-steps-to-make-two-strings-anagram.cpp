class Solution {
public:
    int minSteps(string s, string t) {
        int n=s.length();
        unordered_map<char, int>mpp;
        for(int i=0; i<n; i++){
            mpp[s[i]]++;
        }
        int common=0;
        for(int i=0; i<n; i++){
            if(mpp.find(t[i])!=mpp.end()){
                common++;
                mpp[t[i]]--;
                if(mpp[t[i]]==0) mpp.erase(t[i]);
            }
        }
        return n-common;
    }
    
};