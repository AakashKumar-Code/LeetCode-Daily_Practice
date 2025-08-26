class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxi=0, maxD=0;
        for(auto &it:dimensions){
            int l=it[0];
            int b=it[1];
            int d=l*l+b*b;
            if(d>maxD){
                maxD=d;
                maxi=l*b;
            }else if(maxD==d) maxi=max(maxi, l*b);
        }
        return maxi;        
    }
};