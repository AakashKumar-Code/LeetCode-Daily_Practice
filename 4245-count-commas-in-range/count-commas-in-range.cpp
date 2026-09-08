class Solution {
public:
    int countCommas(int n) {
        int ans=0;
        for(int i=1; i<=n; i++){
            int num=i;
            int cnt=0;
            while(num){
                num/=10;
                cnt++;
            }
            ans+=((cnt-1)/3);
        }
        return ans;
    }
};