class Solution {
public:

    int n;

    void solve(int ind, int t, vector<int>&arr, vector<int>&tmp, vector<vector<int>>&ans){
        if(t==0){
            ans.push_back(tmp);
            return;
        }

        for(int i=ind; i<n; i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>t) break;
            tmp.push_back(arr[i]);
            solve(i+1, t-arr[i], arr, tmp, ans);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        n=arr.size();
        vector<int>tmp;
        vector<vector<int>>ans;
        sort(arr.begin(), arr.end());
        solve(0, target, arr, tmp, ans);
        return ans;
    }
};