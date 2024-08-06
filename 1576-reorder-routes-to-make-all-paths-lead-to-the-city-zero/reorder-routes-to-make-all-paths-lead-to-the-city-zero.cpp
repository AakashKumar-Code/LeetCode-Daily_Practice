class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int, int>>>adj;

        for(auto &it:connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }

        int cnt=0;

        queue<int>q;
        vector<bool>vis(n, 0);
        q.push(0);
        vis[0]=1;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto &it:adj[node]){
                int adjN=it.first;
                int real=it.second;
                if(!vis[adjN]){
                    vis[adjN]=1;
                    q.push(adjN);
                    cnt+=real;
                }
            }
        }
        return cnt;
        
    }
};