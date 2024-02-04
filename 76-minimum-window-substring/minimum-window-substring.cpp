class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>mpp;
        if(t.length()>s.length()) return "";
        for(auto &it:t){
            mpp[it]++;
        }
        int n=s.length();

        int i=0, j=0, start=0, mini=1e9;
        int cnt=mpp.size();

        for(; j<n; j++){
            if(mpp.find(s[j])!=mpp.end()){
                mpp[s[j]]--;
                if(mpp[s[j]]==0) cnt--;
            }
            for(; i<n && cnt==0; i++){
                if(cnt==0){
                    if(j-i+1<mini){
                        start=i;
                        mini=j-i+1;
                    }
                }
                    
                if(mpp.find(s[i])!=mpp.end()){
                    mpp[s[i]]++;
                    if(mpp[s[i]]==1) cnt++;
                }
            }
        }
        return mini==1e9?"":s.substr(start, mini);
    }
};