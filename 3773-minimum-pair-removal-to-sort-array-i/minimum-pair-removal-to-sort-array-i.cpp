class Solution {
public:

    bool isSorted(vector<int>&arr){
        vector<int>tmp=arr;
        sort(tmp.begin(), tmp.end());
        return arr==tmp;
    }

    void swapEl(vector<int>&arr){
        int n=arr.size();
        int ind=0, mini=1e9;
        for(int i=0; i<n-1; i++){
            if(arr[i]+arr[i+1]<mini){
                mini=arr[i]+arr[i+1];
                ind=i;
            }
        }
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(i==ind){
                ans.push_back(arr[i]+arr[i+1]);
                i++;
            }else ans.push_back(arr[i]);
        }
        arr=ans;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int cnt=0;
        while(!isSorted(nums)){
            swapEl(nums);
            cnt++;
        }
        return cnt;        
    }
};