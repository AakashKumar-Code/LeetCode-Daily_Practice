class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.length();
        int h=n/2;
        string tmp;
        for(int i=0; i<h; i++){
            tmp+=s[i];
        }
        sort(tmp.begin(), tmp.end());
        string rev=tmp;
        if((n%2)==1){
            tmp+=s[n/2];
        }
        reverse(rev.begin(), rev.end());
        return tmp+rev;
    }
};