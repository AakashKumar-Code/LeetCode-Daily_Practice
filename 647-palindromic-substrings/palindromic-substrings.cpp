class Solution {
public:

    int n;
    bool solve(int i, int j, string &s){
        if(i>j) return 1;
        if(s[i]==s[j]){
            return solve(i+1, j-1, s);
        }
        return 0;
    }

    int countSubstrings(string s) {
        n=s.length();
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(solve(i, j, s)==1) cnt++;
            }
        }
        return cnt;
    }
};