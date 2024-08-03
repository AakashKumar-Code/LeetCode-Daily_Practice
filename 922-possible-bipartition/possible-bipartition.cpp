class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    vector<vector<int>> adj(n + 1); // Adjusted to use vector of vectors

    // Build the adjacency list
    for (auto &it : dislikes) {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n + 1, -1); // Visited and color array (-1 means unvisited)

    for (int i = 1; i <= n; i++) {
        if (vis[i] == -1) {
            // If the node is unvisited, start a BFS from it
            queue<int> q;
            q.push(i);
            vis[i] = 0; // Start coloring with 0

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                int color = vis[node];

                for (auto &neighbor : adj[node]) {
                    if (vis[neighbor] == -1) {
                        // If the neighbor is unvisited, color it with alternate color
                        vis[neighbor] = 1 - color;
                        q.push(neighbor);
                    } else if (vis[neighbor] == color) {
                        // If the neighbor is already colored with the same color, return false
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

};