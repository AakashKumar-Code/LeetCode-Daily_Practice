class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.length();
        int m=numRows-1;
        vector<vector<string>>arr(numRows, vector<string>(n, ""));

        int row=0, col=0;

        int ind=0;

        while(ind<n){
            if(row<=0){
                row=0;
                while(ind<n && row<numRows){
                    arr[row++][col]=s[ind++];
                }
            }
            if(row>=numRows){
                row=numRows-2;
                col++;
                while(ind<n && row>0){
                    arr[row--][col++]=s[ind++];
                }
            }
        }

        string ans="";
        for(int i=0; i<numRows; i++){
            for(int j=0; j<n; j++){
                ans+=arr[i][j];
            }
        }
        return ans;

        // A       I
        // B     H J
        // C   G
        // D F
        // E
        
    }
};