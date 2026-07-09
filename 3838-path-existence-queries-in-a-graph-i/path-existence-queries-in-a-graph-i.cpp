class Solution {
public:

    vector<int>par, rank;
    int findP(int u){
        if(par[u]==u){
            return u;
        }
        return par[u]=findP(par[u]);
    }

    void uni(int u, int v){
        int pu=findP(u);
        int pv=findP(v);
        if(rank[pu]>rank[pv]){
            par[pv]=pu;
        }else if(rank[pu]<rank[pv]){
            par[pu]=pv;
        }else{
            par[pu]=pv;
        }
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        par=vector<int>(n);
        rank=vector<int>(n, 1);

        for(int i=0; i<n; i++) par[i]=i;

        priority_queue<pair<int, int>>pq;

        for(int i=0; i<n; i++){
            pq.push({nums[i], i});
        }

        pair<int, int>tmp=pq.top();

        while(!pq.empty()){
            pair<int, int>curr=pq.top();
            pq.pop();

            if(abs(tmp.first-curr.first)<=maxDiff){
                uni(tmp.second, curr.second);
            }
            tmp=curr;
        }

        int q=queries.size();

        vector<bool>ans;

        for(auto &it:queries){
            int pu=findP(it[0]);
            int pv=findP(it[1]);
            if(pu==pv){
                ans.push_back(true);
            }else ans.push_back(false);
        }

        return ans;        
    }
};