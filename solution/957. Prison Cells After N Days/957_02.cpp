class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<vector<int>> seen; // seen[0]=Day1, seen[1]=Day2, ..., seen[N-1]=DayN
        vector<int> tmp(8, 0);
        
        for (int i = 0; i < N; i++) {
            for (int j = 1; j < 7; j++)
                tmp[j] = cells[j-1] == cells[j+1] ? 1 : 0;
            
            if (!seen.empty() && tmp == seen.front())
                return seen[(N-1) % seen.size()];
            
            seen.push_back(tmp);
            cells = tmp;
        }
        return cells;
    }
};
