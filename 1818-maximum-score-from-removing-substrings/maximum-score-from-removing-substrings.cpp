class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n=s.length();
        stack<char>st;
        int ans=0;

        if(x>y){
            for(int i=0; i<n; i++){
                if(s[i]=='b' && !st.empty() && st.top()=='a'){
                    ans+=x;
                    st.pop();
                }else st.push(s[i]);
            }

            s="";

            while(!st.empty()){
                s+=st.top();
                st.pop();
            }
            int n=s.length();

            reverse(s.begin(), s.end());

            for(int i=0; i<n; i++){
                if(s[i]=='a' && !st.empty() && st.top()=='b'){
                    ans+=y;
                    st.pop();
                }else st.push(s[i]);
            }
        }else{
            for(int i=0; i<n; i++){
                if(s[i]=='a' && !st.empty() && st.top()=='b'){
                    ans+=y;
                    st.pop();
                }else st.push(s[i]);
            }

            s="";

            while(!st.empty()){
                s+=st.top();
                st.pop();
            }
            int n=s.length();

            reverse(s.begin(), s.end());

            for(int i=0; i<n; i++){
                if(s[i]=='b' && !st.empty() && st.top()=='a'){
                    ans+=x;
                    st.pop();
                }else st.push(s[i]);
            }
        }

        return ans;

    }
};