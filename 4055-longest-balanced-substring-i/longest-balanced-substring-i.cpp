class Solution {
public:
    int longestBalanced(string s) {

        int n=s.length();
        int maxi=0;

        for(int x=0; x<n; x++){
            int f[26]={0};
            for(int j=x; j<n; j++){
                f[s[j]-'a']++;

                bool valid=1;
                int freq=0;

                for(int i=0; i<26; i++){
                    if(f[i]!=0){
                        if(freq==0){
                            freq=f[i];
                        }else if(freq!=f[i]){
                            valid=0;
                            break;
                        }
                    }else continue;
                }

                if(valid) maxi=max(maxi, j-x+1);
            }            
        }
        return maxi;        
    }
};