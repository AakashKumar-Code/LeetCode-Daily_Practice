class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(costBoth>=cost1+cost2){
            return (long long)((long long)need1*(long long)cost1)+(long long)((long long)need2*(long long)cost2);
        }else{
            long long both=min(need1, need2);
            long long total=both*(long long)costBoth;
            need1-=both;
            need2-=both;
            if(need1>0){
                total+=(long long)need1*(long long)min(cost1, costBoth);
            }else if(need2>0){
                total+=(long long)need2*(long long)min(cost2, costBoth);
            }
            return total;
        }
        return 0;
    }
};