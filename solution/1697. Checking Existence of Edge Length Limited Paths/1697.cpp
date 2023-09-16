class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        father.resize(n);
        for (int i = 0; i < n; ++i)
            father[i] = i;

        sort(edgeList.begin(), edgeList.end(), cmp);
        
        for (int i = 0; i < queries.size(); ++i) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), cmp);
        
        int i = 0;
        vector<bool> res(queries.size());
        for (auto& q : queries) {
            while (i < edgeList.size() && edgeList[i][2] < q[2]) {
                merge(edgeList[i][0], edgeList[i][1]);
                i++;
            }
            res[q[3]] = findFahter(q[0]) == findFahter(q[1]);
        }
        return res;
    }
    
private:
    vector<int> father;
    
    void merge(int a, int b) {
        a = findFahter(a), b = findFahter(b);
        if (father[a] == father[b]) return;
        if (a < b)
            father[b] = a;
        else
            father[a] = b;
    }
    
    int findFahter(int x) {
        if (x != father[x])
            father[x] = findFahter(father[x]);
        return father[x];
    }
    
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }
};
