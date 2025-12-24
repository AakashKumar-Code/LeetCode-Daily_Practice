class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].length();

        unordered_set<int>st;       
        bool found=0;

        do{
            found=0;
            for(int i=1; i<n; i++){
                for(int j=0; j<m; j++){
                    if(st.find(j)!=st.end()) continue;
                    if(strs[i-1][j]>strs[i][j]){
                        st.insert(j);
                        found=1;
                        break;
                    }else if(strs[i-1][j]<strs[i][j]) break;
                }
                if(found) break;
            }
        }while(found);

        return st.size();
        
    }
};