class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int mini=1e9;

        for(int i=0; i<n; i++){
            if((nums1[i]%2)==1){
                mini=min(mini, nums1[i]);
            }
        }

        bool poss=1;

        for(int i=0; i<n; i++){
            if((nums1[i]%2)==0){
                if(mini==1e9 || mini>=nums1[i]){
                    poss=0;
                    break;
                }
            }
        }

        if(poss) return 1;
        poss=1;

        for(int i=0; i<n; i++){
            if((nums1[i]%2)==1){
                if(mini==1e9 || mini>=nums1[i]){
                    poss=0;
                    break;
                }
            }
        }

        return poss;        
    }
};