class Solution {
public:

    int dfs(int curr, int par, vector<int>adj[], vector<bool>&hasApple){
        int time=0;
        for(auto &child:adj[curr]){
            if(child==par) continue;
            int time_from_child=dfs(child, curr, adj, hasApple);
            if(time_from_child>0 || hasApple[child]==1){
                time+=(2+time_from_child);
            }
        }
        return time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int>adj[n];

        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(0, -1, adj, hasApple);
        
    }
};