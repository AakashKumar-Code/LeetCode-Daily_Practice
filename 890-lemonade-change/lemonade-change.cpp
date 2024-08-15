class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5=0, cnt10=0;
        int n=bills.size();
        for(int i=0; i<n; i++){
            if(bills[i]==5){
                cnt5++;
            }else if(bills[i]==10){
                if(cnt5>0){
                    cnt5-=1;
                    cnt10++;
                }else return 0;
            }else{
                if(cnt5>=1 && cnt10>=1){
                    cnt10-=1;
                    cnt5-=1;
                }else if(cnt5>=3){
                    cnt5-=3;
                }else return 0;
            }
        }
        return 1;        
    }
};