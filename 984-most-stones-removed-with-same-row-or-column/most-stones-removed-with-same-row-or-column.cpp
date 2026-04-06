class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
      unordered_map<int, vector<vector<int>>>rows, cols;
      for(auto &it:stones){
        int r=it[0];
        int c=it[1];
        rows[r].push_back(it);
        cols[c].push_back(it);
      }

      set<vector<int>>vis;
      int ans=0;

      for(auto &it:stones){
        if(vis.find(it)!=vis.end()) continue;
        ans++;
        int r=it[0];
        int c=it[1];
        queue<pair<int, int>>q;
        q.push({r, c});
        vis.insert(it);
        while(!q.empty()){
          auto [nr, nc]=q.front();
          q.pop();

          for(auto &it:rows[nr]){
            if(vis.find(it)!=vis.end()) continue;
            q.push({it[0], it[1]});
            vis.insert(it);
          }

          for(auto &it:cols[nc]){
            if(vis.find(it)!=vis.end()) continue;
            q.push({it[0], it[1]});
            vis.insert(it);
          }
        }
      }
      return stones.size()-ans;        
    }
};