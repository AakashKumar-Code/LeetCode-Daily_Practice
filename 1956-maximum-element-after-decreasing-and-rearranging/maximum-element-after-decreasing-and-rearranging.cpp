class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(), arr.end());
        int prev=1, maxi=1;

        for(int i=1; i<n; i++){
            if(arr[i]>prev+1){
                arr[i]=prev+1;
            }
            maxi=max(maxi, arr[i]);
            prev=arr[i];
        }

        return maxi;
    }
};