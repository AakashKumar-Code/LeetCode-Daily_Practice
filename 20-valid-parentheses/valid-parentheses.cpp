class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char ch:s){
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }else{
                if(!st.empty() && ((ch==')' && st.top()=='(')
                || (ch=='}' && st.top()=='{')
                || (ch==']' && st.top()=='['))) st.pop();
                else return 0;
            }
        }
        return st.empty();
        
    }
};