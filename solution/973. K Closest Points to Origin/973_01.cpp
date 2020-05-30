class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<int> dists;
        vector<vector<int>> ans;
        
        for (const vector<int>& point : points) {
            dists.push_back(calcDist(point));
        }
        
        sort(dists.begin(), dists.end());
        int distK = dists[K-1];
        
        for (const vector<int>& point : points) {
            if (calcDist(point) <= distK) {
                ans.push_back(point);
            }
        }
        return ans;
    }
    
private:
    int calcDist(const vector<int>& point) {
        return point[0] * point[0]  + point[1] * point[1];
    }
};
