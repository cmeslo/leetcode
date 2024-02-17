class Solution {
public:
    bool canCross(vector<int>& stones) {
        for (int x : stones)
            s.insert(x);
        return dfs(stones, 0, 0);
    }

private:
    unordered_set<int> s;
    set<pair<int, int>> failed;

    bool dfs(vector<int>& stones, int i, int k) {
        if (i == stones.back()) return true;
        if (!s.count(i)) return false;
        if (failed.count({i, k})) return false;

        if (k > 1 && dfs(stones, i + k - 1, k - 1))
            return true;
        if (k > 0 && dfs(stones, i + k, k))
            return true;
        if (dfs(stones, i + k + 1, k + 1))
            return true;
        failed.insert({i, k});
        return false;
    }
};
