#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int N;
    cin >> N;
    vector<int> arr;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    int max_profit = 0;
    for (int i = 0; i < N-1; ++i)
    {
        if (arr[i] < arr[i + 1])
        {
            max_profit = max_profit + (arr[i + 1] - arr[i]);
        }
        else
        {
            continue;
        }
    }
    cout << max_profit;
    return 0;
}               

