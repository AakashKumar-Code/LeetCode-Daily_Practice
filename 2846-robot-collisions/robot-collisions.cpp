class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();

        vector<pair<int, int>>v;

        for(int i=0; i<n; i++){
            v.push_back({positions[i], i});
        }

        sort(v.begin(), v.end());

        stack<int>st;

        for(int i=0; i<n; i++){
            int x=v[i].second;
            while(!st.empty() && (directions[x]=='L' && directions[st.top()]=='R')){
                int y=st.top();
                if(healths[x]==healths[y]){
                    healths[x]=0;
                    healths[y]=0;
                    st.pop();
                    break;
                }else if(healths[x]>healths[y]){
                    healths[x]--;
                    healths[y]=0;
                    st.pop();
                }else{
                    healths[y]--;
                    healths[x]=0;
                    break;
                }
            }
            if(healths[x]>0) st.push(x);
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