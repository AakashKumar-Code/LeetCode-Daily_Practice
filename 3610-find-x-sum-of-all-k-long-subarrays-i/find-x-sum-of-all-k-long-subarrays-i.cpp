class Solution {
public:

    int x_sum(int lo, int hi, vector<int>&arr, int x){
        unordered_map<int, int>mpp;
        int sum=0;
        for(int i=lo; i<=hi; i++){
            sum+=arr[i];
            mpp[arr[i]]++;
        }
        if(mpp.size()<=x) return sum;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(auto &it:mpp){
            pq.push({it.second, it.first});
            if(pq.size()>x){
                pq.pop();
            }
        }
        sum=0;
        while(!pq.empty()){
            auto it=pq.top();
            int num=it.second;
            int f=it.first;
            pq.pop();
            sum+=(f*num);
        }
        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int>ans;
        int i=0;
        while(i+k-1<n){
            ans.push_back(x_sum(i, i+k-1, nums, x));
            i++;
        }
        return ans;       
        
    }
};