class Solution {
public:

    double bfs(string x, string y, unordered_map<string, vector<pair<string, double>>>&adj){
        queue<pair<string, double>>q;
        unordered_set<string>vis;
        vis.insert(x);
        q.push({x, 1.0});

        while(!q.empty()){
            auto it=q.front();
            q.pop();

            string node=it.first;
            double wt=it.second;

            if(node==y) return wt;

            for(auto &it:adj[node]){
                string adjN=it.first;
                double adjW=it.second;
                if(vis.find(adjN)==vis.end()){
                    vis.insert(adjN);
                    q.push({adjN, wt*adjW});
                }
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, 
    vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>>adj;

        int n=equations.size();

        for(int i=0; i<n; i++){
            string u=equations[i][0];
            string v=equations[i][1];
            double wt=values[i];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, 1/wt});
        }

        int sz=queries.size();

        vector<double>ans;

        for(int q=0; q<sz; q++){
            string x=queries[q][0];
            string y=queries[q][1];

            if(adj.find(x)==adj.end() || adj.find(y)==adj.end()){
                ans.push_back(-1.0);
            }else if(x==y){
                ans.push_back(1.0);
            }else{
                ans.push_back(bfs(x, y, adj));
            }
        }

        return ans;
        
    }
};