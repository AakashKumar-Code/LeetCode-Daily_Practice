class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int>mpp;
        int n=s.length();
        int mini=1e9;
        for(int i=0; i<n; i++){
            if(mpp.find(s[i])==mpp.end()){
                mpp[s[i]]=i;
            }else{
                mpp[s[i]]=1e9;
            }
        }
        for(auto &it:mpp){
            mini=min(mini, it.second);
        }
        return mini==1e9?-1:mini;      
        
        
    }
};