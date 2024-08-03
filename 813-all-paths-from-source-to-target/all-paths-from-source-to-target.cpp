class Solution {
public:

    void dfs(int node, int t, vector<vector<int>>& graph, vector<int>&tmp, 
    vector<vector<int>>&ans){
        tmp.push_back(node);
        if(node==t){
            ans.push_back(tmp);
        }else{
            for(int &ngbr:graph[node]){
                dfs(ngbr, t, graph, tmp, ans);
            }
        }
        tmp.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<vector<int>>ans;
        vector<int>tmp;

        dfs(0, n-1, graph, tmp, ans); 
        return ans;       
    }
};