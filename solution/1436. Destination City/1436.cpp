class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> outDegree;
        unordered_set<string> cities;
        for (auto& path : paths) {
            outDegree[path[0]]++;
            cities.insert(path[0]);
            cities.insert(path[1]);
        }
        for (string city : cities) {
            if (outDegree[city] == 0)
                return city;
        }
        return "";
    }
};
