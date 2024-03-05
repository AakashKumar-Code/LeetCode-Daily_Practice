class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        if(n==1) return 1;
        int i=0, j=n-1;
        while(i<=j){
            if(s[i]==s[j]){
                char ch=s[i];
                while(i<=j && s[i]==ch){
                    i++;
                }
                while(i<=j && s[j]==ch){
                    j--;
                }
                if(i==j) return 1;
            }else break;
        }
        return j-i+1;
    }
};