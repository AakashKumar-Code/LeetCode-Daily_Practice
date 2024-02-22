class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n<=1) return 1;
        unordered_map<int, vector<int>>mp1, mp2;
        int sz=trust.size();
        for(int i=0; i<sz; i++){
            int u=trust[i][0];
            int v=trust[i][1];
            mp1[u].push_back(v);
            if(mp1.find(v)==mp1.end()) mp2[v].push_back(u);
        }

        for(auto &it:mp2){
            int v=it.first;
            if(mp1.find(v)==mp1.end() && it.second.size()==n-1) return v;
        }
        return -1;
    }
};