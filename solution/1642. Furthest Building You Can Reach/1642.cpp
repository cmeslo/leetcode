class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<>> q;
        
        for (int i = 1; i < n; ++i) {
            int need = heights[i] - heights[i - 1];
            if (need <= 0)
                continue;
            q.push(need);
            if (q.size() > ladders) {
                if (q.top() <= bricks) {
                    bricks -= q.top();
                    q.pop();
                } else {
                    return i - 1;
                }
            }
        }
        return n - 1;
    }
};
