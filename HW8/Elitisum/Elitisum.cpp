#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <iomanip>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    priority_queue<float> maxQ;
    priority_queue<float,vector<float>, greater<float>> minQ;

    vector<float> ans;
    float firstNum;
    cin >> firstNum;
    maxQ.push(firstNum);
    ans.push_back(firstNum);

    for (int i = 0; i < N - 1; i++)
    {
        float temp;
        cin >> temp;

        if ((maxQ.size() + minQ.size()) % 2 == 0)
        {
            if (temp > maxQ.top() && temp < minQ.top())
            {
                minQ.push(temp);
                ans.push_back(temp);
            }
            else if (temp >= minQ.top())
            {
                minQ.push(temp);
                ans.push_back(minQ.top());
            }
            else if (temp <= maxQ.top())
            {
                maxQ.push(temp);
                ans.push_back(maxQ.top());
            }
        }
        else if (maxQ.size() > minQ.size())
        {
            if (temp <= maxQ.top())
            {
                minQ.push(maxQ.top());
                maxQ.pop();
                maxQ.push(temp);
                ans.push_back((maxQ.top() + minQ.top()) / 2);
            }
            else if (!minQ.empty())
            {
                if (temp > maxQ.top() && temp < minQ.top())
                {
                    minQ.push(temp);
                    ans.push_back((maxQ.top() + minQ.top()) / 2);
                }
                else if (temp >= minQ.top() && !minQ.empty())
                {
                    minQ.push(temp);
                    ans.push_back((maxQ.top() + minQ.top()) / 2);
                }
            }
            else
            {
                minQ.push(temp);
                ans.push_back((maxQ.top() + minQ.top()) / 2);
            }
        }
        else if (maxQ.size() < minQ.size())
        {
            if (temp >= minQ.top())
            {
                maxQ.push(minQ.top());
                minQ.pop();
                minQ.push(temp);
                ans.push_back((maxQ.top() + minQ.top()) / 2);
            }
            else if (temp <= maxQ.top())
            {
                maxQ.push(temp);
                ans.push_back((maxQ.top() + minQ.top()) / 2);
            }
            else if (temp > maxQ.top() && temp < minQ.top())
            {
                maxQ.push(temp);
                ans.push_back((maxQ.top() + minQ.top()) / 2);
            }
        }

    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << fixed << setprecision(1) << ans[i] <<"\n";
    }
    return 0;
}