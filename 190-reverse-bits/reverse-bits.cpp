class Solution {
public:
    int reverseBits(int n) {
        int i=0, ans=0;
        while(n>0){
            ans+=((n%2)*(pow(2, 31-i)));
            n/=2;
            i++;
        }      
        return ans;    
    }
};