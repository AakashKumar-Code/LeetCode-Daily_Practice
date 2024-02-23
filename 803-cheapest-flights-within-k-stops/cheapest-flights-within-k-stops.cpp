class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>>adj[n];
        int paths=flights.size();

        for(int i=0; i<paths; i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int cost=flights[i][2];
            adj[u].push_back({v, cost});
        }

        vector<int>minCost(n, 1e9);
        queue<pair<int, pair<int, int>>>q;
        q.push({0, {src, 0}});
        minCost[src]=0;

        while(!q.empty()){
            int numOfStop=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();
            if(numOfStop>k) continue;
            for(auto &it:adj[node]){
                int adjN=it.first;
                int adjCost=it.second;
                if(cost+adjCost<minCost[adjN]){
                    minCost[adjN]=cost+adjCost;
                    q.push({numOfStop+1, {adjN, minCost[adjN]}});
                }
            }
        }

        return minCost[dst]==1e9?-1:minCost[dst];
    }
};