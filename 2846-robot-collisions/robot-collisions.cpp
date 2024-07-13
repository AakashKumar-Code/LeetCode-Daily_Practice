class Solution {
public:

    bool static comp(pair<int, int>&a, pair<int, int>&b){
        return a.second<b.second;
    }

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();

        vector<pair<int, int>>p;
        for(int i=0; i<n; i++){
            p.push_back({i, positions[i]});
        }

        sort(p.begin(), p.end(), comp);

        stack<int>st;
        

        for(int i=0; i<n; i++){
            int idx=p[i].first;
            while(!st.empty() && directions[st.top()]=='R' && directions[idx]=='L'){
                int prev=st.top();
                if(healths[prev]==healths[idx]){
                    healths[prev]=0;
                    healths[idx]=0;
                    st.pop();
                    break;
                }else if(healths[prev]<healths[idx]){
                    healths[prev]=0;
                    healths[idx]--;
                    st.pop();
                }else{
                    healths[idx]=0;
                    healths[prev]--;
                    break;
                }
            }
            if(healths[idx]>0) st.push(idx);
        }
        if(st.empty()) return {};
        else if(st.size()==n) return healths;

        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        } 
        sort(ans.begin(), ans.end());
        for(int i=0; i<ans.size(); i++){
            ans[i]=healths[ans[i]];
        }       
        
        return ans;
    }
};