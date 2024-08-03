class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();

        queue<pair<int, vector<int>>>q;

        q.push({0, {0}});
        vector<vector<int>>ans;

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int node=it.first;
            vector<int>path=it.second;
            if(node==n-1){
                ans.push_back(path);
                continue;
            }

            for(auto &ngbr:graph[node]){
                vector<int>temp=path;
                temp.push_back(ngbr);
                q.push({ngbr, temp});
            }
        }
        return ans;        
    }
};