class Solution {
public:
    string decodeString(string s) {
        int n=s.length();

        stack<string>st;
        // string prevS=="";

        string currS="";
        int currNo=0;

        for(int i=0; i<n; i++){
            if(s[i]>='0' && s[i]<='9'){
                currNo=(currNo*10)+(s[i]-'0');
            }else if(s[i]>='a' && s[i]<='z'){
                currS+=s[i];
            }else if(s[i]=='['){
                st.push(currS);
                st.push(to_string(currNo));
                currS="";
                currNo=0;
            }else{
                int prevNo=stoi(st.top());
                st.pop();
                string prevS=st.top();
                st.pop();
                string temp="";
                for(int j=0; j<prevNo; j++){
                    temp+=currS;
                }
                currS=prevS+temp;
            }
        }
        return currS;
    }
};