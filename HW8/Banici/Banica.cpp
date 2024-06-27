#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Item
{
    int timeToStart;
    int timeToProduce;
    int priority;

    Item(int first, int second, int third)
    {
        this->timeToStart = first;
        this->timeToProduce = second;
        this->priority = third;
    }
};

struct CompareByTimeToStart
{
    bool operator()(const Item& one, const Item& two)
    {
        return one.timeToStart >= two.timeToStart;
    }
};

struct CompareByTimeToProduce
{
    bool operator()(const Item& one, const Item& two)
    {
        if (one.timeToProduce == two.timeToProduce)
        {
            return one.priority > two.priority;
        }
        else
        {
            return one.timeToProduce > two.timeToProduce;
        }
    }
};

int main() {

    int N;
    cin >> N;

    priority_queue<Item, vector<Item>, CompareByTimeToStart> arrForTimeToStart;
    for (int i = 0; i < N; ++i)
    {
        int time_to_start, time_to_produce;
        cin >> time_to_start >> time_to_produce;
        arrForTimeToStart.push(Item(time_to_start, time_to_produce, i));
    }

    priority_queue<Item, vector<Item>, CompareByTimeToProduce> arrForTimeToProduce;

    int timer = arrForTimeToStart.top().timeToStart;

    arrForTimeToProduce.push(arrForTimeToStart.top());
    arrForTimeToStart.pop();

    while (!arrForTimeToProduce.empty())
    {
        cout << arrForTimeToProduce.top().priority << " ";
        timer += arrForTimeToProduce.top().timeToProduce;
        arrForTimeToProduce.pop();

        while (!arrForTimeToStart.empty() && arrForTimeToStart.top().timeToStart <= timer)
        {
            arrForTimeToProduce.push(arrForTimeToStart.top());
            arrForTimeToStart.pop();
        }

        if (arrForTimeToProduce.empty() && !arrForTimeToStart.empty())
        {
            timer += arrForTimeToStart.top().timeToProduce;
            arrForTimeToProduce.push(arrForTimeToStart.top());
            arrForTimeToStart.pop();
        }
    }

    return 0;
}