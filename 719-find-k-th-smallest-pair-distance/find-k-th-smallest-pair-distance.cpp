class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=-1e9;
        for(int i=0; i<n; i++){
            maxi=max(maxi, nums[i]);
        }

        vector<int>arr(maxi+1, 0);

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                arr[abs(nums[i]-nums[j])]++;
            }
        }

        for(int i=0; i<maxi+1; i++){
            k-=arr[i];
            if(k<=0) return i;
        }
        return -1;
        
    }
};