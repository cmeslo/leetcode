class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int res = accumulate(piles.begin(), piles.end(), 0);
        priority_queue<int> pq(piles.begin(), piles.end());
        while (k--) {
            int x = pq.top(); pq.pop();
            res -= x / 2;
            pq.push((x + 1) / 2);
        }
        return res;
    }
};
