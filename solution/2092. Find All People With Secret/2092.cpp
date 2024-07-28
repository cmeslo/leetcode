// Runtime: 361 ms, Your runtime beats 94.96 % of cpp submissions.
// Memory Usage: 134.6 MB, Your memory usage beats 99.24 % of cpp submissions.

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        const int m = meetings.size();
        sort(meetings.begin(), meetings.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });
        
        father.resize(n);
        for (int i = 0; i < n; ++i)
            father[i] = i;
        merge(0, firstPerson);
        
        for (int i = 0; i < m; ++i) {
            int t = meetings[i][2];
            int j = i;
            while (j < m && t == meetings[j][2]) {
                int a = meetings[j][0], b = meetings[j][1];
                merge(a, b);
                j++;
            }
            j = i;
            while (j < m && t == meetings[j][2]) {
                int a = meetings[j][0], b = meetings[j][1];
                if (findFather(a) != 0)
                    father[a] = a;
                if (findFather(b) != 0)
                    father[b] = b;
                j++;
            }
            i = j - 1;
        }
        
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (findFather(i) == 0)
                res.push_back(i);
        }
        return res;
    }

private:
    vector<int> father;
    
    int findFather(int x) {
        if (father[x] != x)
            father[x] = findFather(father[x]);
        return father[x];
    }
    
    void merge(int a, int b) {
        a = findFather(a), b = findFather(b);
        if (a == b) return;
        if (a < b)
            father[b] = a;
        else
            father[a] = b;
    }
};
