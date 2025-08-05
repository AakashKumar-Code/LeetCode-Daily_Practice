class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();

        vector<bool>t(n, 0);
        int cnt=0;

        for(int i=0; i<n; i++){
            bool kept=0;
            for(int j=0; j<n; j++){
                if(baskets[j]>=fruits[i] && t[j]==0){
                    t[j]=1;
                    kept=1;
                    break;
                }
            }
            if(!kept) cnt++;
        }

        return cnt;        
    }
};