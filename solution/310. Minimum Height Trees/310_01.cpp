#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges)
    {
        if (n == 1) return { 0 };

        vector<int> degrees(n);
        vector<unordered_set<int>> graph = makeGraph(n, edges, degrees);
        queue<int> leaves;
        vector<int> ans;

        for (int i = 0; i < n; ++i) {
            if (degrees[i] == 1) leaves.push(i);
        }

        while (n > 2) {

            int curleaves = leaves.size();
            n -= curleaves;

            for (int i = 0; i < curleaves; ++i) {
                int leap = leaves.front();
                leaves.pop();
                for (auto neighbor : graph[leap]) {
                    graph[neighbor].erase(leap);
                    degrees[neighbor]--;
                    if (degrees[neighbor] == 1) leaves.push(neighbor);
                }
            }
        }
        while (!leaves.empty()) {
            ans.push_back(leaves.front());
            leaves.pop();
        }
        return ans;
    }

    vector<unordered_set<int>> makeGraph(int n, vector<pair<int, int>>& edges, vector<int>& degrees)
    {
        vector<unordered_set<int>> graph(n, unordered_set<int>());

        for (auto edge : edges) {
            graph[edge.first].insert(edge.second);
            graph[edge.second].insert(edge.first);
            degrees[edge.first]++;
            degrees[edge.second]++;
        }
        return graph;
    }
};

void main()
{
    auto ans = new Solution;

    vector<pair<int, int>> test;

    // test.push_back({ 1, 0 });
    // test.push_back({ 1, 2 });
    // test.push_back({ 1, 3 });
    // vector<int> roots = ans->findMinHeightTrees(4, test);

    // test.push_back({ 0, 3 });
    // test.push_back({ 1, 3 });
    // test.push_back({ 2, 3 });
    // test.push_back({ 4, 3 });
    // test.push_back({ 5, 4 });
    // vector<int> roots = ans->findMinHeightTrees(6, test);

    // vector<int> roots = ans->findMinHeightTrees(1,test);

    test.push_back({ 0, 1 });
    test.push_back({ 0, 2 });
    vector<int> roots = ans->findMinHeightTrees(3, test);

    for (auto i : roots) {
        cout << i << ", ";
    }
}
