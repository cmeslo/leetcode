class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> m;
        int maxSeam = 0;
        
        for (int i = 0; i < wall.size(); ++i) {
            int row = 0;
            for (int j = 0; j < wall[i].size() - 1; ++j) {
                row += wall[i][j];
                m[row]++;
                maxSeam = max(maxSeam, m[row]);
                if (wall.size() == maxSeam) return 0; //optimize
            }
        }
        
        return wall.size() - maxSeam;
    }
};
