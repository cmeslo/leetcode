class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        _rects = rects;
        _areaSum = 0;
        for (const auto& rect : rects) {
            _areaSum += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            _areas[_areaSum] = _areas.size();
        }
    }
    
    vector<int> pick() {
        int point = rand() % _areaSum;
        int i = _areas.upper_bound(point)->second;
        int x = rand() % (_rects[i][2] - _rects[i][0] + 1) + _rects[i][0];
        int y = rand() % (_rects[i][3] - _rects[i][1] + 1) + _rects[i][1];
        return {x, y};
    }
    
private:
    vector<vector<int>> _rects;
    int _areaSum;
    map<int, int> _areas;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
