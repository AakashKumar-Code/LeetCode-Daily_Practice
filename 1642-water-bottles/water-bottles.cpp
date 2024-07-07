class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt=numBottles;
        int eB=numBottles;

        while(eB>=numExchange){
            int fB=eB/numExchange;
            eB%=numExchange;
            cnt+=fB;
            eB+=fB;
        }
        return cnt;
    }
};