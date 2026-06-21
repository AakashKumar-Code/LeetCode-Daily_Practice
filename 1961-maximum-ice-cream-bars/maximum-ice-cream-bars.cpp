class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int sum=0;
        int cnt=0;
        for(auto &it:costs){
            if(sum+it>coins) return cnt;
            else{
                sum+=it;
                cnt++;
            } 
        }
        return cnt;        
    }
};