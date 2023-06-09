class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        father.resize(26);
        for (int i = 0; i < 26; ++i) {
            father[i] = i;
        }

        int n = s1.size();
        for (int i = 0; i < n; ++i) {
            merge(s1[i] - 'a', s2[i] - 'a');
        }

        int m = baseStr.size();
        string res;
        for (char& c : baseStr) {
            res += findFather(c - 'a') + 'a';
        }
        return res;
    }

private:
    vector<int> father;

    void merge(int a, int b) {
        a = findFather(a), b = findFather(b);
        if (a == b) return;
        if (a < b)
            father[b] = a;
        else
            father[a] = b;
    }

    int findFather(int x) {
        if (x != father[x])
            father[x] = findFather(father[x]);
        return father[x];
    }
};

// p a r k e r
// m o r r i s

// p,m

// a,o

// r,k,s

// e,i

// p a r s e r
// m a k k e k
