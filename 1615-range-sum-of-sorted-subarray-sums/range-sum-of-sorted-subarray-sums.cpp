class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long>tmp;
        long long mod=1e9+7;

        for(int i=0; i<n; i++){
            long long sum=0;
            for(int j=i; j<n; j++){
                sum+=nums[j];
                tmp.push_back(sum);
            }
        }
        sort(tmp.begin(), tmp.end());
        long long ans=0;
        for(int i=left-1; i<=right-1; i++){
            ans=(ans+tmp[i])%mod;
        }
        return ans;
        
    }
};