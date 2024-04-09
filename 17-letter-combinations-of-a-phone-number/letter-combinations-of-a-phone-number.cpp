class Solution {
public:

    int n;

    void solve(int i, string &digits, string mapping[], string temp, vector<string>&ans){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        int ind=digits[i]-'0';
        string val=mapping[ind];
        for(int j=0; j<val.length(); j++){
            temp.push_back(val[j]);
            solve(i+1, digits, mapping, temp, ans);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        string mapping[10]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        n=digits.length();
        vector<string>ans;
        string temp="";
        solve(0, digits, mapping, temp, ans);
        return ans;
        
    }
};