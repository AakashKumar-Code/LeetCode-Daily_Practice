class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int cnt=0;

        for(int i=0; i<n; i++){
            int a=intervals[i][0];
            int b=intervals[i][1];
            bool covered=0;
            for(int j=0; j<n; j++){
                if(i==j) continue;
                int c=intervals[j][0];
                int d=intervals[j][1];
                if(c<=a && b<=d){
                    covered=1;
                    break;
                }                
            }
            if(!covered) cnt++;
        }

        return cnt;
    }
};