#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		vector<unordered_set<int>> graph = makeGraph(numCourses, prerequisites);
		vector<bool> visited(numCourses, false);

		for (int i = 0; i < numCourses; ++i) {
			if (!visited[i] && !doDFS(i, graph, visited)) return false;
		}
		return true;
	}

	vector<unordered_set<int>> makeGraph(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		vector<unordered_set<int>> graph(numCourses);

		for (auto pre : prerequisites) {
			graph[pre.second].insert(pre.first);
		}
		return graph;
	}

	//circle: false
	bool doDFS(int node, vector<unordered_set<int>> &graph, vector<bool> &visited) {
		if (visited[node] == true) return false;
		visited[node] = true;

		for (auto neigh : graph[node]) {
			if (!doDFS(neigh, graph, visited)) return false;
		}
		visited[node] = false;
		return true;
	}
};

void main()
{
	auto ans = new Solution;

	pair<int, int> a = { 1, 0 };
	pair<int, int> b = { 2, 1 };
//	pair<int, int> c = { 2, 3 };
	vector<pair<int, int>> test;

	test.push_back(a);
	test.push_back(b);
//	test.push_back(c);

	cout << ans->canFinish(3, test) << endl;
}
