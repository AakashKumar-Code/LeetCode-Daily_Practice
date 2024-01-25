class Solution {
public:
    int reverse(int x) {
        int temp=x;
        bool neg=0;
        if(temp<0){
            neg=1;
            temp=abs(temp);
        }
        int ans=0;
        while(temp){
            if(ans>INT_MAX/10) return 0;
            ans=(ans*10)+(temp%10);
            //if(ans>INT_MAX) return 0;
            temp/=10;
        }
        if(neg) ans*=-1;
        return ans;
    }
};