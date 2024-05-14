class Solution {
public:
    int n, m;
    int dr[4]={-1, 0, 1, 0};
    int dc[4]={0, 1, 0, -1};

    int solve(int sr, int sc, vector<vector<int>>& arr, vector<vector<bool>>& visited) {
        if (sr < 0 || sr >= n || sc < 0 || sc >= m || arr[sr][sc] == 0 || visited[sr][sc]) {
            return 0; // Base case: out of bounds or cell already visited or no gold in the cell
        }
        
        visited[sr][sc] = true; // Mark current cell as visited
        
        int maxSum = 0;
        for (int i = 0; i < 4; i++) {
            int nr = sr + dr[i];
            int nc = sc + dc[i];
            int sum = solve(nr, nc, arr, visited); // Recursively explore neighboring cells
            maxSum = max(maxSum, sum); // Update maxSum with the maximum sum from neighboring cells
        }
        
        visited[sr][sc] = false; // Unmark current cell (backtrack)
        
        return maxSum + arr[sr][sc]; // Return the maximum sum including the current cell's gold
    }


    int getMaximumGold(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        int maxi=-1e9;
        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                vector<vector<bool>>visited(n, vector<bool>(m, 0));
                maxi=max(maxi, solve(r, c, grid, visited));
            }
        }
        return maxi;
    }
};