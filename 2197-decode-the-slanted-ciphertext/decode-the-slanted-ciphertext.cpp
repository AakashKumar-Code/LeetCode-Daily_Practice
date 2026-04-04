class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int l=encodedText.length();
        if(l==0) return "";
        int columns=l/rows;
        string ans="";
        for(int col=0; col<columns; col++){
            for(int j=col; j<l; j+=(columns+1)){
                ans+=encodedText[j];
            }
        }
        while(ans.back()==' '){
            ans.pop_back();
        }
        return ans;        
    }
};