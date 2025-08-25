class Solution {
public:

    int n, m;
    bool check(int r, int c){
        if(r>=0 && r<n && c>=0 && c<m) return true;
        return false;
    }

    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();
        vector<int>ans;        

        int tot=n+m-2;

        for(int t=0; t<=tot; t++){
            if(t%2){
                for(int r=0; r<=t; r++){
                    if(check(r, t-r)){
                        ans.push_back(mat[r][t-r]);
                    }
                }
            }else{
                for(int c=0; c<=t; c++){
                    if(check(t-c, c)){
                        ans.push_back(mat[t-c][c]);
                    }                    
                }
            }
        }

        return ans;        
    }
};