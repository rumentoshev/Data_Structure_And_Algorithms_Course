#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include<queue>
using namespace std;

vector<bool> ans;
unordered_map<int, unordered_multiset<int>> Graph;
unordered_set<int> vertices;
unordered_map<int, int> separatedByGraphs;
unordered_map<int, bool> visited;
int N, M;

void fillTheGraph()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;

        if (vertices.find(from) == vertices.end())
        {
            vertices.insert(from);
        }
        if (vertices.find(to) == vertices.end())
        {
            vertices.insert(to);
        }
        Graph[from].insert(to);
        Graph[to].insert(from);
    }
}

void BFS(int num,int numOfGraphs)
{
    queue<int> verticesQ;
    verticesQ.push(num);
    visited[num] = true;
    separatedByGraphs[num] = numOfGraphs;

    while (!verticesQ.empty())
    {
        int temp = verticesQ.front();
        verticesQ.pop();

        for (int v : Graph[temp])
        {
            if (visited[v] == false)
            {
                visited[v] = true;
                separatedByGraphs[v] = numOfGraphs;
                verticesQ.push(v);
            }
        }
    }   
}

void group()
{
    int numOfGraphs = 1;
    for (int v : vertices)
    {
        if (visited[v] == false)
        {
            BFS(v, numOfGraphs);
            numOfGraphs++;
        }
    }
}
int main() {
    
    fillTheGraph();
    group();
    int K;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int start, finish;
        cin >> start >> finish;
        if (separatedByGraphs[start] == separatedByGraphs[finish])
        {
            ans.push_back(true);
        }
        else
        {
            ans.push_back(false);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}