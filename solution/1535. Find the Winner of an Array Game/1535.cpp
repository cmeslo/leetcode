class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        deque<int> dq(arr.begin(), arr.end());
        int win_count = 0;
        
        int winner = dq.front(); dq.pop_front();
        while (win_count < k && win_count < arr.size()) {
            if (winner > dq.front()) {
                win_count++;
                int loser = dq.front(); dq.pop_front();
                dq.push_back(loser);
            } else {
                win_count = 1;
                dq.push_back(winner);
                winner = dq.front(); dq.pop_front();
            }
        }
        
        return winner;
    }
};
