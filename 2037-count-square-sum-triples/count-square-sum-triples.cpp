class Solution {
public:
    int countTriples(int n) {
        int cnt=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int t=i*i+j*j;
                int s=sqrt(t);
                if(s*s==t && s<=n) cnt++;
            }
        }
        return cnt;        
    }
};