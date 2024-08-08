class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>ans;

        int dr[4]={0, 1, 0, -1};
        int dc[4]={1, 0, -1, 0};

        int steps=0;
        int dir=0;

        ans.push_back({rStart, cStart});
        int r=rStart, c=cStart;

        while(ans.size()<rows*cols){            
            if(dir%2==0) steps++;
            for(int cnt=0; cnt<steps; cnt++){
                int nr=r+dr[dir];
                int nc=c+dc[dir];
                if(nr>=0 && nr<rows && nc>=0 && nc<cols){
                    ans.push_back({nr, nc});
                }
                r=nr;
                c=nc;
            }
            dir=(dir+1)%4;
        }
        return ans;        
    }
};