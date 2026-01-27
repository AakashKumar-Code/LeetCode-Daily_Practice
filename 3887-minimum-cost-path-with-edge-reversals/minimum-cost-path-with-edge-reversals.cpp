class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj[n];
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2*w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<int>dist(n, 1e9);

        dist[0]=0;
        pq.push({0, 0});

        while(!pq.empty()){
            auto [d, node]=pq.top();
            pq.pop();

            for(auto &it:adj[node]){
              int adjN=it[0];
              int adjW=it[1];
              if(dist[adjN]>d+adjW){
                dist[adjN]=d+adjW;
                pq.push({dist[adjN], adjN});
              }
            }
        }

        return dist[n-1]==1e9?-1:dist[n-1];        
    }
};