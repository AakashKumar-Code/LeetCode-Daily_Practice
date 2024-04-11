class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n=num.size();
        if(k==n) return "0";

        st.push(num[0]);

        for(int i=1; i<n; i++){
            while(!st.empty() && st.top()>num[i] && k>0){
                st.pop();
                k--;
            }
            if(n-i==k){
                k--;
                continue;
            }
            st.push(num[i]);
        }
        string ans="";

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        
        if(ans[0]=='0'){
            int i=0;
            while(i<ans.length() && ans[i]=='0'){
                i++;
            }
            if(i==ans.size()) return "0";
            return ans.substr(i, ans.length()-i);
        }

        return ans;
       
    }
};