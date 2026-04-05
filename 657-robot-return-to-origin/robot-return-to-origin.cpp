class Solution {
public:
    bool judgeCircle(string moves) {
        int U=0, L=0;
        for(char &ch:moves){
            if(ch=='U'){
                U++;
            }else if(ch=='D'){
                U--;
            }else if(ch=='L'){
                L++;
            }else L--;
        }
        return (U==0 && L==0);        
    }
};