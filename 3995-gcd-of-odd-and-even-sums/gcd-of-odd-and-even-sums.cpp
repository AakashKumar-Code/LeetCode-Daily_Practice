class Solution {
public:

    long long gcd(long long a, long long b){
        if((a%b)==0) return b;
        return gcd(b, a%b);
    }

    int gcdOfOddEvenSums(int n) {
        long long odd=(long long)n*n;
        long long even=(long long) n*(n+1);

        return gcd(odd, even);
    }
};