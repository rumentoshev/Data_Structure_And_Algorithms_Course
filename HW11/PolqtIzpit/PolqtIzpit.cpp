#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

int V, E, start, finish;
unordered_map<int, vector<pair<int, int>>> Graph;
vector<int> timesForVertices;

void fillInfo()
{
    cin >> V >> E >> start >> finish;
    for (int i = 0; i < V; i++)
    {
        int temp;
        cin >> temp;
        timesForVertices.push_back(temp);
    }
    for (int i = 0; i < E; ++i)
    {
        int stP, flP, weight;
        cin >> stP >> flP >> weight;

        Graph[stP].push_back({ flP,weight });
    }
}

vector<int> distances;
void Dijkstra()
{
    for (int i = 0; i < V; i++)
    {
        distances.push_back(INT_MAX);
    }
    distances[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> QueueForDj;
    QueueForDj.push({ 0, start });

    while (!QueueForDj.empty())
    {
        int currentV = QueueForDj.top().second;
        int distanceToCurr = QueueForDj.top().first;

        int diffInTime = distanceToCurr % timesForVertices[currentV];
        if (diffInTime != 0)
        {
            distanceToCurr += (timesForVertices[currentV] - diffInTime);
        }

        QueueForDj.pop();

        for (auto Vpair : Graph[currentV])
        {
            int newDist = distanceToCurr + Vpair.second;
            
            if (newDist < distances[Vpair.first])
            {
                distances[Vpair.first] = newDist;
                QueueForDj.push({ newDist,Vpair.first });
            }
        }
    }
}
int main() 
{
    fillInfo();
    Dijkstra();
    if (distances[finish] == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << distances[finish];
    }
    return 0;
}
