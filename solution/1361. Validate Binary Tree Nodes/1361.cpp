class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n);
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                adj[leftChild[i]].push_back(i);
                ++inDegree[i];
            }
            if (rightChild[i] != -1) {
                adj[rightChild[i]].push_back(i);
                ++inDegree[i];
            }
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (adj[i].size() > 1) return false;
            if (inDegree[i] == 0)
                q.push(i);
        }

        int rootCount = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            if (adj[node].empty()) ++rootCount;
            for (int next : adj[node]) {
                if (--inDegree[next] == 0)
                    q.push(next);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (inDegree[i] != 0)
                return false;
        }
        return q.empty() && rootCount == 1;
    }
};
