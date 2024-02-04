class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n=word.size();
        for(int i=1; i<=n; i++){
            int d=i*k;
            bool ok=1;

            for(int j=d; j<n; j++){
                if(word[j]!=word[j-d]){
                    ok=0;
                    break;
                }
            }
            if(ok) return i;
        }
        return 0;
    }
};