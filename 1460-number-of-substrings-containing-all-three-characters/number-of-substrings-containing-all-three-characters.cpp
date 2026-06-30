class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();

        vector<int>a(n, -1), b(n, -1), c(n, -1);

        for(int i=n-1; i>=0; i--){
            if(s[i]=='a'){
                a[i]=i;
            }else if(s[i]=='b'){
                b[i]=i;
            }else c[i]=i;
        }

        for(int i=n-2; i>=0; i--){
            if(a[i]==-1){
                a[i]=a[i+1];
            }
            if(b[i]==-1){
                b[i]=b[i+1];
            }
            if(c[i]==-1){
                c[i]=c[i+1];
            }
        }

        int ans=0;

        for(int i=0; i<n; i++){
            if(a[i]==-1 || b[i]==-1 || c[i]==-1) continue;
            int maxi=max(a[i], max(b[i], c[i]));

            ans+=n-maxi;
        }

        return ans;
    }
};