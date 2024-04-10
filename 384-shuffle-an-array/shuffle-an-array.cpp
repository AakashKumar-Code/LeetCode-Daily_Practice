class Solution {
public:

    vector<int>o;
    int n;

    Solution(vector<int>& nums) {
        n=nums.size();
        o=nums;
        
    }
    
    vector<int> reset() {
        return o;        
    }
    
    vector<int> shuffle() {
        int sz=n;
        vector<int>temp=o;
        for(int i=n-1; i>=0; i--){
            int j=rand()%sz;
            swap(temp[i], temp[j]);
            sz--;
        }
        return temp;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */