class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_map<int, int>mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }

        for(auto &it:mpp){
            int f=it.second;
            if(f<2) return -1;
            if(f>=3 && f!=4){
               if(f%3==0){
                   ans+=f/3;
                   continue;
               } 
               for(int i=2; i<f; i*=2){
                   if((f-i)%3==0){
                       ans+=(i/2);
                       ans+=((f-i)/3);
                       break;
                   }
               }
            }else if(f==2 || f==4) ans+=f/2;
        }
        return ans;
    }
};