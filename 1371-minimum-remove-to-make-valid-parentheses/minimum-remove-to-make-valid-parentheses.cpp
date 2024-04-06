class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        stack<int>st;
        unordered_set<int>t;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                st.push(i);
            }else if(s[i]==')'){
                if(st.empty()) t.insert(i);
                else st.pop();
            }
        }
        while(!st.empty()){
            t.insert(st.top());
            st.pop();
        }
        string ans="";
        for(int i=0; i<n; i++){
            if(t.find(i)==t.end()) ans+=s[i];
        }
        return ans;
    }
};