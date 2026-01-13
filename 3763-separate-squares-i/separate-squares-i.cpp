class Solution {
public:
    bool check(double mid_y, vector<vector<int>>&squares, double tot_area){
        double down_area=0.0;
        for(auto &it:squares){
            double l=it[2];            
            double y_down=it[1];
            double y_up=y_down+l;
            if(mid_y>=y_up){
                down_area+=(l*l);
            }else if(mid_y>y_down){
                down_area+=(l*(mid_y-y_down));
            }
        }
        return down_area>=(tot_area/2.0);
    }

    double separateSquares(vector<vector<int>>& squares) {
        int n=squares.size();
        double lo=INT_MAX, hi=INT_MIN, tot_area=0.0, ans=0.0;

        for(int i=0; i<n; i++){
            double x=squares[i][0];
            double y=squares[i][1];
            double l=squares[i][2];
            lo=min(lo, y);
            hi=max(hi, y+l);
            tot_area+=(l*l);
        }

        while(hi-lo>1e-5){
            double mid_y=lo+(hi-lo)/2;
            ans=mid_y;
            if(check(mid_y, squares, tot_area)){
                hi=mid_y;
            }else lo=mid_y;
        }

        return ans;        
    }
};