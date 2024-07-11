class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.length();
        stack<string>st;

        for(int i=0; i<n; i++){
            if(s[i]=='('){
                string ch="";
                ch+=s[i];
                st.push(ch);
            }else if(s[i]>='a' && s[i]<='z'){
                string ch="";
                ch+=s[i];
                st.push(ch);
            }else{
                string temp="";
                while(!st.empty() && st.top()!="("){
                    temp+=st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop();
                reverse(temp.begin(), temp.end());
                st.push(temp);
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};