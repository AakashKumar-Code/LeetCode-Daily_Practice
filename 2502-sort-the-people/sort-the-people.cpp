class Solution {
public:

    bool static comp(pair<int, int>&a, pair<int, int>&b){
        return a.first>b.first;
    }

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, int>>v;
        int n=heights.size();

        for(int i=0; i<n; i++){
            v.push_back({heights[i], i});
        }

        sort(v.begin(), v.end(), comp);

        vector<string>ans(n);

        for(int i=0; i<n; i++){
            ans[i]=names[v[i].second];
        }
        return ans;
    }
};