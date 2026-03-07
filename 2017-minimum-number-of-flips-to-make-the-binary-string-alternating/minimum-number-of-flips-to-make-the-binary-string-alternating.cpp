class Solution {
public:

    int comp(int n, string tmp, string x){
        int mini=1e9, cnt=0;

        int i=0, j=0;

        for(; j<2*n; j++){
            if(tmp[j]!=x[j]) cnt++;
            for(; i<2*n && (j-i+1>n); i++){
                if(tmp[i]!=x[i]) cnt--;
            }
            if(j-i+1==n) mini=min(mini, cnt);
        }

        return mini;
    }

    int minFlips(string s) {
        string tmp=s;
        tmp+=s;

        int n=s.length();

        int one=1;

        string t1="", t2="";

        for(int i=0; i<2*n; i++){
            t1+=to_string(one);
            t2+=to_string(1-one);
            one=1-one;
        }

        return min(comp(n, tmp, t1), comp(n, tmp, t2));       
        
    }
};