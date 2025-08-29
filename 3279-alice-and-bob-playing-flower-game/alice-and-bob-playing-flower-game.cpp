class Solution {
public:
    long long flowerGame(int n, int m) {
        unsigned long long o1=n/2+n%2;
        unsigned long long e1=n/2;
        unsigned long long o2=m/2+m%2;
        unsigned long long e2=m/2;
        unsigned long long ans=o1*e2+o2*e1;
        return ans;
    }
};