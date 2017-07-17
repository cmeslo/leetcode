#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		vector<vector<int>> graph = makeGraph(numCourses, prerequisites);
		vector<bool> visited(numCourses, false), dfsPath(numCourses, false);
		vector<int> topoSort;

		for (int i = 0; i < numCourses; ++i) {
			if (!visited[i] && doDFS(i, graph, visited, dfsPath, topoSort)) {
				return {};
			}
		}
		reverse(topoSort.begin(), topoSort.end());
		return topoSort;
	}

private:
	vector<vector<int>> makeGraph(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		vector<vector<int>> graph(numCourses, vector<int>(0));

		for (auto pre : prerequisites) {
			graph[pre.second].push_back(pre.first);
		}
		return graph;
	}

	bool doDFS(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>&dfsPath, vector<int>& topoSort) {
		if (visited[node]) return false;
		visited[node] = dfsPath[node] = true;

		for (int neigh : graph[node]) {
			if (dfsPath[neigh] || doDFS(neigh, graph, visited, dfsPath, topoSort)) return true;
		}
		dfsPath[node] = false;
		topoSort.push_back(node);
		return false;
	}
};

void main()
{
	auto ans = new Solution;

// 	pair<int, int> a = { 1, 0 };
// 	pair<int, int> b = { 2, 1 };
	vector<pair<int, int>> test;

	test.push_back({ 1, 0 });
	test.push_back({ 2, 0 });
	test.push_back({ 3, 1 });
	test.push_back({ 3, 2 });

	vector<int> path = ans->findOrder(4, test);
	for (auto i : path) {
		cout << i << ", ";
	}
}