class Solution {
public:
    int numSteps(string s) {
        int n=s.length();
        int ops=0;
        int c=0;
        for(int i=n-1; i>=1 ;i--){
            if(((s[i]-'0')+c)%2==1){
                ops+=2;
                c=1;
            }else ops++;
        }
        return ops+c;
    }
};