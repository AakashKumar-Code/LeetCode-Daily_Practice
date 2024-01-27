class Solution {
public:

    int mod=1e9+7;

    int kInversePairs(int n, int k) {
        if(k==0) return 1;
        vector<int>prev(k+1, 0), curi(k+1, 0);
        prev[0]=1;
        curi[0]=1;
        for(int i=1; i<=n; i++){
            long long sum=1;
            for(int j=1; j<=k; j++){
                sum+=prev[j];
                if(j>=i) sum-=prev[j-i];
                curi[j]=sum%mod;
            }
            prev=curi;
        }
        return prev[k];
    }
};