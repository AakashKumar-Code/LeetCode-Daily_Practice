class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto &it:words){
            int sum=0;
            for(char &ch:it){
                sum+=weights[ch-'a'];
            }
            ans+=(25-(sum%26)+'a');
        }
        return ans;
    }
};