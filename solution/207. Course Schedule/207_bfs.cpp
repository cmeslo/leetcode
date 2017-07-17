#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		vector<unordered_set<int>> graph = makeGraph(numCourses, prerequisites);
		vector<int> degrees = computeInDegrees(graph);

		for (int i = 0; i < numCourses; ++i) {
			int j = 0;
			for (; j < numCourses; ++j) {
				if (degrees[j] == 0) break;
			}
			if (j == numCourses) return false;

			degrees[j] = -1;
			for (auto neighbor : graph[j]) {
				degrees[neighbor]--;
			}
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

	vector<int> computeInDegrees(vector<unordered_set<int>> &graph) {

		vector<int> degrees(graph.size(), 0);

		for (auto neighbors : graph) {
			for (auto neighbor : neighbors) {
				degrees[neighbor]++;
			}
		}
		return degrees;
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