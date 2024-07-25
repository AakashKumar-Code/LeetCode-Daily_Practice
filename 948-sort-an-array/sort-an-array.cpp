class Solution {
public:

    void maxHeapify(vector<int>&arr, int n, int i){
        int largest=i;
        int lft=2*i+1, rgt=2*i+2;
        if(lft<n && arr[largest]<arr[lft]){
            largest=lft;
        }
        if(rgt<n && arr[largest]<arr[rgt]){
            largest=rgt;
        }
        if(largest!=i){
            swap(arr[i], arr[largest]);
            maxHeapify(arr, n, largest);
        }
    }

    void buildHeap(vector<int>&arr, int n){
        for(int i=(n-2)/2; i>=0; i--){
            maxHeapify(arr, n, i);
        }
    }

    vector<int> sortArray(vector<int>& nums) {

        int n=nums.size();
        buildHeap(nums, n);
        for(int i=n-1; i>=1; i--){
            swap(nums[i], nums[0]);
            maxHeapify(nums, i, 0);
        }
        return nums;        
    }
};