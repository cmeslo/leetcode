class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int winner = arr[0], win_count = 0;
        
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > winner) {
                winner = arr[i];
                win_count = 0;
            }
            if (++win_count == k) break;
        }
        
        return winner;
    }
};
