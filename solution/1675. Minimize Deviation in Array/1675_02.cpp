class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int mn = INT_MAX;
        priority_queue<int> q;
        for (int x : nums) {
            x = x % 2 ? x * 2 : x;
            q.push(x);
            mn = min(mn, x);
        }
        
        int ans = INT_MAX;
        while (true) {
            int x = q.top(); q.pop();
            ans = min(ans, x - mn);
            mn = min(mn, x / 2);
            if (x % 2 == 0)
                q.push(x / 2);
            else
                break;
        }
        return ans;
    }
};
