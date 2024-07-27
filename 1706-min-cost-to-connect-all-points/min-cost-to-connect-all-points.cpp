class Solution {
public:

    #define P pair<int, int>

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();

        vector<vector<int>>adj[n];

        for(int i=0; i<n; i++){
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=0; j<n; j++){
                if(i==j) continue;
                int x2=points[j][0];
                int y2=points[j][1];

                int wt=abs(x2-x1)+abs(y2-y1);
                adj[i].push_back({j, wt});
                
            }
        }

        priority_queue< P, vector<P>, greater<P> >pq;
        int ans=0;

        pq.push({0, 0});
        vector<bool>vis(n, 0);

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            int node=it.second;
            int wt=it.first;

            if(vis[node]) continue;
            else{
                vis[node]=1;
                ans+=wt;
            }

            for(auto it:adj[node]){
                if(!vis[it[0]]){
                    pq.push({it[1], it[0]});
                }
            }
        }
        return ans;
        
    }
};