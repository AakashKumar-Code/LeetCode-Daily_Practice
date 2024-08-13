class Solution {
public:

    bool static comp(pair<int, int>a, pair<int, int>b){
        if(a.first>b.first) return 1;
        else if(a.first==b.first) return a.second<b.second;
        return 0;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        long long tot_gas=0, tot_cost=0;
        for(int i=0; i<n; i++){
            tot_gas+=gas[i];
            tot_cost+=cost[i];
        }
        if(tot_gas<tot_cost) return -1;

        int st=0;
        int tot=0;
        for(int i=0;i<n;i++){
            tot+=(gas[i]-cost[i]);
            if(tot<0){
                tot=0;
                st=i+1;
            }
        }
        return st;      
    }


    
};