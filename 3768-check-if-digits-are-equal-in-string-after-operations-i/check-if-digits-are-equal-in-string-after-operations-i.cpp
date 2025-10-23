class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.length()>2){
            int n=s.length();
            string tmp="";
            for(int i=1; i<n; i++){
                tmp+=to_string(((s[i-1]-'0')+(s[i]-'0'))%10);
            }
            s=tmp;
        }
        if(s[0]==s[1]) return true;
        return false;        
    }
};