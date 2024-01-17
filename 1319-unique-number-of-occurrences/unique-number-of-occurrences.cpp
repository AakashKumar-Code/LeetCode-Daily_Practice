class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int>mp1;
        unordered_set<int>mp2;
        int n=arr.size();
        
        for(int i=0; i<n; i++){
            mp1[arr[i]]++;
        }

        for(auto &it:mp1){
            if(mp2.find(it.second)!=mp2.end()) return 0;
            mp2.insert(it.second);
        }
        return 1;
    }
};