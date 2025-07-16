class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        memo.resize(n);
        return dfs(books, shelfWidth, 0);
    }
    
private:
    int n;
    vector<int> memo;
    
    int dfs(vector<vector<int>>& books, int shelfWidth, int start) {
        if (start >= n) return 0;
        if (memo[start]) return memo[start];
        
        int res = INT_MAX, width = 0, height = 0;
        for (int i = start; i < n && width + books[i][0] <= shelfWidth; ++i) {
            width += books[i][0];
            height = max(height, books[i][1]);
            res = min(res, height + dfs(books, shelfWidth, i + 1));
        }
        return memo[start] = res;
    }
};
