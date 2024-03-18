class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        if(n==0) return 0;
        sort(points.begin(), points.end());
        vector<int>prev={points[0][0], points[0][1]};

        int cnt=1;
        for(int i=1; i<n; i++){
            if(points[i][0]>prev[1]){
                cnt++;
                prev=points[i];
            }else{
                prev[0]=max(prev[0], points[i][0]);
                prev[1]=min(prev[1], points[i][1]);
            }
        }
        return cnt;

    }
};