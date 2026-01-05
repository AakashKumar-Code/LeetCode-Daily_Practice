class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        long long sum=0;
        int cnt=0, mini=1e9;
        bool isZero=false;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int num=matrix[i][j];
                if(num==0) isZero=true;
                sum+=abs(num);
                mini=min(abs(num), mini);
                if(num<0){
                    cnt++;
                }
            }
        }
        if(isZero) return sum;

        return (cnt%2==0)?sum:sum-2*mini;
        
    }
};