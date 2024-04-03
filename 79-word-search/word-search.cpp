class Solution {
public:

    int n, m;

    int dr[4]={-1, 0, 1, 0};
    int dc[4]={0, 1, 0, -1};

    bool solve(int r, int c, int ind, string &word, vector<vector<char>>& board){
        if(ind>word.size()-1) return 1;
        char ch=board[r][c];
        board[r][c]='$';
        for(int i=0; i<4; i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]==word[ind]){
                if(solve(nr, nc, ind+1, word, board)) return 1;
            }
        }
        board[r][c]=ch;
        return 0;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==word[0]){
                    if(solve(i, j, 1, word, board)) return 1;;
                }
            }
        }
        return 0;
    }
};