class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int hMax=1, hCnt=1, vMax=1, vCnt=1;

        for(int h=1; h<hBars.size(); h++){
            if(hBars[h-1]+1==hBars[h]){
                hCnt++;
                hMax=max(hMax, hCnt);
            }else hCnt=1;
        }

        for(int v=1; v<vBars.size(); v++){
            if(vBars[v-1]+1==vBars[v]){
                vCnt++;
                vMax=max(vMax, vCnt);
            }else vCnt=1;
        }

        int side=min(hMax, vMax)+1;
        return side*side;
    }
};