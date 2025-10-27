class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int prev=0;
        for(char &ch:bank[0]){
            if(ch=='1'){
                prev++;
            }
        }
        int ans=0;
        for(int i=1; i<n; i++){
            int curr=0;
            for(char &ch:bank[i]){
                if(ch=='1'){
                    curr++;
                }
            }
            if(curr>0){
                ans+=(prev*curr);
                prev=curr;
            }
        }
        return ans;        
    }
};