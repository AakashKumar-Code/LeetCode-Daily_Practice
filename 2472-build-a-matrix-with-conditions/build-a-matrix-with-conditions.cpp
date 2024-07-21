class Solution {
public:    
    vector<int> topoSort(vector<vector<int>>&edges, int &n){
        unordered_map<int, vector<int>>adj;
        vector<int>indegree(n+1, 0);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            indegree[v]++;
            adj[u].push_back(v);
        }

        int cnt=0;

        queue<int>q;
        for(int i=1; i<=n; i++){
            if(indegree[i]==0){
                q.push(i);
                cnt++;
            }
        }

        vector<int>ans;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            

            for(int &it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    cnt++;
                }
            }
        }

        if(cnt==n) return ans;
        else return {};

        
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