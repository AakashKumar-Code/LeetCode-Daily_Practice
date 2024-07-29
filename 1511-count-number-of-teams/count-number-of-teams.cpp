class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        int ans=0;

        for(int j=1; j<n-1; j++){
            int cnt_i1=0;
            int cnt_i2=0;
            for(int i=0; i<j; i++){
                if(rating[i]<rating[j]) cnt_i1++;
                if(rating[i]>rating[j]) cnt_i2++;

            }
            int cnt_k1=0;
            int cnt_k2=0;
            for(int k=j+1; k<n; k++){
                if(rating[k]>rating[j]) cnt_k1++;
                if(rating[k]<rating[j]) cnt_k2++;

            }
            ans+=(cnt_i1*cnt_k1);
            ans+=(cnt_i2*cnt_k2);

        }
        return ans;
        
    }
};