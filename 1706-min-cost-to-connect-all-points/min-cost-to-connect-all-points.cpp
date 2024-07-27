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
        
        if(par_x==par_y) return;
        
        if(rank[par_x]>rank[par_y]){
            par[par_y]=par_x;
        }else if(rank[par_x]<rank[par_y]){
            par[par_x]=par_y;
        }else{
            par[par_x]=par_y;
            rank[par_y]++;
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();

        vector<vector<int>>vec;

        for(int i=0; i<n; i++){
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=0; j<n; j++){
                if(i==j) continue;
                int x2=points[j][0];
                int y2=points[j][1];

                int wt=abs(x2-x1)+abs(y2-y1);
                vec.push_back({wt, i, j});                
            }
        }
        sort(vec.begin(), vec.end());

        int ans=0;
        vector<int>par(n), rank(n, 0);
        
        for(int i=0; i<n; i++) par[i]=i;
        
        for(auto &it:vec){
            int u=it[1];
            int v=it[2];
            int wt=it[0];
            
            int par_u=find(u, par);
            int par_v=find(v, par);
            
            if(par_u!=par_v){
                ans+=wt;
                Union(u, v, par, rank);
            }
        }
        return ans;
        
    }
};