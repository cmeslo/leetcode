/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        presum.resize(n + 1, vector<int>(n + 1));
        
        // init presum
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                int val = grid[i - 1][j - 1];
                presum[i][j] = presum[i-1][j] + presum[i][j-1] + val - presum[i-1][j-1];
            }
        }
        
        return construct(grid, 1, 1, n, n);
    }
    
private:
    vector<vector<int>> presum;
    
    Node* construct(vector<vector<int>>& grid, int y1, int x1, int y2, int x2) {
        int n = y2 - y1 + 1;
        int sum = presum[y2][x2] - presum[y1-1][x2] - presum[y2][x1-1] + presum[y1-1][x1-1];
        if (sum == n * n || sum == 0) return new Node(grid[y1-1][x1-1], true);
        
        Node* root = new Node();
        root->topLeft = construct(grid, y1, x1, y1 + n/2 - 1, x1 + n/2 - 1);
        root->topRight = construct(grid, y1, x1 + n/2, y2 - n/2, x2);
        root->bottomLeft = construct(grid, y1 + n/2, x1, y2, x2 - n/2);
        root->bottomRight = construct(grid, y1 + n/2, x1 + n/2, y2, x2);
        return root;
    }
};
