class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (groupSize == 1) return true;
        sort(hand.begin(), hand.end());
        
        unordered_map<int, queue<int>> m;
        int left = hand.size();
        for (int card : hand) {
            int pre = card - 1;
            if (m.count(pre)) {
                int cnt = m[pre].front() + 1; m[pre].pop();
                if (cnt < groupSize)
                    m[card].push(cnt);
                else
                    left -= cnt;
                
                if (m[pre].empty())
                    m.erase(pre);
            } else {
                m[card].push(1);
            }
        }
        return left == 0;
    }
};
