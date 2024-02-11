class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        this->n = n;
        father.resize(n);
        for (int i = 0; i < edges.size(); ++i) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), cmp);
        int minMST = kruskal(edges, -1);

        unordered_set<int> s1;
        for (int i = 0; i < edges.size(); ++i) {
            int mst = kruskal(edges, i);
            if (minMST < mst) {
                s1.insert(edges[i][3]);
            }
        }

        vector<int> res2;
        for (int i = 0; i < edges.size(); ++i) {
            if (s1.count(edges[i][3])) continue;

            auto edge = edges[i];
            edges.insert(edges.begin(), edge);
            int mst = kruskal(edges, -1);
            if (minMST == mst) {
                res2.push_back(edge[3]);
            }
            edges.erase(edges.begin());
        }

        vector<int> res1(s1.begin(), s1.end());
        return {res1, res2};
    }

private:
    int n;
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

    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }

    int kruskal(vector<vector<int>>& edges, int k) {
        for (int i = 0; i < n; ++i)
            father[i] = i;

        int mst = 0;
        for (int i = 0; i < edges.size(); ++i) {
            if (i == k) continue;
            int a = edges[i][0], b = edges[i][1], w = edges[i][2];
            if (findFather(a) != findFather(b)) {
                merge(a, b);
                mst += w;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (findFather(i) != findFather(0))
                return INT_MAX;
        }
        return mst;
    }
};
