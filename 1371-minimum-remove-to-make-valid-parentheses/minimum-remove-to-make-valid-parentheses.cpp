class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        int open=0, close=0;
        unordered_set<int>st;

        for(int i=0; i<n; i++){
            if(s[i]=='('){
                open++;
            }else if(s[i]==')'){
                if(open>0) open--;
                else st.insert(i);
            }

            if(s[n-i-1]==')'){
                close++;
            }else if(s[n-i-1]=='('){
                if(close>0) close--;
                else st.insert(n-i-1);
            }
        }
        string ans="";
        for(int i=0; i<n; i++){
            if(st.find(i)==st.end()) ans+=s[i];
        }
        return ans;
    }
};