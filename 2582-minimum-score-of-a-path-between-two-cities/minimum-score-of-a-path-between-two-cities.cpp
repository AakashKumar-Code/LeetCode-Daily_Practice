class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>>adj;

        for(auto &it:roads){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        queue<int>q;
        q.push(1);

        vector<bool>vis(n+1, 0);
        vis[1]=1;

        int mini=INT_MAX;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto &it:adj[node]){
                int adjN=it.first;
                int adjW=it.second;
                mini=min(mini, adjW);
                if(!vis[adjN]){
                    vis[adjN]=1;
                    q.push(adjN);
                }
            }
        }
        return mini;        
    }
};