class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(int i=0; i<=n; i++){
            unsigned long long num=1<<i;
            if(n==(num)) return 1;
            if(num>n) break;
        }
        return 0;
    }
};