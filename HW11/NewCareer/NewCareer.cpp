#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
#include<climits>
using namespace std;

int V, E, Q;
unordered_map<int, vector<pair<int, int>>> Graph;


void fillInfo()
{
    cin >> V >> E >> Q;
    for (int i = 0; i < E; ++i)
    {
        int A, B, w;
        cin >> A >> B >> w;
        Graph[A].push_back({ B,w });
    }
}
vector<vector<pair<int, int>>> distances(V,vector<pair<int,int>> (V,({INT_MAX,})));
void Dijkstra(int start)
{
    distances[start][start].first = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> QueueForDj;
    QueueForDj.push({ 0, start });

    while (!QueueForDj.empty())
    {
        int currentV = QueueForDj.top().second;
        int distanceToCurr = QueueForDj.top().first;


        QueueForDj.pop();

        for (auto Vpair : Graph[currentV])
        {
            int newDist = distanceToCurr + Vpair.second;

            if (newDist < distances[start][Vpair.first].first)
            {
                distances[start][Vpair.first].first = newDist;
                QueueForDj.push({ newDist,Vpair.first });
            }
        }
    }
}


int main()
{
    fillInfo();

    for (int i = 0; i < V; i++)
    {
        vector<pair<int, int>> temp;
        distances.push_back(temp);
    }

    vector<bool> SetOfQueue(V, false);
    vector<int> order;
    for (int i = 0; i < Q; i++)
    {
        int start, finish;
        cin >> start >> finish;
        if (SetOfQueue[start] == false)
        {
            SetOfQueue[start] = true;
            for (int j = 0; j < V; j++)
            {
                distances[start].push_back({ INT_MAX,j });
            }
            Dijkstra(start);
        }
        order.push_back(start);
        order.push_back(finish);
    }

    for (int i = 0; i < order.size(); i += 2)
    {
        if (distances[order[i]][order[i + 1]].first == INT_MAX)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << distances[order[i]][order[i + 1]].first << "\n";
        }
    }
    return 0;
}