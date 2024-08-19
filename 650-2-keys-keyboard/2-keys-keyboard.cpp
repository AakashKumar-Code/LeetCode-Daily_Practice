class Solution {
public:

    int solve(int n){
        for(int i=2; i*i<=n; i++){
            if((n%i)==0){
                int sNo=i;
                int lNo=n/i;
                return sNo+solve(lNo);
            }
        }
        return n;
    }

    int minSteps(int n) {
        if(n==1) return 0;
        return solve(n);        
    }
};