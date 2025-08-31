class Solution(object):
    def isValidSudoku(self, board):
        for i in range(9):
            f=[0]*10
            for j in range(9):
                ch=board[i][j]
                if ch=='.':
                    continue
                ind=ord(ch)-ord('0')
                if f[ind]>0:
                    return False
                f[ind]+=1

        for j in range(9):
            f=[0]*10
            for i in range(9):
                ch=board[i][j]
                if ch=='.':
                    continue
                ind=ord(ch)-ord('0')
                if f[ind]>0:
                    return False
                f[ind]+=1

        for box_row in range(0, 9, 3):
            for box_col in range(0, 9, 3):
                f=[0]*10
                for i in range(3):
                    for j in range(3):
                        ch=board[box_row+i][box_col+j]
                        if ch=='.':
                            continue
                        ind=ord(ch)-ord('0')
                        if f[ind]>0:
                            return False
                        f[ind]+=1

        return True                        
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        