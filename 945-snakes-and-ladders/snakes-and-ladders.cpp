class Solution {
public:
    int n;

    pair<int, int> getCoord(int num){
        int rT=(num-1)/n;
        int rB=(n-1)-rT;
        int c=(num-1)%n;
        if((n%2==0 && rB%2==0) || (n%2==1 && rB%2==1)) c=(n-1)-c;
        return {rB, c};
    }

    int bfs(vector<vector<int>>&arr){
        
        queue<int>q;
        q.push(1);
        vector<vector<bool>>vis(n, vector<bool>(n, 0));
        vis[n-1][0]=1;

        int cnt=0;
        while(!q.empty()){
            int sz=q.size();

            for(int t=0; t<sz; t++){
                int curr=q.front();
                q.pop();

                if(curr==n*n) return cnt;

                for (int i = 1; i <= 6; i++) {
                    int next = curr + i;

                    if(next>n*n) break;
                    
                    pair<int, int>coord=getCoord(next);
                    int nr=coord.first;
                    int nc=coord.second;

                    if(vis[nr][nc]) continue;
                    vis[nr][nc]=1;

                    if(arr[nr][nc]==-1){
                        q.push(next);
                    }else{
                        q.push(arr[nr][nc]);
                    }
                }
            }
            cnt++;
        }
        return -1;
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n=board.size();      

        return bfs(board);        
    }
};