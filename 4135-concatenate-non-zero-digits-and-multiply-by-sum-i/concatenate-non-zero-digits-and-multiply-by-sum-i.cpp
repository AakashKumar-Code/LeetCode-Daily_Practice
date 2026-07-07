class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0, num=0;
        for(int i=1e9; i>=1; i/=10){
            int x=((n/i)%10);
            if(x>0){
                num=(num*10)+x*1LL;
                sum+=x;
            }
        }
        return num*sum;
    }
};