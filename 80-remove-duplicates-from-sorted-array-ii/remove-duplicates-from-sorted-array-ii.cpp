class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int cnt=0, el=-1e9;

        int ind=0;

        for(int i=0; i<n; i++){
            if(el!=nums[i]){
                el=nums[i];
                cnt=1;
                swap(nums[ind], nums[i]);
                ind++;
            }else{
                if(cnt<2){
                    swap(nums[ind], nums[i]);
                    ind++;
                    cnt++;
                }
            }            
        }
        return ind;        
    }
};