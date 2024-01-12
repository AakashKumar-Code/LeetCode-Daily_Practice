class Solution {
public:

    bool isV(char &ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || 
        ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U') return 1;
        else return 0;
    }

    bool halvesAreAlike(string s) {
        int cnt1=0, cnt2=0;
        int n=s.length()/2;
        for(int i=0; i<n; i++){
            if(isV(s[i])) cnt1++;
            if(isV(s[i+n])) cnt2++;
        }
        return cnt1==cnt2;
    }
};