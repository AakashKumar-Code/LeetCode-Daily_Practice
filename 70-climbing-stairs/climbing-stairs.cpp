class Solution {
public:

    int climbStairs(int n) {
        int one=1;
        int zero=1;
        for(int i=2; i<=n; i++){
            int ways=one+zero;
            zero=one;
            one=ways;
        }
        return one;
    }
};