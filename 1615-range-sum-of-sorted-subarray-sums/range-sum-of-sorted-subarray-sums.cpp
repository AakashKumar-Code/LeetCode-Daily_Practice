class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue< pair<long long, int>, vector<pair<long long, int>>, 
        greater<pair<long long,int>> >pq;
        
        for(int i=0; i<n; i++){
            pq.push({ nums[i], i});
        }
        
        long long mod=1e9+7;
        vector<long long>tmp;
        int cnt=right;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            long long sum=it.first;
            int ind=it.second;
            tmp.push_back(sum);
            cnt--;
            if(cnt==0) break;

            if(ind<n-1){
                sum=(sum+nums[ind+1])%mod;
                pq.push({sum, ind+1});
            }
        }
        long long ans=0;
        for(int i=left-1; i<=right-1; i++){
            ans=(ans+tmp[i])%mod;
        }
        return ans;       
        
    }
};