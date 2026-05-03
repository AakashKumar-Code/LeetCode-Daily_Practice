class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        string tmp=s;
        tmp+=s;
        int i=0;
        while(i<n){
            if(tmp.substr(i, n)==goal) return true;
            i++;
        }
        return false;        
    }
};