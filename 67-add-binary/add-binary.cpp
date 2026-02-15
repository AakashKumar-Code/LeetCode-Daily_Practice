class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int i=0, j=0, n=a.length(), m=b.length(), c=0;
        string ans="";

        while(i<n && j<m){
            int x=a[i]-'0';
            int y=b[j]-'0';
            int sum=x+y+c;
            c=(sum/2);
            sum=(sum%2);
            ans+=to_string(sum);
            i++;
            j++;            
        }

        while(i<n){
            int x=a[i]-'0';
            int sum=x+c;
            c=(sum/2);
            sum=(sum%2);
            ans+=to_string(sum);
            i++;
        }

        while(j<m){
            int y=b[j]-'0';
            int sum=y+c;
            c=(sum/2);
            sum=(sum%2);
            ans+=to_string(sum);
            j++;  
        }

        while(c>0){
            ans+=to_string(c);
            c--;
        }

        reverse(ans.begin(), ans.end());

        return ans;        
    }
};