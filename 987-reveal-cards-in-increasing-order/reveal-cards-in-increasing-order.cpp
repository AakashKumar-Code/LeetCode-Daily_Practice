class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        sort(deck.begin(), deck.end());

        vector<int>ans(n, 0);

        int j=0;
        bool skip=0;

        for(int i=0; i<n; i++){
            while(ans[j]!=0){
                j=(j+1)%n;
            }
            if(skip){
                skip=0;
                j=(j+1)%n;
                while(ans[j]!=0){
                    j=(j+1)%n;
                }
            }
            if(ans[j]==0 && skip==0){
                ans[j]=deck[i];
                skip=1;
            }
            j=(j+1)%n;
        }
        return ans;
    }
};