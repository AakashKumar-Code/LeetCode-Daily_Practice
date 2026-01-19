class Solution {
public:
    int n, m;

    bool check(int x, vector<vector<int>>& mat, vector<vector<int>>& pre, int t){
        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                int x1=r;
                int y1=c;
                int x2=r+x-1;
                int y2=c+x-1;
                if(x2>=n || y2>=m) continue;

                int sum=pre[x2][y2];
                if(x1>1) sum-=pre[x1-1][y2];
                if(y1>1) sum-=pre[x2][y1-1];
                if(x1>1 && y1>1) sum+=pre[x1-1][y1-1];

                if(sum<=t) return true;
            }
        }
        return false;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        n=mat.size();
        m=mat[0].size();

        vector<vector<int>>pre(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                pre[i][j]=(i>0?pre[i-1][j]:0)+(j>0?pre[i][j-1]:0)
                -((i>0 && j>0)?pre[i-1][j-1]:0)+mat[i][j];
            }
        }

        int lo=1, hi=min(n, m);
            
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid, mat, pre, threshold)){
                ans=mid;
                lo=mid+1;
            }else hi=mid-1;
        }

        return ans;
    }
};