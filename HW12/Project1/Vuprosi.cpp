#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

int N, M, Q;
vector<int> prevCity;

int findParent(int x)
{
    if (prevCity[x] == x)
    {
        return x;
    }
    prevCity[x] = findParent(prevCity[x]);
    prevCity[x] = prevCity[prevCity[x]];
    return prevCity[x];
}

void Union(int first,int second)
{
    int city1 = findParent(first);
    int city2 = findParent(second);

    if (city1 != city2)
    {
        prevCity[city2] = city1;
    }

}
int main() 
{
    //fill the information
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        prevCity.push_back(i);
    }
    for (int i = 0; i < M; i++)
    {
        int city1, city2;
        cin >> city1 >> city2;
        Union(city1 - 1,city2 - 1);
    }

    //Enter Q and answear
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int type, city1, city2;
        cin >> type >> city1 >> city2;
        if (type == 1)
        {
            int temp1 = findParent(city1 - 1);
            int temp2 = findParent(city2 - 1);
            bool ans = temp1 == temp2;
            cout << (int)ans;
        }
        else
        {
            Union(city1 - 1, city2 - 1);
        }
    }
    return 0;
}