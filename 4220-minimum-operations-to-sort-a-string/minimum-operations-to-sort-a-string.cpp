class Solution {
public:

    bool isSorted(string s){
        char prev='a';
        for(char &ch:s){
            if(prev>ch) return false;
            else prev=ch;
        }
        return true;
    }

    int minOperations(string s) {
        int n=s.length();

        if(n==1) return 0;
        else if(n==2){
            if(s[0]<=s[1]) return 0;
            else return -1;
        }else{
            if(isSorted(s)) return 0;
            string tmp1=s, tmp2=s;
            sort(tmp1.begin(), tmp1.end()-1);
            sort(tmp2.begin()+1, tmp2.end());
            if(isSorted(tmp1) || isSorted(tmp2)) return 1;  
            sort(tmp2.begin(), tmp2.end()-1);
            sort(tmp1.begin()+1, tmp1.end());   
            if(isSorted(tmp1) || isSorted(tmp2)) return 2;
            return 3;        
        }

        return -1;        
    }
};