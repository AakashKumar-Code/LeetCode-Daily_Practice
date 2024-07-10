class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt=0;

        int n=logs.size();
        for(int i=0; i<n; i++){
            if(logs[i][0]=='.'){
                if(logs[i][1]=='.') cnt<=0?cnt=0:cnt-=1;
            }else cnt+=1;
        }

        return cnt<=0?0:cnt;
        
    }
};