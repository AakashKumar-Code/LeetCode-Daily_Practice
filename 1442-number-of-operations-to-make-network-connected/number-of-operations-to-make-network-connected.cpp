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

    int makeConnected(int n, vector<vector<int>>& connections) {

        int e=connections.size();
        if(e<n-1) return -1;

        int components=n;

        vector<int>par(n), rank(n, 0);

        for(int i=0; i<n; i++){
            par[i]=i;
        }

        for(int i=0; i<e; i++){
            int u=connections[i][0];
            int v=connections[i][1];

            int u_par=find(u, par);
            int v_par=find(v, par);
            if(u_par!=v_par){
                Union(u, v, par, rank);
                components--;
            }
        }
        return components-1;        
    }
};