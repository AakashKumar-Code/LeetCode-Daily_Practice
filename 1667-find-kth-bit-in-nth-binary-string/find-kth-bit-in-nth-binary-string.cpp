class Solution {
public:
    char findKthBit(int n, int k) {
        string s="0";

        for(int i=2; i<=n; i++){
            string tmp=s;
            tmp+="1";
            reverse(s.begin(), s.end());
            for(char &ch:s){
                if(ch=='1'){
                    tmp+="0";
                }else tmp+="1";
            }
            s=tmp;
        }

        return s[k-1];        
    }
};