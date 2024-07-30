class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        int right_a=0;
        for(int i=0; i<n; i++){
            if(s[i]=='a') right_a++;
        }

        int left_b=0;
        int mini=1e9;

        for(int i=0; i<n; i++){
            if(s[i]=='a'){
                right_a--;
            }
            mini=min(mini, right_a + left_b);
            if(s[i]=='b') left_b++;
        }
        return mini;
    }
};