class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        father.resize(n);
        for (int i = 0; i < n; ++i)
            father[i] = i;
        father[firstPerson] = 0;
        
        sort(meetings.begin(), meetings.end(), [&](auto& a, auto& b) {
            return a[2] < b[2];
        });
        
        unordered_set<int> knew{0, firstPerson};
        for (int i = 0; i < meetings.size(); ++i) {
            unordered_set<int> people;
            int time = meetings[i][2];
            for (; i < meetings.size() && meetings[i][2] == time; ++i) {
                int a = meetings[i][0], b = meetings[i][1];
                if (FindFather(a) != FindFather(b))
                    Union(a, b);
                people.insert(a);
                people.insert(b);
            }
            i--;
            for (int x : people) {
                if (FindFather(x) == 0)
                    knew.insert(x);
                else
                    father[x] = x;
            }
        }
        return vector<int>(knew.begin(), knew.end());
    }
    
private:
    vector<int> father;
    
    int FindFather(int x) {
        if (x != father[x])
            father[x] = FindFather(father[x]);
        return father[x];
    }
    
    void Union(int a, int b) {
        a = FindFather(a), b = FindFather(b);
        if (a < b)
            father[b] = a;
        else
            father[a] = b;
    }
};
