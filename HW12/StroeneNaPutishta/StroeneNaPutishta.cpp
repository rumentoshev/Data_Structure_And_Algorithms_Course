#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


struct Road
{
    int index;
    int fromCity;
    int toCity;
    long long int cost;
    long long int profit;

    Road(int id, int from, int to, long long int c, long long int p)
    {
        this->index = id;
        this->fromCity = from;
        this->toCity = to;
        this->cost = c;
        this->profit = p;
    }

    bool operator<(const Road& other)
    {
        if (this->cost == other.cost)
        {
            return this->profit >= other.profit;
        }

        return this->cost < other.cost;
    }
};
vector<Road> Map;
vector<int> Parent;
vector<int> Dist;

int findRoad(int city)
{
    if (Parent[city] == city)
    {
        return city;
    }
    Parent[city] = findRoad(Parent[city]);
    return Parent[city];
}

void BuildRoad(int from, int to)
{
    int prevFrom = findRoad(from);
    int prevTo = findRoad(to);

    if (prevFrom != prevTo)
    {
        if (Dist[prevFrom] < Dist[prevTo])
        {
            Parent[prevFrom] = prevTo;
            Dist[prevTo] += Dist[prevFrom];
        }
        else
        {
            Parent[prevTo] = prevFrom;
            Dist[prevFrom] += Dist[prevTo];
        }
    }
}
int main() 
{
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= M; i++)
    {
        int city1, city2;
        long long int cost, profit;
        cin>> city1 >> city2 >> cost >> profit;
        Map.push_back(Road(i, city1-1, city2-1, cost, profit));
    }
    for (int i = 0; i < N; i++)
    {
        Parent.push_back(i);
    }
    for (int i = 0; i < N; i++)
    {
        Dist.push_back(1);
    }

    sort(Map.begin(), Map.end());
    vector<int> ans;
    for (int i = 0; i < Map.size(); i++)
    {
        if (!(findRoad(Map[i].fromCity) == findRoad(Map[i].toCity)))
        {
            ans.push_back(Map[i].index);
            BuildRoad(Map[i].fromCity, Map[i].toCity);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
       cout << ans[i] << "\n";
    }
    
    return 0;
}


