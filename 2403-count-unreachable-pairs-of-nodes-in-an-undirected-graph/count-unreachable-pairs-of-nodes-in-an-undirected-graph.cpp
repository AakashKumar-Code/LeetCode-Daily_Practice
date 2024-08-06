class Solution {
public:

    void dfs(int node, long long &cnt, unordered_map<int, vector<int>>&adj, vector<bool>&vis){
        vis[node]=1;
        for(auto &it:adj[node]){
            if(!vis[it]){
                cnt++;
                dfs(it, cnt, adj, vis);
            }
        }
        
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>adj;

        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        long long rem=n;
        long long ans=0;

        vector<bool>vis(n, 0);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                long long cnt=1;
                dfs(i, cnt, adj, vis);
                ans += (cnt) * (rem-cnt);
                rem -= cnt;
            }
        }
        return ans;        
    }
};