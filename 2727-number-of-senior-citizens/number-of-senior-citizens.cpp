class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(string &it:details){
            if((it[11]>='7') || (it[11]>='6' && it[12]>'0')) ans++;
        }
        return ans;
        
    }
};