class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0;
        int prevRow=0;
        int n=bank.size();
        int len=bank[0].length();
        for(int i=0; i<len; i++){
            if(bank[0][i]=='1') prevRow++;
        }
        for(int row=1; row<n; row++){
            int cnt=0;
            for(int i=0; i<len; i++){
                if(bank[row][i]=='1') cnt++;
            }
            ans+=(cnt*prevRow);
            if(cnt!=0) prevRow=cnt;
        }
        return ans;
    }
};