class Solution {
public:

    int dij(int src, int &n, vector<vector<pair<int, int>>>& adj, int &k){
        int cnt=0;
        priority_queue<pair<int, int>, vector<pair< int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, src});
        vector<int>dist(n, 1e9);
        dist[src]=0;

        while(!pq.empty()){
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();

            for(auto &it:adj[node]){
                int adjN=it.first;
                int adjW=it.second;
                if(wt+adjW<dist[adjN]){
                    dist[adjN]=wt+adjW;
                    pq.push({dist[adjN], adjN});
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (i != src && dist[i] <= k) {
                cnt++;
            }
        }

        return cnt;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<pair<int, int>>> adj(n);

        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int mini=1e9, ans=-1;

        for(int i=0; i<n; i++){
            int tmp=dij(i, n, adj, distanceThreshold);
            if(tmp<=mini){
                mini=tmp;
                ans=i;
            }
        }
        return ans;           
    }
};