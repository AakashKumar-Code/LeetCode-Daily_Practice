class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt=0;
        int n=s.length();
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                cnt++;
                s[i]='0';
            }
        }

        s[n-1]='1';
        cnt--;
        int i=0;
        while(cnt){
            s[i++]='1';
            cnt--;
        }
        return s;

    }
};