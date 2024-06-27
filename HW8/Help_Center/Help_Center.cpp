#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {

    int sizeOfGroup, timeInterval, allGroups;
    cin >> sizeOfGroup >> timeInterval >> allGroups;
    priority_queue <int, vector<int>, greater<int>> arr;
    vector<int> ans;
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int temp;
        cin >> temp;
        arr.push(temp);
        if (i % timeInterval == 0 && allGroups != 0)
        {
            allGroups--;
            for (int j = 0; j < sizeOfGroup; j++)
            {
                ans.push_back(arr.top());
                arr.pop();
            }
        }
    }

    if (allGroups > 0)
    {
        while (allGroups != 0)
        {
            for (int j = 0; j < sizeOfGroup; j++)
            {
                ans.push_back(arr.top());
                arr.pop();
            }
            --allGroups;
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}