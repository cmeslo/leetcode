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
        return helper(grid, 0, 0, grid.size());
    }
    
private:
    Node* helper(vector<vector<int>>& grid, int y, int x, int n) {
        if (n == 1) return new Node(grid[y][x] == 1, true);
        
        Node* node = new Node();
        Node* topLeft = helper(grid, y, x, n/2);
        Node* topRight = helper(grid, y, x+n/2, n/2);
        Node* bottomLeft = helper(grid, y+n/2, x, n/2);
        Node* bottomRight = helper(grid, y+n/2, x+n/2, n/2);
        
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf
            && topLeft->val == topRight->val
            && topRight->val == bottomLeft->val
            && bottomLeft->val == bottomRight->val) {
            node->val = topLeft->val;
            node->isLeaf = true;
        } else {
            node->topLeft = topLeft;
            node->topRight = topRight;
            node->bottomLeft = bottomLeft;
            node->bottomRight = bottomRight;
        }
        return node;
    }
};
