class Solution {
public:

    bool isVow(char &ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'
        || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
            return true;
        }
        return false;
    }

    bool isValid(string word) {
        int n=word.length();
        if(n<3) return false;
        int vowCnt=0, consCnt=0;

        for(int i=0; i<n; i++){
            char ch=word[i];
            if(ch>='0' && ch<='9'){
                continue;
            }else if((ch>='a' && ch<='z') || 
            (ch>='A' && ch<='Z')){
                if(isVow(ch)) vowCnt++;
                else consCnt++;
            }else return false;
        }
        if(vowCnt>0 && consCnt>0) return true;
        return false;        
    }
};