class Solution {
public:

    void dfs(int node, unordered_map<int, vector<int>>&adj, int &n, vector<int>&vis, stack<int>&st, bool &cycle){
        vis[node]=1;

        for(int &it:adj[node]){
            if(vis[it]==0){
                dfs(it, adj, n, vis, st, cycle);
            }else if(vis[it]==1){
                cycle=1;
                return;
            }
        }

        vis[node]=2;
        st.push(node);
    }

    vector<int> topoSort(vector<vector<int>>&edges, int &n){
        unordered_map<int, vector<int>>adj;
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }

        vector<int>vis(n+1, 0);

        stack<int>st;
        bool cycle=0;

        for(int i=1; i<=n; i++){
            if(vis[i]==0){
                dfs(i, adj, n, vis, st, cycle);
                if(cycle) return {};
            }
        }
        vector<int>order;

        while(!st.empty()){
            order.push_back(st.top());
            st.pop();
        }
        return order;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, 
    vector<vector<int>>& colConditions) {

        vector<int>topoRow=topoSort(rowConditions, k);
        vector<int>topoCol=topoSort(colConditions, k);

        if(topoRow.empty() || topoCol.empty()){
            return {};
        }

        vector<vector<int>>ans(k, vector<int>(k, 0));

        for(int i=0; i<k; i++){
            for(int j=0; j<k; j++){
                if(topoRow[i]==topoCol[j]){
                    ans[i][j]=topoRow[i];
                }
            }
        }

        return ans;   
        
    }
};