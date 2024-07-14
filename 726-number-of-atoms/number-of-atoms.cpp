class Solution {
public:
    string countOfAtoms(string formula) {
        int n=formula.length();

        stack<unordered_map<string, int>>st;
        st.push(unordered_map<string, int>());

        int i=0;

        while(i<n){
            if(formula[i]=='('){
                st.push(unordered_map<string, int>());
                i++;
            }else if(formula[i]==')'){
                unordered_map<string, int>mp1=st.top();
                st.pop();
                i++;

                string mult;
                while(i<n && isdigit(formula[i])){
                    mult.push_back(formula[i]);
                    i++;
                }

                if(!mult.empty()){
                    int multInt=stoi(mult);
                    for(auto &it:mp1){
                        string f=it.first;
                        int s=it.second;
                        mp1[f]=s*multInt;
                    }
                }

                for(auto &it:mp1){
                    string f=it.first;
                    int s=it.second;
                    st.top()[f]+=s;
                }
            }else{
                string curr;
                curr.push_back(formula[i]);
                i++;
                while(i<n && isalpha(formula[i]) && islower(formula[i])){
                    curr.push_back(formula[i]);
                    i++;
                }

                string cnt;
                while(i<n && isdigit(formula[i])){
                    cnt.push_back(formula[i]);
                    i++;
                }

                int cntInt= cnt.empty()?1:stoi(cnt);
                st.top()[curr]+=cntInt;
            }
        }

        map<string, int>mp(st.top().begin(), st.top().end());
        string ans;

        for(auto &it:mp){
            string f=it.first;
            ans+=f;
            int s=it.second;
            if(s>1) ans+=to_string(s);
        }
        return ans;
    }
};