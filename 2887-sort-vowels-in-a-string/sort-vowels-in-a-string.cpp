class Solution {
public:
    string sortVowels(string s) {
        string vow="";
        int n=s.length();
        for(int i=0; i<n; i++){
            char ch=s[i];
            if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'
            || ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                vow+=ch;
                s[i]='*';
            }
        }
        sort(vow.begin(), vow.end());
        int x=vow.length();
        int ind=0;
        for(int i=0; i<n; i++){
            if(s[i]=='*'){
                s[i]=vow[ind];
                ind++;
                if(ind==x) break;
            }
        }
        return s;
    }
};