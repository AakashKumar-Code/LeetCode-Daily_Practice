class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int, int>mpp;
        for(int i=0; i<n; i++){
            mpp[arr[i]]++;
        }
        vector<pair<int, int>>v;
        for(auto &it:mpp){
            v.push_back({it.second, it.first});
        }
        sort(v.begin(), v.end());
        int cnt=0;
        int sz=v.size();
        for(int i=0; i<n && k>0; i++){
            if(v[i].first<=k){
                k-=v[i].first;
                v[i].first=0;
            }else{
                v[i].first-=k;
                k=0;
            }
        }
        for(int i=0; i<sz; i++){
            if(v[i].first>0) cnt++;
        }
        return cnt;
    }
};