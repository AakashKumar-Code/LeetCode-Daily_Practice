class Solution {
public:
    string frequencySort(string s) {
        int n=s.length();
        unordered_map<char, int>mpp;
        for(int i=0; i<n; i++){
            mpp[s[i]]++;
        }

        string ans="";
        vector<pair<int, char>>temp;
        for(auto &it:mpp){
            temp.push_back({it.second, it.first});
        }
        sort(temp.begin(), temp.end(), greater());

        int sz=temp.size();
        for(int i=0; i<sz; i++){
            ans.append(temp[i].first, temp[i].second);
        }

        return ans;
    }
};