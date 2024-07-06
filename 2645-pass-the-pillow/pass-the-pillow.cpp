class Solution {
public:
    int passThePillow(int n, int time) {
        int N=n-1;
        int fR=time/N;
        int rT=time%N;
        if(fR%2==0){
            return rT+1;
        }else return n-rT;
    }
};