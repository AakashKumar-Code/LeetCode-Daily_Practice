class Solution {
public:

    void bellman_ford(int src, int &n, vector<vector<int>>&e, vector<int>&dist){
        dist[src]=0;

        for(int k=1; k<=n-1; k++){
            for(auto &it:e){
                int u=it[0];
                int v=it[1];
                int wt=it[2];

                if(dist[u]!=INT_MAX && dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                }
                if(dist[v]!=INT_MAX && dist[v]+wt<dist[u]){
                    dist[u]=dist[v]+wt;
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>mat(n, vector<int>(n, INT_MAX));

        for(int i=0; i<n; i++){
            bellman_ford(i, n, edges, mat[i]);
        }

        int ans=-1, mini=INT_MAX;

        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=0; j<n; j++){
                if(i!=j && mat[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(mini>=cnt){
                mini=cnt;
                ans=i;
            }
        }
        return ans;

    }
};