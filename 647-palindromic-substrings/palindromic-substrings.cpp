class Solution {
public:

    int n, cnt;

    void solve(int i, int j, string &s){
        while(i>=0 && j<n && s[i]==s[j]){
            cnt++;
            i--;
            j++;
        }
        return;
    }

    int countSubstrings(string s) {
        n=s.length();
        cnt=0;
        for(int i=0; i<n; i++){
            solve(i, i, s);
            solve(i, i+1, s);
        }
        return cnt;
    }
};