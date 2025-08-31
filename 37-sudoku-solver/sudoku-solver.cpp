class Solution {
public:

    pair<int, int> findSq(int r, int c){
        pair<int, int>ans={-1, -1};
        if(r<=2) ans.first=0;
        else if(r>=3 && r<=5) ans.first=3;
        else ans.first=6;

        if(c<=2) ans.second=0;
        else if(c>=3 && c<=5) ans.second=3;
        else ans.second=6;

        return ans;
    }

    bool check(int r, int c, char val, vector<vector<char>>&board){
        //row-check
        for(int j=0; j<9; j++){
            if(c!=j && board[r][j]==val) return 0;
        }

        //col-check
        for(int i=0; i<9; i++){
            if(r!=i && board[i][c]==val) return 0;
        }

        //sq-check
        int x, y;
        tie(x, y)=findSq(r, c);
        for(int i=x; i<x+3; i++){
            for(int j=y; j<y+3; j++){
                if(!(i==r && j==c) && board[i][j]==val) return 0;
            }
        }

        return 1;
    }

    bool solve(vector<vector<char>>&board){
        for(int r=0; r<9; r++){
            for(int c=0; c<9; c++){
                if(board[r][c]=='.'){
                    for(char i='1'; i<='9'; i++){
                        if(check(r, c, i, board)==1){
                            board[r][c]=i;
                            if(solve(board)==1){
                                return 1;
                            }else board[r][c]='.';
                        }
                    }
                    return 0;
                }
            }
        }
        return 1;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        return;        
    }
};