class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int>temp=score;
        sort(temp.begin(), temp.end(), greater<int>());
        unordered_map<int, string>mpp;
        int n=temp.size();

        if(n>=1) mpp[temp[0]]="Gold Medal";
        if(n>=2) mpp[temp[1]]="Silver Medal";
        if(n>=3) mpp[temp[2]]="Bronze Medal";

        for(int i=3; i<n; i++){
            mpp[temp[i]]=to_string(i+1);
        }

        vector<string>ans(n);
        for(int i=0; i<n; i++){
            ans[i]=mpp[score[i]];
        }

        return ans;
    }
};