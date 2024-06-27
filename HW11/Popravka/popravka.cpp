#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

int V, E, startPoint, finishPoint;
unordered_map<int, vector<pair<int, int>>> Graph;
unordered_map<int, int> Dist; //V,weight;
vector<vector<int>> parents;
vector <vector<int>> Paths;
vector<int> currPath;
int counter = 0;


void FillInformation()
{
	cin >> V >> E >> finishPoint >> startPoint;
	for (int i = 0; i < E; i++)
	{
		int start, finish, weight;
		cin >> start >> finish >> weight;
		Graph[start].push_back({ finish,weight });
		Graph[finish].push_back({ start,weight });
	}
}

void BFS()
{
	unordered_map<int, bool> visited;
	for (int i = 0; i < V; i++)
	{
		vector<int> temp;
		parents.push_back(temp);
	}

	Dist[startPoint] = 0;
	parents[startPoint].push_back(-1);

	queue<int> Queue;
	Queue.push(startPoint);

	while (!Queue.empty()) {
		int current = Queue.front();
		visited[current] = true;
		Queue.pop();

		for (int i = 0; i < Graph[current].size(); i++)
		{
			if (Dist[current] > Dist[current] + Graph[current][i].second)
			{
				continue;
			}
			else if (Dist[current] <= Dist[current] + Graph[current][i].second)
			{
				if (visited[Graph[current][i].first] == false)
				{
					visited[Graph[current][i].first] == true;
					Dist[Graph[current][i].first] = Dist[current] + Graph[current][i].second;
					Queue.push(Graph[current][i].first);
					parents[Graph[current][i].first].push_back(current);
				}
				
			}
		}
	}
}

void FindPaths(int start,vector<int> currPath)
{
	if (start == -1) {
		Paths.push_back(currPath);
		counter++;
		return;
	}

	for (auto parent : parents[start]) {
		currPath.push_back(start);
		FindPaths(parent,currPath);
		currPath.pop_back();
	}
}
int main() 
{
	FillInformation();
	BFS();
	vector<int> currPath;
	FindPaths(finishPoint, currPath);
	cout << counter;
	return 0;
}