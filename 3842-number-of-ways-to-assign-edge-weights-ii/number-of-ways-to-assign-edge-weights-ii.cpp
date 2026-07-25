class Solution {
public:

    int mod=1e9+7;
    int n;
    int cols;

    unordered_map<int, vector<int>>adj;
    vector<vector<int>>ancestorTable;
    vector<int>depth;

    void dfs(int node, int par){
        ancestorTable[node][0]=par;
        
        for(int &ngbr:adj[node]){
            if(ngbr==par) continue;
            depth[ngbr]=depth[node]+1;
            dfs(ngbr, node);
        }        
    }

    void buildAncestorTable(){
        for(int j=1; j<cols; j++){
            for(int node=0; node<n; node++){
                if(ancestorTable[node][j-1]!=-1){
                    ancestorTable[node][j]=ancestorTable[ancestorTable[node][j-1]][j-1];
                }
            }
        }
    }

    int findLCA(int u, int v){
        if(depth[u]<depth[v]){
            swap(u, v);
        }
        int k=(depth[u]-depth[v]);

        for(int j=0; j<cols; j++){
            if(k&(1<<j)){
                u=ancestorTable[u][j];
            }
        }

        if(u==v) return u;

        for(int j=cols-1; j>=0; j--){
            if(ancestorTable[u][j]==-1) continue;
            if(ancestorTable[u][j]!=ancestorTable[v][j]){
                u=ancestorTable[u][j];
                v=ancestorTable[v][j];
            }
        }

        return ancestorTable[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n=edges.size()+1;
        cols=log2(n)+1;

        for(auto &it:edges){
            int u=it[0]-1;
            int v=it[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        ancestorTable=vector<vector<int>>(n, vector<int>(cols, -1));
        depth=vector<int>(n, 0);
        dfs(0, -1);

        buildAncestorTable();

        vector<int>pow2(n+1);
        pow2[0]=1;
        for(int i=1; i<=n; i++){
            pow2[i]=(2LL*pow2[i-1])%mod;
        }

        vector<int>res;

        for(auto &it:queries){
            int u=it[0]-1;
            int v=it[1]-1;

            int lca=findLCA(u, v);
            int d=depth[u]+depth[v]-2*depth[lca];
            if(d==0){
                res.push_back(0);
            }else{
                res.push_back(pow2[d-1]);
            }
        }

        return res;        
    }
};