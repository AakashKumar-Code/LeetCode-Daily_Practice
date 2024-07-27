class Solution {
public:

    int find(int x, vector<int>&par){
        if(x==par[x]){
            return x;
        }
        return par[x]=find(par[x], par);
    }

    void Union(int x, int y, vector<int>&par, vector<int>&rank){
        int par_x=find(x, par);
        int par_y=find(y, par);

        if(par_x==par_y){
            return;
        }

        if(rank[par_x]>rank[par_y]){
            par[par_y]=par_x;
        }else if(rank[par_x]<rank[par_y]){
            par[par_x]=par_y;
        }else{
            par[par_x]=par_y;
            rank[par_y]++;
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        int e=edges.size();

        vector<int>par(n), rank(n, 0);
        for(int i=0; i<n; i++) par[i]=i;

        for(auto &it:edges){
            Union(it[0], it[1], par, rank);
        }
        
        long long ans=0;

        unordered_map<int, long long>mpp;

        for(int i=0; i<n; i++){
            mpp[find(i, par)]++;
        }

        for(int i=0; i<n; i++){
            ans=(ans+(n-mpp[find(i, par)]));
        }
        return ans/2;       
    }
};