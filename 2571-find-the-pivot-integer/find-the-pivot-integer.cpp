class Solution {
public:
    int pivotInteger(int n) {
        int temp=((n*(n+1))/2);
        int x=sqrt(temp);
        return x*x==(temp)?x:-1;
    }
};