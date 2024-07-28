class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int>adj[n+1];

        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>min1(n+1, 1e9), min2(n+1, 1e9);
        min1[1]=0;

        queue< pair<int, int> >pq;
        pq.push({0, 1});

        while(!pq.empty()){
            auto it=pq.front();
            pq.pop();
            int u=it.second;
            int timeElapsed=it.first;

            if(min2[n]!=1e9) return min2[n];

            int div=timeElapsed/change;
            if(div%2==1){
                timeElapsed=((div+1)*change);
            }

            for(auto &it:adj[u]){
                int v=it;
                int vArrivalTime=timeElapsed+time;
                if(vArrivalTime<min1[v]){
                    min2[v]=min1[v];
                    min1[v]=vArrivalTime;
                    pq.push({min1[v], v});
                }else if(vArrivalTime>min1[v] && vArrivalTime<min2[v]){
                    min2[v]=vArrivalTime;
                    pq.push({min2[v], v});
                }
            }            
        }
        return -1;
    }
};