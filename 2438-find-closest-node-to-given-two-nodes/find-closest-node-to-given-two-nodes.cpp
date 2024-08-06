class Solution {
public:
    int n;

    void bfs(int src, vector<int>& edges, vector<int>& dist) {
        vector<bool> vis(n, false);
        queue<pair<int, int>> q;
        q.push({src, 0});
        vis[src] = true;

        while (!q.empty()) {
            auto [node, d] = q.front();
            q.pop();

            dist[node] = d;

            int adjN = edges[node];
            if (adjN != -1 && !vis[adjN]) {
                vis[adjN] = true;
                q.push({adjN, d + 1});
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);

        bfs(node1, edges, dist1);
        bfs(node2, edges, dist2);

        int minDist = INT_MAX;
        int ans = -1;

        for (int i = 0; i < n; ++i) {
            if (dist1[i] != INT_MAX && dist2[i] != INT_MAX) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    ans = i;
                } else if (maxDist == minDist && i < ans) {
                    ans = i;
                }
            }
        }

        return ans;
    }
};
