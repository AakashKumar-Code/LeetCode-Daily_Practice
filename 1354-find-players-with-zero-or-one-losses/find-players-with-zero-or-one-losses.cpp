class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
        map<int, int>lost;
        set<int>winners;

        for(int i=0; i<n; i++){
            lost[matches[i][1]]++;
            winners.insert(matches[i][0]);
        }
        vector<int>zero, one;
        for(auto &it:winners){
            if(lost[it]==0){
                zero.push_back(it);
            }
        }
        for(auto &it:lost){
            if(it.second==1){
                one.push_back(it.first);
            }
        }
        return {zero, one};
    }
};